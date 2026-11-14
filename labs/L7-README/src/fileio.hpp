#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>
#include <vector>

using namespace std;

bool readNumbers(const string& filename, vector<int>& numbers);
int findMaximum(const vector<int>& numbers);
int findMinimum(const vector<int>& numbers);
long long calculateSum(const vector<int>& numbers);
double calculateAverage(const vector<int>& numbers);
bool writeResults(const string& filename, const vector<int>& numbers);
void deleteData(vector<int>& numbers);

#endif