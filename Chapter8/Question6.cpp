#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream infile("test_data.txt");
    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    const int NUM_QUESTIONS = 20;
    char answers[NUM_QUESTIONS + 1];
    infile.getline(answers, NUM_QUESTIONS + 1);

    char studentId[10];
    char studentAnswers[NUM_QUESTIONS + 1];
    int score;
    char grade;

    while (infile >> studentId >> studentAnswers) {
        score = 0;
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (studentAnswers[i] == answers[i]) {
                score += 2;
            } else if (studentAnswers[i] != ' ') {
                score -= 1;
            }
        }

        double percentage = static_cast<double>(score) / (NUM_QUESTIONS * 2) * 100;
        if (percentage >= 90) {
            grade = 'A';
        } else if (percentage >= 80) {
            grade = 'B';
        } else if (percentage >= 70) {
            grade = 'C';
        } else if (percentage >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        cout << "Student ID: " << studentId << endl;
        cout << "Answers: " << studentAnswers << endl;
        cout << "Score: " << score << endl;
        cout << "Grade: " << grade << endl;
        cout << endl;
    }

    infile.close();
    return 0;
} 