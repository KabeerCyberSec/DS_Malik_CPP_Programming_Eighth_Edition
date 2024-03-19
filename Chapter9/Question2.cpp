#include <iostream>
#include <string>
using namespace std;
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readStudentData(studentType students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter student " << i+1 << "'s first name: ";
        cin >> students[i].studentFName;

        cout << "Enter student " << i+1 << "'s last name: ";
        cin >> students[i].studentLName;

        cout << "Enter student " << i+1 << "'s test score: ";
        cin >> students[i].testScore;
    }
}

void assignGrades(studentType students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].testScore >= 90)
            students[i].grade = 'A';
        else if (students[i].testScore >= 80)
            students[i].grade = 'B';
        else if (students[i].testScore >= 70)
            students[i].grade = 'C';
        else if (students[i].testScore >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

int findHighestScore(studentType students[], int numStudents) {
    int highestScore = students[0].testScore;
    for (int i = 1; i < numStudents; ++i) {
        if (students[i].testScore > highestScore)
            highestScore = students[i].testScore;
    }
    return highestScore;
}

void printStudentsWithHighestScore(studentType students[], int numStudents, int highestScore) {
    cout << "Students with the highest test score (" << highestScore << "):\n";
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].testScore == highestScore)
            cout << students[i].studentLName << ", " << students[i].studentFName << endl;
    }
}

void outputStudentInfo(studentType students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        cout << students[i].studentLName << ", " << students[i].studentFName << ": ";
        cout << "Test Score: " << students[i].testScore << ", Grade: " << students[i].grade << endl;
    }
}

int main() {
    const int numStudents = 20;
    studentType students[numStudents];
    readStudentData(students, numStudents);
    assignGrades(students, numStudents);
    outputStudentInfo(students, numStudents);
    int highestScore = findHighestScore(students, numStudents);
    printStudentsWithHighestScore(students, numStudents, highestScore);

    return 0;
}
