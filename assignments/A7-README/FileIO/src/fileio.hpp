#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <string>
#include <vector>
#include <ostream>

using namespace std;

struct Student {
    string first, last;
    double tests[4];
    double total = 0;
    double average = 0;
    char grade = 'F';
};

char letterGrade(double average);
void calculate(Student& student);
bool readFile(string filename, vector<Student>& students);
void sortStudents(vector<Student>& students);
void showStatistics(ostream& out, vector<double> values);
void report(ostream& out, vector<Student> students);

#endif