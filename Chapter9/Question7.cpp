#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store football player data
struct FootballPlayer {
    string playerName;
    string playerPosition;
    int touchdowns;
    int catches;
    int passingYards;
    int receivingYards;
    int rushingYards;
};

// Function prototypes
void inputData(FootballPlayer players[], int size);
void outputData(FootballPlayer players[], int size);
int searchPlayer(FootballPlayer players[], int size, string playerName);
void updatePlayerData(FootballPlayer players[], int size);
void saveDataToFile(FootballPlayer players[], int size);

int main() {
    const int size = 10;
    FootballPlayer players[size];

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Input player data\n";
        cout << "2. Output player data\n";
        cout << "3. Search for a player\n";
        cout << "4. Update player data\n";
        cout << "5. Save data to file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputData(players, size);
                break;
            case 2:
                outputData(players, size);
                break;
            case 3: {
                string playerName;
                cout << "Enter player name to search: ";
                cin >> playerName;
                int index = searchPlayer(players, size, playerName);
                if (index != -1)
                    cout << "Player found at index " << index << endl;
                else
                    cout << "Player not found." << endl;
                break;
            }
            case 4:
                updatePlayerData(players, size);
                break;
            case 5:
                saveDataToFile(players, size);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to input player data
void inputData(FootballPlayer players[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter details for player " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> players[i].playerName;
        cout << "Position: ";
        cin >> players[i].playerPosition;
        cout << "Touchdowns: ";
        cin >> players[i].touchdowns;
        cout << "Catches: ";
        cin >> players[i].catches;
        cout << "Passing yards: ";
        cin >> players[i].passingYards;
        cout << "Receiving yards: ";
        cin >> players[i].receivingYards;
        cout << "Rushing yards: ";
        cin >> players[i].rushingYards;
    }
}

void outputData(FootballPlayer players[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Player " << i + 1 << ":\n";
        cout << "Name: " << players[i].playerName << endl;
        cout << "Position: " << players[i].playerPosition << endl;
        cout << "Touchdowns: " << players[i].touchdowns << endl;
        cout << "Catches: " << players[i].catches << endl;
        cout << "Passing yards: " << players[i].passingYards << endl;
        cout << "Receiving yards: " << players[i].receivingYards << endl;
        cout << "Rushing yards: " << players[i].rushingYards << endl;
    }
}

void saveDataToFile(FootballPlayer players[], int size) {
    ofstream outFile("player_data.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << "Player " << i + 1 << ":\n";
            outFile << "Name: " << players[i].playerName << endl;
            outFile << "Position: " << players[i].playerPosition << endl;
            outFile << "Touchdowns: " << players[i].touchdowns << endl;
            outFile << "Catches: " << players[i].catches << endl;
            outFile << "Passing yards: " << players[i].passingYards << endl;
            outFile << "Receiving yards: " << players[i].receivingYards << endl;
            outFile << "Rushing yards: " << players[i].rushingYards << endl;
        }
        cout << "Player data saved to player_data.txt" << endl;
        outFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

int searchPlayer(FootballPlayer players[], int size, string playerName) {
    for (int i = 0; i < size; ++i) {
        if (players[i].playerName == playerName)
            return i;
    }
    return -1; // Player not found
}

void updatePlayerData(FootballPlayer players[], int size) {
    string playerName;
    cout << "Enter player name to update: ";
    cin >> playerName;
    int index = searchPlayer(players, size, playerName);
    if (index != -1) {
        cout << "Enter new details for player ";
        cout << "Name: ";
        cin >> players[index].playerName;
        cout << "Position: ";
        cin >> players[index].playerPosition;
        cout << "Touchdowns: ";
        cin >> players[index].touchdowns;
        cout << "Catches: ";
        cin >> players[index].catches;
        cout << "Passing yards: ";
        cin >> players[index].passingYards;
        cout << "Receiving yards: ";
        cin >> players[index].receivingYards;
        cout << "Rushing yards: ";
        cin >> players[index].rushingYards;
    }
    else cout<<"Player not found";
}