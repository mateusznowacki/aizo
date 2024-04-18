#ifndef AIZO_SORTOWANIE_CONSOLEMANAGER_H
#define AIZO_SORTOWANIE_CONSOLEMANAGER_H

#include <iostream>

using namespace std;

class ConsoleManager {
public:
    // Metoda do wyświetlania tablicy
    template<typename T>
    void printArray(T arr[], int size) {
        cout << "[";
        for (int i = 0; i < size; ++i) {
            cout << fixed << arr[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    // Metoda do wyświetlania głównego menu
    void printMenu() {
        cout << "Wybierz opcje z menu" << endl;
        cout << "1. Generowanie tablic do pliku" << endl;
        cout << "2. Sprawdzanie poprawnosci algorytmow" << endl;
        cout << "3. Pomiary automatyczne i generowanie wynikow" << endl;
        cout << "4. Wyjscie" << endl;
    }

    // Metoda do wybierania typu danych
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

    // Metoda do wybierania algorytmu sortowania
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

    // Metoda do wybierania stopnia posortowania tablicy
    int printSortedArrayType() {
        cout << "Wybierz w jakim stopniu ma byc posortowana tablica" << endl;
        cout << "1. 1/3" << endl;
        cout << "2. 2/3" << endl;
        cout << "3. Losowa" << endl;
        int choice = 0;
        cin >> choice;
        return choice;
    }

    // Metoda do pobierania rozmiaru tablicy od użytkownika
    int printGetArraySize() {
        cout << "Wpisz ilosc elementow ktore ma miec tablica" << endl;
        int choice = 0;
        cin >> choice;
        return choice;
    }

    // Metoda do wyświetlania dostępnych źródeł danych
    void printAvailableDataSources() {
        cout << "Wybierz zrodlo danych" << endl;
        cout << "1. Wygeneruj losowe dane" << endl;
        cout << "2. Wczytaj dane z pliku" << endl;
    }

    // Metoda do pobierania nazwy pliku od użytkownika
    string printGetFilename() {
        string filename;
        cout << "Podaj nazwe pliku z ktorego chcesz wczytac tablice: " << endl;
        cin >> filename;
        return filename;
    }

    // Metoda do wyświetlania informacji o poprawności posortowania tablicy
    void printIfCorrectlySorted(bool isCorrect) {
        if (isCorrect) {
            cout << "Tablica zostala posortowana poprawnie" << endl;
        } else {
            cout << "Tablica nie jest posortowana poprawnie" << endl;
        }
    }

    // Metoda do zapytania użytkownika, czy chce wyświetlić tablicę przed i po sortowaniu
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

    // Metoda do zapytania użytkownika, czy chce sprawdzić inny algorytm sortowania
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

    // Metoda do wyświetlania konfiguracji testów
    void printConfig(string type, int iterations, int *sizes, int algorithm, int arrayType) {
        cout << "Typ danych: " << type << endl;
        cout << "Ilosc iteracji: " << iterations << endl;
        cout << "Rozmiary tablic: ";
        for (int i = 0; i < 7; ++i) {
            cout << sizes[i] << " ";
        }
        cout << endl;

        switch (algorithm) {
            case 1: {
                cout << "Algorytm: Insertion sort" << endl;
                break;
            }
            case 2: {
                cout << "Algorytm: Binary insertion sort" << endl;
                break;
            }
            case 3: {
                cout << "Algorytm: Merge sort" << endl;
                break;
            }
            case 4: {
                cout << "Algorytm: Bubble sort" << endl;
                break;
            }
            case 5: {
                cout << "Algorytm: Heap sort" << endl;
                break;
            }
            case 6: {
                cout << "Algorytm: Quick sort" << endl;
                break;
            }

        }
    }
};

#endif //AIZO_SORTOWANIE_CONSOLEMANAGER_H
