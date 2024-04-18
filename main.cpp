#include <iostream>
#include "ConsoleManager.h" // Włączenie pliku nagłówkowego ConsoleManager.h
#include "Controller.h" // Włączenie pliku nagłówkowego Controller.h
#include "AutoPerformanceTester.h" // Włączenie pliku nagłówkowego AutoPerformanceTester.h

using namespace std;

int main() {

    AutoPerformanceTester tester; // Utworzenie obiektu tester klasy AutoPerformanceTester
    ConsoleManager console; // Utworzenie obiektu console klasy ConsoleManager
    Controller controller; // Utworzenie obiektu controller klasy Controller

    int choice = 0;
    do {
        console.printMenu(); // Wywołanie funkcji printMenu() z obiektu console
        cin >> choice; // Pobranie wyboru użytkownika

        switch (choice) {
            case 1: {
                controller.generateArraysToFile(); // Wywołanie funkcji generateAraaysToFile() generowanie tablic do pliku
                break;
            }
            case 2:
                controller.getUserDataForSorting(); // Wywołanie funkcji getUserDataForSorting() reczne sprawdznie poprawnosci algorytmow
                break;
            case 3:
                tester.runAutoTests(); // Wywołanie funkcji runAutoTests() do automatycznych testow i zbierania wynikow
                break;
            default:
                cout << "Nie ma takiej opcji" << endl; // Komunikat w przypadku nieprawidłowego wyboru
                break;
        }

    } while (choice != 4); // Pętla wykonuje się dopóki użytkownik nie wybierze opcji 4 (wyjście)

    return 0;
}
