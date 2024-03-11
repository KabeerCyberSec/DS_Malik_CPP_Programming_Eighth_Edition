#include <iostream>
#include <cmath>
using namespace std;
int MAX_NUMBERS = 100;
double calculateMean(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += numbers[i];
    }
    return static_cast<double>(sum) / count;
}
double calculateStandardDeviation(int numbers[], int count, double mean) {
    double variance = 0;
    for (int i = 0; i < count; ++i) {
        variance += pow(numbers[i] - mean, 2);
    }
    return sqrt(variance / count);
}
int main(){

    int numbers[MAX_NUMBERS];
    int count;
    cout << "Enter the count of numbers (up to " << MAX_NUMBERS << "): ";
    cin >> count;
    if (count > 0 && count <= MAX_NUMBERS) {
        cout << "Enter " << count << " numbers:\n";
        for (int i = 0; i < count; ++i) {
            cout << "Number " << i + 1 << ": ";
            cin >> numbers[i];
        }
        double mean = calculateMean(numbers, count);
        double standardDeviation = calculateStandardDeviation(numbers, count, mean);
        cout << "Mean (average): " << mean << endl;
        cout << "Standard Deviation: " << standardDeviation << endl;
    } else {
        cout << "Invalid count of numbers. Please enter a count between 1 and " << MAX_NUMBERS << "." << endl;
    }
    return 0;
}
