#include <iostream>
#include<ctime>//for time
using namespace std;
int LOTTERY_SIZE = 5;
void generateLotteryNumbers(int lottery[]) {
    srand(time(NULL));
    for (int i = 0; i < LOTTERY_SIZE; ++i) {
        int num;
        do {
            num = rand() % 9 + 1;
        } while (lottery[i] == num);
        lottery[i] = num;
    }
}
bool containsDuplicates(int userNumbers[]) {
    for (int i = 0; i < LOTTERY_SIZE - 1; ++i) {
        for (int j = i + 1; j < LOTTERY_SIZE; ++j) {
            if (userNumbers[i] == userNumbers[j]) {
                return true;
            }
        }
    }
    return false;
}
void compareNumbers(int lottery[], int userNumbers[]) {
    int matchingDigits = 0;
    for (int i = 0; i < LOTTERY_SIZE; ++i) {
        if (lottery[i] == userNumbers[i]) {
            ++matchingDigits;
        }
    }

    if (matchingDigits == LOTTERY_SIZE) {
        cout << "Congratulations! You won the game!" << endl;
    } else {
        cout << "You didn't win. You matched " << matchingDigits << " digits." << endl;
    }
}

int main() {
    int lottery[LOTTERY_SIZE];
    int userNumbers[LOTTERY_SIZE];
    generateLotteryNumbers(lottery);
    cout << "Enter five distinct numbers between 1 and 9:" << endl;
    for (int i = 0; i < LOTTERY_SIZE; ++i) {
        cin >> userNumbers[i];
    }

    if (containsDuplicates(userNumbers)) {
        cout << "Error: Input contains duplicate numbers." << endl;
        return 1;
    }

    compareNumbers(lottery, userNumbers);

    return 0;
}
