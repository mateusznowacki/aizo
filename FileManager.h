#ifndef AIZO_SORTOWANIE_FILEMANAGER_H
#define AIZO_SORTOWANIE_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

class FileManager {
public:
    template<typename T>
    void saveArrayToFile(T *arr, int size) {
        string filename;

        cout << "Podaj nazwe pliku do ktorego chcesz zapisac tablice: " << endl;
        cin >> filename;

        // Otwarcie pliku do zapisu
        ofstream outputFile(filename.c_str(), ofstream::trunc);
        if (!outputFile.is_open()) {
            cerr << "Nie mozna otworzyc pliku do zapisu." << endl;
            return;
        }

        // Zapisanie rozmiaru tablicy w pierwszej linii pliku
        outputFile << size << endl;

        // Zapisanie zawartości tablicy do pliku
        for (int i = 0; i < size; ++i) {
            outputFile << arr[i] << endl;
        }

        // Zamknięcie pliku
        outputFile.close();

        cout << "Tablica zostala zapisana do pliku " << endl;
    }

    template<typename T>
    T *getArrayFromFile(string filename) {
        int size = 0;
        T *arr;

        // Otwórz plik do odczytu
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Nie mozna otworzyc pliku do odczytu." << endl;
            return nullptr;
        }

        // Odczytaj rozmiar tablicy z pierwszej linii pliku
        if (!(inputFile >> size)) {
            cerr << "Blad odczytu rozmiaru tablicy z pliku." << endl;
            inputFile.close();
            return nullptr;
        }

        // Inicjalizuj tablicę o odpowiednim rozmiarze
        arr = new T[size];

        // Odczytaj dane z pliku i wpisz do tablicy
        for (int i = 0; i < size; ++i) {
            if (!(inputFile >> arr[i])) {
                cerr << "Blad odczytu danych z pliku." << endl;
                delete[] arr; // Zwolnij pamięć w przypadku błędu
                inputFile.close();
                return nullptr;
            }
        }

        cout << "Tablica zostala wczytana z pliku." << endl;

