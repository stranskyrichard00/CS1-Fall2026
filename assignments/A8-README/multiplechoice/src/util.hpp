#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    int grade;
};


int countCorrect(const vector<char>& key, const char* answers);

void sortStudents(vector<Student>& students, const string& order);

#endif