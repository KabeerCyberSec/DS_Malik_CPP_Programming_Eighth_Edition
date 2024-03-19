#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct LetterCount {
    char letter;
    int capitalCount;
    int smallCount;
};
void openFile(ifstream& inFile, ofstream& outFile);
void countLetters(ifstream& inFile, LetterCount counts[]);
void printResult(LetterCount counts[]);

int main() {
    ifstream inFile;
    ofstream outFile;
    LetterCount counts[26];

    openFile(inFile, outFile);
    countLetters(inFile, counts);
    printResult(counts);

    inFile.close();
    outFile.close();

    return 0;
}
void openFile(ifstream& inFile, ofstream& outFile) {
    string inputFileName, outputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    inFile.open(inputFileName);
    if (!inFile) {
        cout << "Error: Unable to open input file." << endl;
        exit(0);
    }
}
void countLetters(ifstream& inFile, LetterCount counts[]) {
    char ch;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            if (isupper(ch))
                counts[ch - 'A'].capitalCount++;
            else
                counts[ch - 'a'].smallCount++;
        }
    }
}
void printResult(LetterCount counts[]) {
    for (int i = 0; i < 26; ++i) {
        char letter = 'A' + i;
        int total = counts[i].capitalCount + counts[i].smallCount;
        cout << letter << ": " << counts[i].capitalCount << " capital letters, " << counts[i].smallCount << " small letters, ";
        if (total != 0) {
            cout << fixed << setprecision(2) << (counts[i].capitalCount * 100.0 / total) << "% capital, ";
            cout << fixed << setprecision(2) << (counts[i].smallCount * 100.0 / total) << "% small" << endl;
        } else {
            cout << "0% capital, 0% small" << endl;
        }
    }
}
