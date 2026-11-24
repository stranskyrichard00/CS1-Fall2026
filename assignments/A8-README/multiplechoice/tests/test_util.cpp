#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/util.hpp"

using namespace std;

TEST_CASE("Count correct answers") {
    vector<char> key{'A', 'C', 'D', 'C', 'B'};

    SUBCASE("All correct") {
        vector<char> answers{'A', 'C', 'D', 'C', 'B'};
        CHECK(countCorrect(key, answers.data()) == 5);
    }

    SUBCASE("Some correct") {
        vector<char> answers{'A', 'C', 'C', 'B', 'D'};
        CHECK(countCorrect(key, answers.data()) == 2);
    }

    SUBCASE("None correct") {
        vector<char> answers{'B', 'A', 'A', 'A', 'A'};
        CHECK(countCorrect(key, answers.data()) == 0);
    }
}

TEST_CASE("Sort by student ID ascending") {
    vector<Student> students{{30, 1}, {10, 3}, {20, 2}};

    sortStudents(students, "STUDENT_ID_ASC");

    CHECK(students[0].id == 10);
    CHECK(students[1].id == 20);
    CHECK(students[2].id == 30);
}

TEST_CASE("Sort by student ID descending") {
    vector<Student> students{{30, 1}, {10, 3}, {20, 2}};

    sortStudents(students, "STUDENT_ID_DESC");

    CHECK(students[0].id == 30);
    CHECK(students[1].id == 20);
    CHECK(students[2].id == 10);
}

TEST_CASE("Sort by grade ascending with ID tie-breaker") {
    vector<Student> students{{30, 2}, {10, 2}, {20, 1}};

    sortStudents(students, "GRADE_ASC");

    CHECK(students[0].id == 20);
    CHECK(students[1].id == 10);
    CHECK(students[2].id == 30);
}

TEST_CASE("Sort by grade descending with ID tie-breaker") {
    vector<Student> students{{30, 2}, {10, 2}, {20, 1}};

    sortStudents(students, "GRADE_DESC");

    CHECK(students[0].id == 10);
    CHECK(students[1].id == 30);
    CHECK(students[2].id == 20);
}

TEST_CASE("One student") {
    vector<Student> students{{1234, 1}};

    sortStudents(students, "GRADE_DESC");

    REQUIRE(students.size() == 1);
    CHECK(students[0].id == 1234);
}