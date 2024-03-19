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
        cout << i + 1 << " " << menuList[i].menuItem << " $" << fixed << setprecision(2) << menuList[i].menuPrice << endl;
    }
    cout << endl;
    cout << "To select an item, enter the number corresponding to the item followed by the quantity:" << endl;
    cout << "For example, enter '1 2' to select 2 Bacon and Egg." << endl;
}
void printCheck(menuItemType menuList[], int selections[], int quantities[], int numSelections) {
    double total = 0;
    for (int i = 0; i < numSelections; ++i) {
        int index = selections[i] - 1;
        total += menuList[index].menuPrice * quantities[i];
        cout << quantities[i] << " " << menuList[index].menuItem << " $" << fixed << setprecision(2) << menuList[index].menuPrice * quantities[i] << endl;
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
    int quantities[numItems];
    int numSelections = 0;
    getData(menuList, numItems);
    showMenu(menuList, numItems);
    cout << "Enter the numbers corresponding to the items you want to order followed by the quantity (enter 0 to finish):" << endl;
    int selection, quantity;
    while (true) {
        cin >> selection;
        if (selection == 0)
            break;
        cin >> quantity;
        selections[numSelections] = selection;
        quantities[numSelections] = quantity;
        numSelections++;
    }
    cout << endl;
    printCheck(menuList, selections, quantities, numSelections);

    return 0;
}
