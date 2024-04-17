#ifndef AIZO_SORTOWANIE_DATAGENERATOR_H
#define AIZO_SORTOWANIE_DATAGENERATOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>
#include <cmath>
#include <random>

using namespace std;

//todo poprawic generowanie tablic

class DataGenerator {
public:
    DataGenerator(){

    }

    template<typename T>
    T *generateAllRandomArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        random_device rd;
        mt19937 gen(rd());

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        if constexpr (is_integral_v<T>) {
            uniform_int_distribution<T> dis(numeric_limits<T>::min(), numeric_limits<T>::max());
            for (int i = 0; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (is_floating_point_v<T>) {
            uniform_real_distribution<T> dis(numeric_limits<T>::min(), numeric_limits<T>::max());
            for (int i = 0; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (is_same_v<T, char>) {
            uniform_int_distribution<int> dis(numeric_limits<char>::min(), numeric_limits<char>::max());
            for (int i = 0; i < size; ++i) {
                arr[i] = static_cast<T>(dis(gen));
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

        int sortedSize = size * 0.33;

        // Wypełnienie początkowej części tablicy liczbami posortowanymi
        if constexpr (is_arithmetic_v<T>) {
            T current_value = numeric_limits<T>::min();
            T max_value = numeric_limits<T>::max();
            T increment = (max_value - current_value) / sortedSize;
            for (int i = 0; i < sortedSize; ++i) {
                arr[i] = current_value;
                current_value += increment;
            }
        }

        // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
        for (int i = sortedSize; i < size; ++i) {
            if constexpr (is_same_v<T, int>) {
                arr[i] = rand();
            } else if constexpr (is_floating_point_v<T>) {
                T fraction = static_cast<T>(rand()) / RAND_MAX;
                T scale = numeric_limits<T>::max() - arr[i - 1];
                arr[i] = arr[i - 1] + fraction * scale;
            } else if constexpr (is_same_v<T, char>) {
                arr[i] = static_cast<T>(rand() % (numeric_limits<T>::max() - arr[i - 1] + 1) + arr[i - 1] + 1);
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
