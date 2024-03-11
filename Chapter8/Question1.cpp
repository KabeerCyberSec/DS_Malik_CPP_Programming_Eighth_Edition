#include <iostream>
using namespace std;
int main() {
    const int SIZE = 50;
    double alpha[SIZE];


    for (int i = 0; i < 25; i++) {
        alpha[i] = i * i;
    }


    for (int i = 25; i < SIZE; i++) {
        alpha[i] = 3 * i;
    }


    for (int i = 0; i < SIZE; i++) {
        cout << alpha[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}