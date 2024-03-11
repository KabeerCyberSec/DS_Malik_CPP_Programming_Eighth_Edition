#include <iostream>
using namespace std;
const int ARRAY_SIZE = 50;
void enterIntegers(int arr[]) {
    cout << "Enter 50 integers:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cin >> arr[i];
    }
}
void selectionSort(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < ARRAY_SIZE; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

bool isSumOfTwo(int num, const int arr[]) {
    int left = 0, right = ARRAY_SIZE - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == num) {
            return true;
        } else if (sum < num) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

void outputPairs(int num, const int arr[]) {
    cout << "Pairs where " << num << " is the sum of two other array elements:\n";
    int left = 0, right = ARRAY_SIZE - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == num) {
            cout << arr[left] << " + " << arr[right] << endl;
            left++;
            right--;
        } else if (sum < num) {
            left++;
        } else {
            right--;
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    enterIntegers(arr);
    selectionSort(arr);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (isSumOfTwo(arr[i], arr)) {
            outputPairs(arr[i], arr);
        }
    }

    return 0;
}
