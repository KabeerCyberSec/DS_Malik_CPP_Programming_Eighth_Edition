#include <iostream>
using namespace std;

int smallestIndex(int arr[], int size) {
    int minIndex = 0;
    int minVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int minIndex = smallestIndex(arr, size);
    cout << "Index of smallest element: " << minIndex << endl;

    return 0;
}