#include "util.hpp"

#include <iostream>

using namespace std;


int main() {
    int questions;
    cin >> questions;

    vector<char> key(questions);

    for (char& answer : key) {
        cin >> answer;
    }

    int studentCount;
    cin >> studentCount;

    vector<Student> students;

    for (int i = 0; i < studentCount; ++i) {
        int id;
        cin >> id;

        vector<char> answers(questions);

        for (char& answer : answers) {
            cin >> answer;
        }

        // Pointer to the vector's existing storage.
        const char* answerPointer = answers.data();

        int grade = countCorrect(key, answerPointer);
        students.push_back({id, grade});
    }

    string order;
    cin >> order;

    sortStudents(students, order);

    for (const Student& student : students) {
        cout << student.id << ' ' << student.grade << '\n';
    }

    return 0;
}