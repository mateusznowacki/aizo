#ifndef AIZO_SORTOWANIE_DATAGENERATOR_H
#define AIZO_SORTOWANIE_DATAGENERATOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class DataGenerator {
public:
    DataGenerator(){

    }

    template<typename T>
    T *generateAllRandomArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        srand(time(nullptr));

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        for (int i = 0; i < size; ++i) {
            if constexpr (std::is_same<T, int>::value) {
                arr[i] = rand();
            } else if constexpr (std::is_same<T, float>::value) {
                // Generowanie losowej liczby typu float z zakresu [0, 1) bez notacji naukowej
                float fraction = static_cast<float>(rand()) / RAND_MAX;
                float scale = std::numeric_limits<float>::max();
                arr[i] = fraction * scale;
            } else if constexpr (std::is_same<T, double>::value) {
                // Generowanie losowej liczby typu double z zakresu [0, 1) bez notacji naukowej
                double fraction = static_cast<double>(rand()) / RAND_MAX;
                double scale = std::numeric_limits<double>::max();
                arr[i] = fraction * scale;
            } else if constexpr (std::is_same<T, char>::value) {
                arr[i] = static_cast<T>(rand() % (std::numeric_limits<T>::max() - std::numeric_limits<T>::min() + 1) + std::numeric_limits<T>::min());
            }
        }

        return arr;
    }

    template<typename T>
    T *generate33SortedArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        srand(time(nullptr));

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        // Wygenerowanie posortowanej części tablicy (pierwsze 33%)
        int sortedSize = static_cast<int>(size * 0.33);
        for (int i = 0; i < sortedSize; ++i) {
            arr[i] = static_cast<T>(i); // Liczby posortowane rosnąco
        }

        // Wygenerowanie reszty tablicy z losowymi liczbami większymi lub równe wartościom w posortowanej części
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = static_cast<T>(rand() % (RAND_MAX - sortedSize) +
                                    sortedSize); // Losowe liczby większe lub równe niż największa wartość w posortowanej części
        }

        // Sprawdzenie, czy dalsze liczby nie są mniejsze niż ostatnia posortowana liczba
        for (int i = sortedSize; i < size; ++i) {
            if (arr[i] < arr[sortedSize - 1]) {
                arr[i] = arr[sortedSize - 1] + 1; // Ustawiamy na wartość większą niż ostatnia posortowana liczba
            }
        }

        return arr;
    }

    template<typename T>
    T *generate66SortedArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        srand(time(nullptr));

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        // Wygenerowanie posortowanej części tablicy (pierwsze 66%)
        int sortedSize = static_cast<int>(size * 0.66);
        for (int i = 0; i < sortedSize; ++i) {
            arr[i] = static_cast<T>(i); // Liczby posortowane rosnąco
        }

        // Wygenerowanie reszty tablicy z losowymi liczbami większymi lub równe wartościom w posortowanej części
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = static_cast<T>(rand() % (RAND_MAX - sortedSize) +
                                    sortedSize); // Losowe liczby większe lub równe niż największa wartość w posortowanej części
        }

        // Sprawdzenie, czy dalsze liczby nie są mniejsze niż ostatnia posortowana liczba
        for (int i = sortedSize; i < size; ++i) {
            if (arr[i] < arr[sortedSize - 1]) {
                arr[i] = arr[sortedSize - 1] + 1; // Ustawiamy na wartość większą niż ostatnia posortowana liczba
            }
        }

        return arr;
    }


};

#endif //AIZO_SORTOWANIE_DATAGENERATOR_H
