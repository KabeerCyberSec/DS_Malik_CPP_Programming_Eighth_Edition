#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("scores.txt");
    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int scores[26];
    int count[8] = {0};

    int score;
    int i = 0;
    while (infile >> score) {
        scores[i++] = score;
    }

    int numScores = i;

    for (int i = 0; i < numScores; i++) {
        int range = scores[i] / 25;  
        if (range < 0 || range > 7) {
            cout << "Score out of range: " << scores[i] << endl;
        } else {
            count[range]++;
        }
    }

    cout << "Score Range\tCount" << endl;
    cout << "0-24\t\t" << count[0] << endl;
    cout << "25-49\t\t" << count[1] << endl;
    cout << "50-74\t\t" << count[2] << endl;
    cout << "75-99\t\t" << count[3] << endl;
    cout << "100-124\t\t" << count[4] << endl;
    cout << "125-149\t\t" << count[5] << endl;
    cout << "150-174\t\t" << count[6] << endl;
    cout << "175-200\t\t" << count[7] << endl;
    infile.close();
    return 0;
}