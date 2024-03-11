#include <iostream>
using namespace std;
void inputArray(int alpha[]) {
    cout << "Enter 20 numbers:\n";
    for (int i = 0; i < 20; ++i) {
        cin >> alpha[i];
    }
}
void doubleArray(const int alpha[], int beta[]) {
    for (int i = 0; i < 20; ++i) {
        beta[i] = 2 * alpha[i];
    }
}
void copyAlphaBeta(const int alpha[], const int beta[], int matrix[][4]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = alpha[i * 4 + j];
        }
    }
    for (int i = 5; i < 10; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = beta[(i - 5) * 4 + j];
        }
    }
}
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
        if ((i + 1) % 15 == 0)
            cout << endl;
    }
    cout << endl;
}

int main() {
    int alpha[20];
    int beta[20];
    int matrix[10][4];
    inputArray(alpha);
    doubleArray(alpha, beta);
    copyAlphaBeta(alpha, beta, matrix);
    cout << "Printing alpha:\n";
    printArray(alpha, 20);
    cout << "Printing beta:\n";
    printArray(beta, 20);
    cout << "Printing matrix:\n";
    for (int i = 0; i < 10; ++i) {
        printArray(matrix[i], 4);
    }
    return 0;
}
