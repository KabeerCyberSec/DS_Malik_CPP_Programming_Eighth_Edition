#include <iostream>
#include <iomanip>
using namespace std;
const int ROWS = 13;
const int SEATS_PER_ROW = 6;
const char AVAILABLE = '*';
const char OCCUPIED = 'X';

void initializeSeatingPlan(char seatingPlan[][SEATS_PER_ROW]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            seatingPlan[i][j] = AVAILABLE;
        }
    }
}
void displaySeatingPlan(const char seatingPlan[][SEATS_PER_ROW]) {
    char seatLetter = 'A';
    cout << "  ";
    for (int i = 0; i < SEATS_PER_ROW; ++i) {
        cout << setw(2) << seatLetter++ << " ";
    }
    cout << endl;

    for (int i = 0; i < ROWS; ++i) {
        cout << "Row " << setw(2) << i + 1 << " ";
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            cout << setw(2) << seatingPlan[i][j] << " ";
        }
        cout << endl;
    }
}
void assignSeat(char seatingPlan[][SEATS_PER_ROW], int row, char seat) {
    int seatIndex = seat - 'A';
    if (seatingPlan[row - 1][seatIndex] == AVAILABLE) {
        seatingPlan[row - 1][seatIndex] = OCCUPIED;
        cout << "Seat assigned successfully." << endl;
    } else {
        cout << "Seat is already occupied. Please choose another seat." << endl;
    }
}
int main() {
    char seatingPlan[ROWS][SEATS_PER_ROW];
    initializeSeatingPlan(seatingPlan);
    int ticketType, row;
    char seat;
    while (true) {
        cout << "\n1. Assign Seat\n";
        cout << "2. Display Seating Plan\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ticketType;
        switch (ticketType) {
            case 1:
                cout << "Enter ticket type (1: First Class, 2: Business Class, 3: Economy Class): ";
                cin >> ticketType;
                if (ticketType < 1 || ticketType > 3) {
                    cout << "Invalid ticket type." << endl;
                    break;
                }
                cout << "Enter desired row number (1-13): ";
                cin >> row;
                if (row < 1 || row > ROWS) {
                    cout << "Invalid row number." << endl;
                    break;
                }
                cout << "Enter desired seat letter (A-F): ";
                cin >> seat;
                seat = toupper(seat);
                if (seat < 'A' || seat > 'F') {
                    cout << "Invalid seat letter." << endl;
                    break;
                }
                assignSeat(seatingPlan, row, seat);
                break;
            case 2:
                displaySeatingPlan(seatingPlan);
                break;
            case 3:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
