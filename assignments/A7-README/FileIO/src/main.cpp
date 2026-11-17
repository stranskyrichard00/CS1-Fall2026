#include "fileio.hpp"

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

// Algorithm:
// 1. Read student records from a file.
// 2. Calculate totals, averages, and letter grades.
// 3. Display, sort, or save the report.
// 4. Repeat until the user exits.
int main() {
    vector<Student> students;
    int choice;
    string filename;

    do {
        cout << "\n1. Read file\n"
             << "2. Display report and statistics\n"
             << "3. Sort students\n"
             << "4. Save report\n"
             << "5. Clear data\n"
             << "0. Exit\n"
             << "Choice: ";

        if (!(cin >> choice)) break;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            cout << "Input filename: ";
            getline(cin, filename);

            if (readFile(filename, students))
                cout << "Loaded " << students.size() << " students.\n";
            else
                cout << "Could not read valid student data.\n";
        } else if (choice == 5) {
            students.clear();
            cout << "Data cleared.\n";
        } else if (choice >= 2 && choice <= 4) {
            if (students.empty()) {
                cout << "Read a file first.\n";
                continue;
            }

            if (choice == 2) {
                report(cout, students);
            } else if (choice == 3) {
                sortStudents(students);
                cout << "Sorted from highest average to lowest:\n";

                for (const Student& student : students) {
                    cout << student.first << ' ' << student.last
                         << ": " << student.average << '\n';
                }
            } else {
                cout << "Output filename: ";
                getline(cin, filename);
                ofstream output(filename);

                if (output) {
                    report(output, students);
                    output.close();
                    cout << (output.fail() ? "Write failed.\n"
                                          : "Report saved.\n");
                } else {
                    cout << "Could not open output file.\n";
                }
            }
        } else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}