        return arr;
    }


    int getArraySizeFromFile(string filename) {
        int size = 0;
        // Otwórz plik do odczytu
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Nie mozna otworzyc pliku do odczytu." << endl;
        }

        // Odczytaj rozmiar tablicy z pierwszej linii pliku
        if (!(inputFile >> size)) {
            cerr << "Blad odczytu rozmiaru tablicy z pliku." << endl;
            inputFile.close();
        }
        return size;
    }

    string getConfigFileType() {
        ifstream inputFile("../config.txt");

        if (!inputFile.is_open()) {
            cerr << "Nie udało się otworzyć pliku: " << endl;
        }

        string line;
        while (getline(inputFile, line)) {
            // Sprawdź, czy linia zawiera "type:"
            if (line.find("type:") != string::npos) {
                // Znaleziono linię z "type:", zwróć wartość po dwukropku
                size_t colonPos = line.find(":");
                return line.substr(colonPos + 1);
            }
        }
        // Nie znaleziono linii z "type:"
        cerr << "Nie znaleziono linii z 'type:' w pliku: " << endl;
    }

    int getConfigFileIterations() {
        ifstream inputFile("../config.txt");

        if (!inputFile.is_open()) {
            cerr << "Nie udało się otworzyć pliku: " << endl;
            return -1; // Zwróć -1 w przypadku błędu
        }

        string line;
        while (getline(inputFile, line)) {
            // Sprawdź, czy linia zawiera "iterations:"
            if (line.find("iterations:") != string::npos) {
                // Znaleziono linię z "iterations:", zwróć wartość po dwukropku
                size_t colonPos = line.find(":");
                string valueStr = line.substr(colonPos + 1);
                // Konwertuj string na int i zwróć
                try {
                    return stoi(valueStr);
                } catch (...) {
                    cerr << "Błąd konwersji wartości 'iterations' na int." << endl;
                    return 0; // Zwróć 0 w przypadku błędu konwersji
                }
            }
        }
        // Nie znaleziono linii z "iterations:"
        cerr << "Nie znaleziono linii z 'iterations:' w pliku: " << endl;
        return 0; // Zwróć 0 jeśli nie znaleziono

    }

    int *getConfigFileArraySize() {
        ifstream inputFile("../config.txt");
        if (!inputFile.is_open()) {
            cerr << "Nie udało się otworzyć pliku: config.txt" << endl;
        }

        // Zliczanie linii zawierających klucz "size:"
        int amount = 0;
        string line;
        while (getline(inputFile, line)) {
            if (line.find("size:") != string::npos) {
                amount++;
            }
        }

        // Alokacja pamięci dla tablicy
        int *sizes = new int[amount];

        // Przejście przez plik ponownie i wpisanie wartości do tablicy
        inputFile.clear();
        inputFile.seekg(0, ios::beg); // Przewiń na początek pliku
        int index = 0;
        while (getline(inputFile, line)) {
            if (line.find("size:") != string::npos) {
                // Znaleziono linię zawierającą "size:", pobierz wartość i zapisz do tablicy
                size_t colonPos = line.find(":");
                string valueStr = line.substr(colonPos + 1);
                try {
                    sizes[index++] = stoi(valueStr);
                } catch (...) {
                    cerr << "Błąd konwersji wartości 'size' na int." << endl;
                    delete[] sizes; // Zwolnij zaalokowaną pamięć w przypadku błędu
                    return nullptr; // Zwróć nullptr w przypadku błędu konwersji
                }
            }
        }

        inputFile.close();
        return sizes;
    }

    string getConfigFileAlgorithm() {
        ifstream inputFile("../config.txt");

        if (!inputFile.is_open()) {
            cerr << "Nie udało się otworzyć pliku: " << endl;
        }

        string line;
        while (getline(inputFile, line)) {
            // Sprawdź, czy linia zawiera "type:"
            if (line.find("algorithm:") != string::npos) {
                // Znaleziono linię z "type:", zwróć wartość po dwukropku
                size_t colonPos = line.find(":");
                return line.substr(colonPos + 1);
            }
        }
        // Nie znaleziono linii z "type:"
        cerr << "Nie znaleziono linii z 'type:' w pliku: " << endl;
    }

    string getConfigFileArray() {
        ifstream inputFile("../config.txt");

        if (!inputFile.is_open()) {
            cerr << "Nie udało się otworzyć pliku: " << endl;
        }

        string line;
        while (getline(inputFile, line)) {
            // Sprawdź, czy linia zawiera "type:"
            if (line.find("array:") != string::npos) {
                // Znaleziono linię z "type:", zwróć wartość po dwukropku
                size_t colonPos = line.find(":");
                return line.substr(colonPos + 1);
            }
        }
        // Nie znaleziono linii z "type:"
        cerr << "Nie znaleziono linii z 'type:' w pliku: " << endl;
    }

    void
    saveResultToFile(chrono::duration<int64_t, ratio<1, 1000000000>> time, int algorithm, int arrayType, int size) {
        string filename;
        string algorithmName;
        string arrayTypeName;

        switch (algorithm) {
            case 1:
                algorithmName = "insertionSort";
                break;
            case 2:
                algorithmName = "binaryInsertionSort";
                break;
            case 3:
                algorithmName = "mergeSort";
                break;
            case 4:
                algorithmName = "bubbleSort";
                break;
            case 5:
                algorithmName = "heapSort";
                break;
            case 6:
                algorithmName = "quickSort";
                break;
        }

        switch (arrayType) {
            case 1:
                arrayTypeName = "random";
                break;
            case 2:
                arrayTypeName = "33sorted";
                break;
            case 3:
                arrayTypeName = "66sorted";
                break;

        }

        filename = algorithmName + "_" + arrayTypeName + "_" + to_string(size) + ".txt";

        // Otwarcie pliku w trybie dopisywania
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            // Obsługa błędu, jeśli nie udało się otworzyć pliku
            cerr << "Warning: Could not open file, creating a new file." << endl;
            // Utworzenie nowego pliku
            file.open(filename);
            if (!file.is_open()) {
                // Obsługa błędu, jeśli nie udało się utworzyć nowego pliku
                cerr << "Error: Could not create file" << endl;
                return;
            }
        }
        auto duration_ms = chrono::duration_cast<chrono::milliseconds>(time);

        // Zapisanie wyniku czasu do pliku
        file << duration_ms.count() << endl;

        // Zamknięcie pliku
        file.close();

    }
};

#endif //AIZO_SORTOWANIE_FILEMANAGER_H