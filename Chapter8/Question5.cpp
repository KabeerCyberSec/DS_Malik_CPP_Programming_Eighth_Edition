#include <iostream>
#include <cctype>
using namespace std;

int main() {
    const int MAX_LEN = 100;
    char str[MAX_LEN];

    cout << "Enter a string: ";
    cin.getline(str, MAX_LEN);

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    cout << "Uppercase string: " << str << endl;

    return 0;
}