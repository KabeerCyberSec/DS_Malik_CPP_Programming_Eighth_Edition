#include <iostream>
using namespace std;
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}
int findPrimeFactor(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0 && isPrime(i))
            return i;
    }
    return -1;
}
int main() {
    for (int num = 2; num <= 100'000'000; ++num) {
        if (!isPrime(num)) {
            int factor = findPrimeFactor(num);
            cout << num << " = " << factor << " * " << num / factor << endl;
        }
    }
    return 0;
}
