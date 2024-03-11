#include <iostream>
using namespace std;

int lastLargestIndex(int arr[], int size) {
    int maxIndex = 0;
    int maxVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] >= maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main() {
    int arr[] = {5, 8, 2, 8, 1, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxIndex = lastLargestIndex(arr, size);
    cout << "Index of last largest element: " << maxIndex << endl;

    return 0;
}