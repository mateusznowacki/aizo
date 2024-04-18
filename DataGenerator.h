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
    DataGenerator() {

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
        std::random_device rd;
        std::mt19937 gen(rd());

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        int sortedSize = size * 0.33;

        // Wypełnienie początkowej części tablicy liczbami posortowanymi
        if constexpr (std::is_arithmetic_v<T>) {
            T current_value = std::numeric_limits<T>::min();
            for (int i = 0; i < sortedSize; ++i) {
                arr[i] = current_value;
                ++current_value;
            }
        }

        // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<T> dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (std::is_floating_point_v<T>) {
            std::uniform_real_distribution<T> dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (std::is_same_v<T, char>) {
            std::uniform_int_distribution<int> dis(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = static_cast<T>(dis(gen));
            }
        }

        return arr;
    }

    template<typename T>
    T *generate66SortedArray(int size) {
        // Inicjalizacja generatora liczb pseudolosowych
        std::random_device rd;
        std::mt19937 gen(rd());

        // Alokacja pamięci dla tablicy
        T *arr = new T[size];

        int sortedSize = size * 0.66;

        // Wypełnienie początkowej części tablicy liczbami posortowanymi
        if constexpr (std::is_arithmetic_v<T>) {
            T current_value = std::numeric_limits<T>::min();
            for (int i = 0; i < sortedSize; ++i) {
                arr[i] = current_value;
                ++current_value;
            }
        }

        // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<T> dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (std::is_floating_point_v<T>) {
            std::uniform_real_distribution<T> dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = dis(gen);
            }
        } else if constexpr (std::is_same_v<T, char>) {
            std::uniform_int_distribution<int> dis(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
            for (int i = sortedSize; i < size; ++i) {
                arr[i] = static_cast<T>(dis(gen));
            }
        }

        return arr;
    }
};

#endif //AIZO_SORTOWANIE_DATAGENERATOR_H
