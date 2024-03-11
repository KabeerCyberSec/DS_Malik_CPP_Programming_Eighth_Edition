#include <iostream>
#include <string>
using namespace std;
const int NUM_STUDENTS = 10;
const int NUM_TESTS = 5;

void readData(string names[], int scores[][NUM_TESTS]) {
    cout << "Enter student names and their test scores:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cin >> names[i];
        for (int j = 0; j < NUM_TESTS; ++j) {
            cin >> scores[i][j];
        }
    }
}

void calculateGrades(const int scores[][NUM_TESTS], char grades[], double averages[]) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int total = 0;
        for (int j = 0; j < NUM_TESTS; ++j) {
            total += scores[i][j];
        }
        averages[i] = static_cast<double>(total) / NUM_TESTS;

        if (averages[i] >= 90) {
            grades[i] = 'A';
        } else if (averages[i] >= 80) {
            grades[i] = 'B';
        } else if (averages[i] >= 70) {
            grades[i] = 'C';
        } else if (averages[i] >= 60) {
            grades[i] = 'D';
        } else {
            grades[i] = 'F';
        }
    }
}

void outputResults(const string names[], const char grades[], const double averages[]) {
    double classAverage = 0;
    cout << "Student\t\tAverage\tGrade\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << names[i] << "\t\t" << averages[i] << "\t" << grades[i] << endl;
        classAverage += averages[i];
    }
    classAverage /= NUM_STUDENTS;
    cout << "Class Average: " << classAverage << endl;
}

int main() {
    string names[NUM_STUDENTS];
    int scores[NUM_STUDENTS][NUM_TESTS];
    char grades[NUM_STUDENTS];
    double averages[NUM_STUDENTS];

    readData(names, scores);
    calculateGrades(scores, grades, averages);
    outputResults(names, grades, averages);

    return 0;
}
