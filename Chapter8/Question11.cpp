#include <iostream>
#include <string>
using namespace std;
int MAX_DIGITS = 20;


void readNumber(string& numberString, int number[]) {
    cout << "Enter a positive integer of at most " << MAX_DIGITS << " digits: ";
    cin >> numberString;


    int len = numberString.length();
    for (int i = 0; i < len; ++i) {
        number[len - i - 1] = numberString[i] - '0'; 
    }
}

void addNumbers(int num1[], int num2[], int sum[]) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        sum[i] = num1[i] + num2[i] + carry;
        carry = sum[i] / 10; 
        sum[i] %= 10; 
    }
}

void outputSum(int sum[]) {
    cout << "Sum of the numbers: ";
    bool leadingZero = true; 
    for (int i = MAX_DIGITS - 1; i >= 0; --i) {
        if (sum[i] != 0 || !leadingZero) {
            cout << sum[i];
            leadingZero = false;
        }
    }
    cout << endl;
}

int main() {
    string numberString1, numberString2;
    int num1[MAX_DIGITS] = {0};
    int num2[MAX_DIGITS] = {0};
    int sum[MAX_DIGITS] = {0};
    readNumber(numberString1, num1);
    readNumber(numberString2, num2);
    addNumbers(num1, num2, sum);
    outputSum(sum);
    return 0;
}
