#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;
void readData(string runners[], int miles[][NUM_DAYS]) {
    ifstream inputFile("data.txt"); 
    if (!inputFile) {
        cerr << "Failed to open the file.\n";
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inputFile >> runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            inputFile >> miles[i][j];
        }
    }
    inputFile.close();
}

void calculateTotals(const string runners[], const int miles[][NUM_DAYS], int totalMiles[], double averageMiles[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        totalMiles[i] = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles[i] += miles[i][j];
        }
        averageMiles[i] = static_cast<double>(totalMiles[i]) / NUM_DAYS;
    }
}

void outputResults(const string runners[], const int miles[][NUM_DAYS], const int totalMiles[], const double averageMiles[]) {
    cout << "Runner\t\tTotal Miles\tAverage Miles/Day\n";
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << runners[i] << "\t\t" << totalMiles[i] << "\t\t" << averageMiles[i] << endl;
    }
}

int main() {
    string runners[NUM_RUNNERS];
    int miles[NUM_RUNNERS][NUM_DAYS];
    int totalMiles[NUM_RUNNERS];
    double averageMiles[NUM_RUNNERS];

    readData(runners, miles);
    calculateTotals(runners, miles, totalMiles, averageMiles);
    outputResults(runners, miles, totalMiles, averageMiles);

    return 0;
}
