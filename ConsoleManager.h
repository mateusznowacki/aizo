#ifndef AIZO_SORTOWANIE_CONSOLEMANAGER_H
#define AIZO_SORTOWANIE_CONSOLEMANAGER_H

#include <iostream>

using namespace std;


class ConsoleManager {
public:
    template<typename T>
    void printArray(T arr[], int size) {
        cout << "[";
        for (int i = 0; i < size; ++i) {
            cout << fixed<<arr[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    void printMenu() {
        cout << "Wybierz opcje z menu" << endl;
        cout << "1. Generowanie tablic do pliku" << endl;
        cout << "2. Sprawdzanie poprawnosci algorytmow" << endl;
        cout << "3. Pomiary automatyczne i generowanie wynikow" << endl;
        cout << "4. Wyjscie" << endl;
    }


    int getTypeOptions() {
        cout << "Wybierz typ danych" << endl;
        cout << "1. Int" << endl;
        cout << "2. Double" << endl;
        cout << "3. Float" << endl;
        cout << "4. Char" << endl;
        int choice = 0;
        cin >> choice;
        return choice;
    }


    int printSortingAlgorithmsOptions() {
        cout << "Wybierz algorytm sortowania" << endl;
        cout << "1. Insertion sort" << endl;
        cout << "2. Binary insertion sort" << endl;
        cout << "3. Merge sort" << endl;
        cout << "4. Bubble sort " << endl;
        cout << "5. Heap sort" << endl;
        cout << "6. Quick sort" << endl;
        int choice = 0;
        cin >> choice;
        return choice;
    }


    int printSortedArrayType() {
        cout << "Wybierz w jakim stopniu ma byc posortowana tablica" << endl;
        cout << "1. 1/3" << endl;
        cout << "2. 2/3" << endl;
        cout << "3. Losowa" << endl;
        int choice = 0;
        cin >> choice;
        return choice;
    }

    int printGetArraySize() {
        cout << "Wpisz ilosc elementow ktore ma miec tablica" << endl;
        int choice = 0;
        cin >> choice;
        return choice;
    }


    void printAvailableDataSources() {
        cout << "Wybierz zrodlo danych" << endl;
        cout << "1. Wygeneruj losowe dane" << endl;
        cout << "2. Wczytaj dane z pliku" << endl;
    }

    string printGetFilename() {
        string filename;
        cout << "Podaj nazwe pliku z ktorego chcesz wczytac tablice: " << endl;
        cin >> filename;
        return filename;
    }

    void printIfCorrectlySorted(bool isCorrect) {
        if (isCorrect) {
            cout << "Tablica zostala posortowana poprawnie" << endl;
        } else {
            cout << "Tablica nie jest posortowana poprawnie" << endl;
        }
    }

    bool askIfPrintArray() {
        cout << "Czy chcesz wyswietlic tablice przed i po sortowaniu?  1-tak 0-nie" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            return true;
        } else {
            return false;
        }
    }

    bool askIfWantToCheckOtherAlgorithm() {
        cout << "Czy chcesz sprawdzic inny algorytm sortowania? 1-tak 0-nie" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            return true;
        } else {
            return false;
        }
    }
};


#endif //AIZO_SORTOWANIE_CONSOLEMANAGER_H
