#include <iostream>
using namespace std;
struct computerType {
    string manufacturer;
    string modelType;
    string processorType;
    int ramGB;
    int hardDriveGB;
    int yearBuilt;
    double price;
};

int main() {
    computerType myComputer;
    cout << "Enter manufacturer of the computer: ";
    getline(cin, myComputer.manufacturer);

    cout << "Enter model type of the computer: ";
    getline(cin, myComputer.modelType);

    cout << "Enter processor type of the computer: ";
    getline(cin, myComputer.processorType);

    cout << "Enter RAM size of the computer in GB: ";
    cin >> myComputer.ramGB;

    cout << "Enter hard drive size of the computer in GB: ";
    cin >> myComputer.hardDriveGB;

    cout << "Enter year when the computer was built: ";
    cin >> myComputer.yearBuilt;

    cout << "Enter price of the computer: ";
    cin >> myComputer.price;

    cout << "\nComputer Information:\n";
    cout << "Manufacturer: " << myComputer.manufacturer << endl;
    cout << "Model Type: " << myComputer.modelType << endl;
    cout << "Processor Type: " << myComputer.processorType << endl;
    cout << "RAM (GB): " << myComputer.ramGB << endl;
    cout << "Hard Drive (GB): " << myComputer.hardDriveGB << endl;
    cout << "Year Built: " << myComputer.yearBuilt << endl;
    cout << "Price: $" << myComputer.price << endl;

    return 0;
}
