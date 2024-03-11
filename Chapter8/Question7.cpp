#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int NUM_CANDIDATES = 5;
    char candidates[NUM_CANDIDATES][20];
    int votes[NUM_CANDIDATES];
    int totalVotes = 0;


    for (int i = 0; i < NUM_CANDIDATES; i++) {
        cout << "Enter the last name of candidate " << i + 1 << ": ";
        cin >> candidates[i];
        cout << "Enter the number of votes for " << candidates[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }


    int winnerIndex = 0;
    for (int i = 1; i < NUM_CANDIDATES; i++) {
        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    cout << "Candidate\tVotes Received\t% of Total Votes" << endl;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        double percentage = static_cast<double>(votes[i]) / totalVotes * 100;
        cout << candidates[i] << "\t\t" << votes[i] << "\t\t" << percentage << "%" << endl;
    }
    cout << "Total\t\t" << totalVotes << endl;
    cout << "The Winner of the Election is " << candidates[winnerIndex] << "." << endl;

    return 0;
}