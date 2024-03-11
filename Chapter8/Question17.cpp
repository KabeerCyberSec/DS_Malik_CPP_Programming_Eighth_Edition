#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int NUM_EMPLOYEES = 10;
const int DATA_COLUMNS = 3;
void readData(string names[], int hours[][DATA_COLUMNS]) {
    ifstream inputFile("employee_data.txt");
    if (!inputFile) {
        cerr << "Failed to open the file.\n";
        exit(1);
    }

    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        inputFile >> names[i];
        for (int j = 0; j < DATA_COLUMNS; ++j) {
            inputFile >> hours[i][j];
        }
    }
    inputFile.close();
}
void calculateWeeklyPay(int hours[][DATA_COLUMNS], double weeklyPay[]) {
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        int regularHours = hours[i][0] > 40 ? 40 : hours[i][0];
        int overtimeHours = hours[i][0] > 40 ? hours[i][0] - 40 : 0;
        double regularPay = regularHours * hours[i][1];
        double overtimePay = overtimeHours * hours[i][1] * 1.5;
        weeklyPay[i] = regularPay + overtimePay;
    }
}
double computeAveragePay(const double weeklyPay[]) {
    double totalPay = 0;
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        totalPay += weeklyPay[i];
    }
    return totalPay / NUM_EMPLOYEES;
}
void outputAboveAverage(const string names[], const double weeklyPay[], double averagePay) {
    cout << "Employees with pay greater than or equal to the average weekly pay:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        if (weeklyPay[i] >= averagePay) {
            cout << names[i] << endl;
        }
    }
}
void outputEmployeeData(const string names[], const int hours[][DATA_COLUMNS], const double weeklyPay[]) {
    cout << "Employee data:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "Name: " << names[i] << ", Hours worked: " << hours[i][0] << ", Hourly pay rate: $" << hours[i][1]
                  << ", Weekly pay: $" << weeklyPay[i] << endl;
    }
}

int main() {
    string names[NUM_EMPLOYEES];
    int hours[NUM_EMPLOYEES][DATA_COLUMNS];
    double weeklyPay[NUM_EMPLOYEES];
    readData(names, hours);
    calculateWeeklyPay(hours, weeklyPay);
    double averagePay = computeAveragePay(weeklyPay);
    outputAboveAverage(names, weeklyPay, averagePay);
    outputEmployeeData(names, hours, weeklyPay);

    return 0;
}