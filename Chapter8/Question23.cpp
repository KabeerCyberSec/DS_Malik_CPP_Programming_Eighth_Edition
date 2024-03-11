#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;
const int ROWS = 3;
const int COLS = 3;
const int HEIGHT = 3;

void fillArray(int array[ROWS][COLS][HEIGHT]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            for (int k = 0; k < HEIGHT; ++k) {
                array[i][j][k] = rand() % 9 + 1;
            }
        }
    }
}
bool isMagicSquare(int array[ROWS][COLS][HEIGHT]) {
    int magicNumber = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            for (int k = 0; k < HEIGHT; ++k) {
                magicNumber += array[i][j][k];
            }
        }
    }
    magicNumber /= 3;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int rowSum = 0, colSum = 0, diagSum1 = 0, diagSum2 = 0;
            for (int k = 0; k < HEIGHT; ++k) {
                rowSum += array[i][j][k];
                colSum += array[j][i][k];
                if (i == j)
                    diagSum1 += array[i][j][k];
                if (i + j == 2)
                    diagSum2 += array[i][j][k];
            }
            if (rowSum != magicNumber || colSum != magicNumber)
                return false;
            if (i == 0 && j == 0 && (diagSum1 != magicNumber || diagSum2 != magicNumber))
                return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    int array[ROWS][COLS][HEIGHT];
    int magicSquareCount = 0;
    int trials = 1000000;

    for (int t = 0; t < trials; ++t) {
        fillArray(array);
        if (isMagicSquare(array))
            magicSquareCount++;
    }
    cout << "Number of times the array is a magic square: " << magicSquareCount << endl;
    return 0;
}
