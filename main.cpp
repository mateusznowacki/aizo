#include <iostream>
#include "ConsoleManager.h"
#include "Controller.h"
#include "AutoPerformanceTester.h"

using namespace std;

int main() {

    AutoPerformanceTester tester;
    ConsoleManager console;
    Controller controller;
    DataGenerator generator;

    int choice = 0;
    do {
        console.printMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                controller.generateAraaysToFile();
                break;
            }
            case 2:
                controller.getUserDataForSorting();
                break;
            case 3:
                tester.runAutoTests();
                break;
            default:
                cout << "Nie ma takiej opcji" << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
