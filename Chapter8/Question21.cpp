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
    const int MAX_PRIMES = 1230;
    int primes[MAX_PRIMES];
    int primeCount = 0;
    for (int num = 2; primeCount < MAX_PRIMES; ++num) {
        if (isPrime(num)) {
            primes[primeCount++] = num;
        }
    }
    for (int num = 2; num <= 100'000'000; ++num) {
        if (isPrime(num)) {
            cout << num << " is prime.\n";
        } else {
            int factor = findPrimeFactor(num);
            cout << num << " is not prime. One of its prime factors is " << factor << ".\n";
        }
    }

    return 0;
}
