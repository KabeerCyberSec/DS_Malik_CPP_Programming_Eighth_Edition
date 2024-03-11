#include <iostream>
using namespace std;
int MONTHS = 12;


void getData(int temperatures[][2]) {
    cout << "Enter the highest and lowest temperatures for each month:\n";
    for (int i = 0; i < MONTHS; ++i) {
        cout << "Month " << i + 1 << ":\n";
        cout << "High: ";
        cin >> temperatures[i][0];
        cout << "Low: ";
        cin >> temperatures[i][1];
    }
}


double averageHigh(int temperatures[][2]) {
    int total = 0;
    for (int i = 0; i < MONTHS; ++i) {
        total += temperatures[i][0];
    }
    return static_cast<double>(total) / MONTHS;
}


double averageLow(int temperatures[][2]) {
    int total = 0;
    for (int i = 0; i < MONTHS; ++i) {
        total += temperatures[i][1];
    }
    return static_cast<double>(total) / MONTHS;
}


int indexHighTemp(int temperatures[][2]) {
    int maxIndex = 0;
    for (int i = 1; i < MONTHS; ++i) {
        if (temperatures[i][0] > temperatures[maxIndex][0]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}


int indexLowTemp(int temperatures[][2]) {
    int minIndex = 0;
    for (int i = 1; i < MONTHS; ++i) {
        if (temperatures[i][1] < temperatures[minIndex][1]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int temperatures[MONTHS][2];


    getData(temperatures);

    double avgHigh = averageHigh(temperatures);
    double avgLow = averageLow(temperatures);


    int maxIndex = indexHighTemp(temperatures);
    int minIndex = indexLowTemp(temperatures);


    cout << "Average High: " << avgHigh << endl;
    cout << "Average Low: " << avgLow << endl;
    cout << "Highest Temperature: " << temperatures[maxIndex][0] << " (Month " << maxIndex + 1 << ")" << endl;
    cout << "Lowest Temperature: " << temperatures[minIndex][1] << " (Month " << minIndex + 1 << ")" << endl;

    return 0;
}
