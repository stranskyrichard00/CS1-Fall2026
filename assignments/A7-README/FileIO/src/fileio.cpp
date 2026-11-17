#include "fileio.hpp"

#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

char letterGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

void calculate(Student& student) {
    student.total = 0;

    for (double score : student.tests) {
        student.total += score;
    }

    student.average = student.total / 4;
    student.grade = letterGrade(student.average);
}

bool readFile(string filename, vector<Student>& students) {
    ifstream input(filename);

    if (!input) return false;

    vector<Student> loaded;
    Student student;

    while (input >> student.first) {
        if (!(input >> student.last)) return false;

        for (double& score : student.tests) {
            if (!(input >> score) || !(score >= 0 && score <= 100)) {
                return false;
            }
        }

        if (loaded.size() == 50) return false;

        calculate(student);
        loaded.push_back(student);
    }

    if (!input.eof() || loaded.empty()) return false;

    students = loaded;
    return true;
}

void sortStudents(vector<Student>& students) {
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) {
             return a.average > b.average;
         });
}

void showStatistics(ostream& out, vector<double> values) {
    if (values.empty()) return;

    sort(values.begin(), values.end());

    double sum = 0;

    for (double value : values) {
        sum += value;
    }

    int middle = static_cast<int>(values.size()) / 2;
    double median = values[middle];

    if (values.size() % 2 == 0) {
        median = (values[middle - 1] + values[middle]) / 2;
    }

    out << setw(10) << sum / values.size()
        << setw(10) << values.back()
        << setw(10) << values.front()
        << setw(10) << median << '\n';
}

void report(ostream& out, vector<Student> students) {
    if (students.empty()) return;

    for (Student& student : students) {
        calculate(student);
    }

    sortStudents(students);
    out << fixed << setprecision(1);

    out << "CSCI 111 Grade Report\n\n";
    out << left << setw(14) << "First"
        << setw(14) << "Last" << right
        << setw(8) << "Test1" << setw(8) << "Test2"
        << setw(8) << "Test3" << setw(8) << "Test4"
        << setw(8) << "Total" << setw(8) << "Average"
        << setw(8) << "Grade" << '\n';

    for (const Student& student : students) {
        out << left << setw(14) << student.first
            << setw(14) << student.last << right;

        for (double score : student.tests) {
            out << setw(8) << score;
        }

        out << setw(8) << student.total
            << setw(8) << student.average
            << setw(8) << student.grade << '\n';
    }

    out << "\n" << left << setw(14) << "Statistics" << right
        << setw(10) << "Average" << setw(10) << "Maximum"
        << setw(10) << "Minimum" << setw(10) << "Median" << '\n';

    string labels[] = {"Test1", "Test2", "Test3", "Test4", "Total", "Final"};

    for (int column = 0; column < 6; ++column) {
        vector<double> values;

        for (const Student& student : students) {
            if (column < 4) values.push_back(student.tests[column]);
            else if (column == 4) values.push_back(student.total);
            else values.push_back(student.average);
        }

        out << left << setw(14) << labels[column] << right;
        showStatistics(out, values);
    }

    out << '\n';

    for (char grade : string("ABCDF")) {
        int count = 0;

        for (const Student& student : students) {
            if (student.grade == grade) ++count;
        }

        out << grade << "% = "
            << 100.0 * count / students.size() << "%\n";
    }
}