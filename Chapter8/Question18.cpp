#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;
const int ROWS = 4;
const int COLS = 4;
const int NUM_PAIRS = 8;
void initializeDeck(int deck[][COLS]) {
    int numPairs = 0;
    for (int num = 1; num <= NUM_PAIRS; ++num) {
        for (int i = 0; i < 2; ++i) {
            int row, col;
            do {
                row = rand() % ROWS;
                col = rand() % COLS;
            } while (deck[row][col] != 0); 
            deck[row][col] = num;
            numPairs++;
        }
    }
}
void printDeck(const int deck[][COLS], bool reveal) {
    cout << "  1 2 3 4" << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; ++j) {
            if (reveal || deck[i][j] > 0) {
                cout << deck[i][j] << " ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}
bool allCardsRevealed(const int deck[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (deck[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
void playMemoryGame() {
    int deck[ROWS][COLS] = {0};
    initializeDeck(deck);
    int turns = 0;
    while (!allCardsRevealed(deck)) {
        printDeck(deck, false);
        int r1, c1, r2, c2;
        cout << "Enter the row and column numbers of two cards (separated by space): ";
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 < 1 || r1 > ROWS || c1 < 1 || c1 > COLS || r2 < 1 || r2 > ROWS || c2 < 1 || c2 > COLS) {
            cout << "Invalid input. Row and column numbers must be between 1 and " << ROWS << "." << endl;
            continue;
        }
        if (deck[r1 - 1][c1 - 1] == deck[r2 - 1][c2 - 1]) {
            cout << "Match!" << endl;
            deck[r1 - 1][c1 - 1] = 0;
            deck[r2 - 1][c2 - 1] = 0;
        } else {
            cout << "No match. Try again." << endl;
        }
        turns++;
    }
    cout << "Congratulations! You completed the game in " << turns << " turns." << endl;
    printDeck(deck, true);
}
int main() {
    srand(time(NULL));
    playMemoryGame();
    return 0;
}