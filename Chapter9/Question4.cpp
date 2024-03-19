#include <iostream>
#include <iomanip>
using namespace std;
struct menuItemType {
    string menuItem;
    double menuPrice;
};
void getData(menuItemType menuList[], int numItems) {
    menuList[0] = {"Plain Egg", 1.45};
    menuList[1] = {"Bacon and Egg", 2.45};
    menuList[2] = {"Muffin", 0.99};
    menuList[3] = {"French Toast", 1.99};
    menuList[4] = {"Fruit Basket", 2.49};
    menuList[5] = {"Cereal", 0.69};
    menuList[6] = {"Coffee", 0.50};
    menuList[7] = {"Tea", 0.75};
}
void showMenu(menuItemType menuList[], int numItems) {
    cout << "Welcome to Johnny's Restaurant" << endl;
    for (int i = 0; i < numItems; ++i) {
        cout << left << setw(15) << menuList[i].menuItem << "$" << fixed << setprecision(2) << menuList[i].menuPrice << endl;
    }
    cout << endl;
    cout << "To select an item, enter the number corresponding to the item:" << endl;
    cout << "For example, enter 1 for Plain Egg, 2 for Bacon and Egg, and so on." << endl;
}
void printCheck(menuItemType menuList[], int selections[], int numSelections) {
    double total = 0;
    for (int i = 0; i < numSelections; ++i) {
        total += menuList[selections[i] - 1].menuPrice;
    }
    double tax = total * 0.05;
    double amountDue = total + tax;
    cout << "Tax $" << fixed << setprecision(2) << tax << endl;
    cout << "Amount Due $" << fixed << setprecision(2) << amountDue << endl;
}

int main() {
    const int numItems = 8;
    menuItemType menuList[numItems];
    int selections[numItems];
    int numSelections = 0;
    getData(menuList, numItems);
    showMenu(menuList, numItems);
    int selection;
    cout << "Enter the numbers corresponding to the items you want to order (enter 0 to finish):" << endl;
    while (true) {
        cin >> selection;
        if (selection == 0)
            break;
        else if (selection < 1 || selection > numItems) {
            cout << "Invalid selection. Please enter a number between 1 and " << numItems << "." << endl;
        } else {
            selections[numSelections++] = selection;
        }
    }
    cout << endl;
    printCheck(menuList, selections, numSelections);

    return 0;
}
