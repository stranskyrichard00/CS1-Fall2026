#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/fileio.hpp"

#include <sstream>

using namespace std;

TEST_CASE("Letter grades") {
    CHECK(letterGrade(90) == 'A');
    CHECK(letterGrade(80) == 'B');
    CHECK(letterGrade(70) == 'C');
    CHECK(letterGrade(60) == 'D');
    CHECK(letterGrade(59) == 'F');
}

TEST_CASE("Student calculations") {
    Student student{"John", "Smith", {100, 90, 80, 90}};
    calculate(student);

    CHECK(student.total == 360);
    CHECK(student.average == 90);
    CHECK(student.grade == 'A');
}

TEST_CASE("Sort students") {
    vector<Student> students{
        {"Low", "Score", {60, 60, 60, 60}},
        {"High", "Score", {90, 90, 90, 90}}
    };

    for (Student& student : students) calculate(student);

    sortStudents(students);

    CHECK(students[0].first == "High");
}

TEST_CASE("Read input file") {
    vector<Student> students;

    REQUIRE(readFile("data/students.txt", students));
    CHECK(students.size() == 6);
    CHECK(students[0].average == 93);
}

TEST_CASE("Statistics include even and odd medians") {
    ostringstream evenOutput;
    showStatistics(evenOutput, {40, 10, 20, 30});

    istringstream evenInput(evenOutput.str());
    double average, maximum, minimum, median;
    evenInput >> average >> maximum >> minimum >> median;

    CHECK(average == 25);
    CHECK(maximum == 40);
    CHECK(minimum == 10);
    CHECK(median == 25);

    ostringstream oddOutput;
    showStatistics(oddOutput, {30, 10, 20});

    istringstream oddInput(oddOutput.str());
    oddInput >> average >> maximum >> minimum >> median;

    CHECK(median == 20);
}

TEST_CASE("Report contains correct grade percentages") {
    vector<Student> students{
        {"Ann", "Smith", {90, 90, 90, 90}},
        {"Bob", "Jones", {80, 80, 80, 80}}
    };

    ostringstream output;
    report(output, students);

    CHECK(output.str().find("A% = 50.0%") != string::npos);
    CHECK(output.str().find("B% = 50.0%") != string::npos);
    CHECK(output.str().find("F% = 0.0%") != string::npos);
}