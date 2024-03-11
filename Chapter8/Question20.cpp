#include <iostream>
using namespace std;
double computeAverageSpeed(double distance, double time) {
    if (time == 0) return 0;
    return distance / time;
}
int main() {
    const int MAX_RECORDS = 100; 
    double distances[MAX_RECORDS];
    double times[MAX_RECORDS];
    int numRecords = 0;
    cout << "Enter the number of records: ";
    cin >> numRecords;
    cout << "Enter distances and times:\n";
    for (int i = 0; i < numRecords; ++i) {
        cout << "Record " << i + 1 << " - Distance: ";
        cin >> distances[i];
        cout << "Record " << i + 1 << " - Time: ";
        cin >> times[i];
    }
    cout << "Average speed over successive time intervals:\n";
    for (int i = 0; i < numRecords - 1; ++i) {
        double intervalDistance = distances[i + 1] - distances[i];
        double intervalTime = times[i + 1] - times[i];
        double averageSpeed = computeAverageSpeed(intervalDistance, intervalTime);
        cout << "Interval " << i + 1 << ": " << averageSpeed << endl;
    }
    return 0;
}
