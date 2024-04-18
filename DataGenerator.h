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

class DataGenerator {
public:
    // Konstruktor klasy DataGenerator
    DataGenerator() {

    }

    // Metoda do generowania tablicy zawierającej losowe elementy
    template<typename T>
    T *generateAllRandomArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        random_device rd;
        mt19937 gen(rd());

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        // Generowanie losowych wartości dla elementów tablicy
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

    // Metoda do generowania tablicy zawierającej 33% posortowane elementy
    template<typename T>
    T *generate33SortedArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        random_device rd;
        mt19937 gen(rd());

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        int sortedSize = size * 0.33;

        // Wypełnienie początkowej części tablicy liczbami posortowanymi
        if constexpr (is_arithmetic_v<T>) {
            T current_value = numeric_limits<T>::min();
            for (int i = 0; i < sortedSize; ++i) {
                arr[i] = current_value;
                ++current_value;
            }
        }

        // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
        if constexpr (is_integral_v<T>) {
            uniform_int_distribution<T> dis(numeric_limits<T>::min(), numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (is_floating_point_v<T>) {
            uniform_real_distribution<T> dis(numeric_limits<T>::min(), numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (is_same_v<T, char>) {
            uniform_int_distribution<int> dis(numeric_limits<char>::min(), numeric_limits<char>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = static_cast<T>(dis(gen));
            }
        }

        return arr;
    }

    // Metoda do generowania tablicy zawierającej 66% posortowane elementy
    template<typename T>
    T *generate66SortedArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        random_device rd;
        mt19937 gen(rd());

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        int sortedSize = size * 0.66;

        // Wypełnienie początkowej części tablicy liczbami posortowanymi
        if constexpr (is_arithmetic_v<T>) {
            T current_value = numeric_limits<T>::min();
            for (int i = 0; i < sortedSize; ++i) {
                arr[i] = current_value;
                ++current_value;
            }
        }

        // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
        if constexpr (is_integral_v<T>) {
            uniform_int_distribution<T> dis(numeric_limits<T>::min(), numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (is_floating_point_v<T>) {
            uniform_real_distribution<T> dis(numeric_limits<T>::min(), numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (is_same_v<T, char>) {
            uniform_int_distribution<int> dis(numeric_limits<char>::min(), numeric_limits<char>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = static_cast<T>(dis(gen));
            }
        }

        return arr;
    }
};

#endif //AIZO_SORTOWANIE_DATAGENERATOR_H
