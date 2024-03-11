#include <iostream>
using namespace std;
const int ARRAY_SIZE = 50;
void enterIntegers(int arr[]) {
    cout << "Enter 50 integers:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cin >> arr[i];
    }
}
bool isSumOfTwo(int num, const int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        for (int j = i + 1; j < ARRAY_SIZE; ++j) {
            if (arr[i] + arr[j] == num) {
                return true;
            }
        }
    }
    return false;
}
void outputPairs(int num, const int arr[]) {
    cout << "Pairs where " << num << " is the sum of two other array elements:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        for (int j = i + 1; j < ARRAY_SIZE; ++j) {
            if (arr[i] + arr[j] == num) {
                cout << arr[i] << " + " << arr[j] << endl;
            }
        }
    }
}
int main() {
    int arr[ARRAY_SIZE];
    enterIntegers(arr);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (isSumOfTwo(arr[i], arr)) {
            outputPairs(arr[i], arr);
        }
    }
    return 0;
}
