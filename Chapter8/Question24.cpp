#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;
const int ROWS = 20;
const int HEIGHT = 3;
const int COLS = 20;

bool isPeak(int board[ROWS][HEIGHT][COLS], int row, int height, int col) {
    int neighbors[] = {-1, 0, 1};
    int countLess = 0, countGreater = 0;
    for (int i : neighbors) {
        for (int j : neighbors) {
            for (int k : neighbors) {
                int newRow = row + i;
                int newHeight = height + j;
                int newCol = col + k;
                if (newRow >= 0 && newRow < ROWS && newHeight >= 0 && newHeight < HEIGHT && newCol >= 0 && newCol < COLS) {
                    if (board[newRow][newHeight][newCol] < board[row][height][col]) {
                        countLess++;
                    } else if (board[newRow][newHeight][newCol] > board[row][height][col]) {
                        countGreater++;
                    }
                }
            }
        }
    }
    return (countLess == 26 || countGreater == 26);
}

int main() {
    srand(time(NULL));

    int board[ROWS][HEIGHT][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            for (int k = 0; k < COLS; ++k) {
                board[i][j][k] = rand() % 1000;
            }
        }
    }
    cout << "Peaks in the board:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            for (int k = 0; k < COLS; ++k) {
                if (isPeak(board, i, j, k)) {
                    cout << "Peak at (" << i << ", " << j << ", " << k << ") - ";
                    if (board[i][j][k] > board[i-1][j][k] && board[i][j][k] > board[i+1][j][k] && board[i][j][k] > board[i][j-1][k] && board[i][j][k] > board[i][j+1][k] && board[i][j][k] > board[i][j][k-1] && board[i][j][k] > board[i][j][k+1]){
                      cout << "Maximum\n";
                    } else if (board[i][j][k] < board[i-1][j][k] && board[i][j][k] < board[i+1][j][k] && board[i][j][k] < board[i][j-1][k] && board[i][j][k] < board[i][j+1][k] && board[i][j][k] < board[i][j][k-1] && board[i][j][k] < board[i][j][k+1]){
                      cout << "Minimum\n";
                    }
                }
            }
        }
    }

    return 0;
}
