#include "util.hpp"

#include <algorithm>

using namespace std;

int countCorrect(const vector<char>& key, const char* answers) {
    int correct = 0;

    for (size_t i = 0; i < key.size(); ++i) {
        if (key[i] == answers[i]) {
            ++correct;
        }
    }

    return correct;
}

void sortStudents(vector<Student>& students, const string& order) {
    sort(students.begin(), students.end(),
         [&order](const Student& a, const Student& b) {
             if (order == "STUDENT_ID_ASC") {
                 return a.id < b.id;
             }

             if (order == "STUDENT_ID_DESC") {
                 return a.id > b.id;
             }

             // Grade ties always use ascending student IDs.
             if (a.grade == b.grade) {
                 return a.id < b.id;
             }

             if (order == "GRADE_ASC") {
                 return a.grade < b.grade;
             }

             return a.grade > b.grade;
         });
}