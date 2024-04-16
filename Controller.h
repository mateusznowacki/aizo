#ifndef AIZO_SORTOWANIE_CONTROLLER_H
#define AIZO_SORTOWANIE_CONTROLLER_H

#include <chrono>
#include "ConsoleManager.h"
#include "Algorithms.h"
#include "DataGenerator.h"
#include "FileManager.h"

using namespace std;

class Controller {

    ConsoleManager console;
    Algorithms algorithm;
    DataGenerator generator;
    FileManager fileManager;

public:
    void getUserDataForSorting() {
        int choice = 0;
        console.printAvailableDataSources();
        cin >> choice;
        if (choice == 1) {
            generateOwnDataAndSort();
        } else if (choice == 2) {
            getDataFromFileAndSort();
        }
    }

    void getDataFromFileAndSort() {
        string filename = console.printGetFilename();
        int type = console.getTypeOptions();
        int algorithmType = console.printSortingAlgorithmsOptions();

        switch (type) {
            case 1: {
                int *intArray = fileManager.getArrayFromFile<int>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                runSortingAlgorithmVerification<int>(intArray, size, algorithmType);
                delete[] intArray;
                break;
            }
            case 2: {
                double *doubleArray = fileManager.getArrayFromFile<double>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                runSortingAlgorithmVerification<double>(doubleArray, size, algorithmType);
                delete[] doubleArray;
                break;
            }
            case 3: {
                float *floatArray = fileManager.getArrayFromFile<float>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                runSortingAlgorithmVerification<float>(floatArray, size, algorithmType);
                delete[] floatArray;
                break;
            }
            case 4: {
                char *charArray = fileManager.getArrayFromFile<char>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                runSortingAlgorithmVerification<char>(charArray, size, algorithmType);
                delete[] charArray;
                break;
            }
        }
    }

    void generateOwnDataAndSort() {
        int type = console.getTypeOptions();
        int size = console.printGetArraySize();
        int arrayType = console.printSortedArrayType();
        int algorithmType = console.printSortingAlgorithmsOptions();
        switch (type) {
            case 1: {
                int *intArray = getArray<int>(size, arrayType);
                runSortingAlgorithmVerification<int>(intArray, size, algorithmType);
                delete[] intArray;
                break;
            }
            case 2: {
                double *doubleArray = getArray<double>(size, arrayType);
                runSortingAlgorithmVerification<double>(doubleArray, size, algorithmType);
                delete[] doubleArray;
                break;
            }
            case 3: {
                float *floatArray = getArray<float>(size, arrayType);
                runSortingAlgorithmVerification<float>(floatArray, size, algorithmType);
                delete[] floatArray;
                break;
            }
            case 4: {
                char *charArray = getArray<char>(size, arrayType);
                runSortingAlgorithmVerification<char>(charArray, size, algorithmType);
                delete[] charArray;
                break;
            }
        }
    }


    template<typename T>
    T *getArray(int size, int arrayType) {
        switch (arrayType) {
            case 1:
                return generator.generate33SortedArray<T>(size);
            case 2:
                return generator.generate66SortedArray<T>(size);
            case 3:
                return generator.generateAllRandomArray<T>(size);
            default:
                cerr << "Invalid array type." << std::endl;
                return nullptr;
        }
    }

    template<typename T>
    void runSortingAlgorithmVerification(T *array, int size, int algorithmType) {
        switch (algorithmType) {
            case 1: {
                console.printArray(array, size);
                algorithm.insertionSort(array, size);
                console.printArray(array, size);
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 2: {
                console.printArray(array, size);
                algorithm.insertionSortBinary(array, size);
                console.printArray(array, size);
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 3: {
                console.printArray(array, size);
                algorithm.mergeSort(array, size);
                console.printArray(array, size);
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 4: {
                console.printArray(array, size);
                algorithm.bubbleSort(array, size);
                console.printArray(array, size);
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 5: {
                console.printArray(array, size);
                algorithm.heapSort(array, size);
                console.printArray(array, size);
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 6: {
                console.printArray(array, size);
                algorithm.quickSort(array, size);
                console.printArray(array, size);
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
        }
    }

    template<typename T>
    auto runSortingAlgorithm(T *array, int size, int algorithmType) {
        chrono::high_resolution_clock::time_point start, end;

        switch (algorithmType) {
            case 1: {
                start = chrono::high_resolution_clock::now();
                algorithm.insertionSort(array, size);
                end = chrono::high_resolution_clock::now();
                break;
            }
            case 2: {
                start = chrono::high_resolution_clock::now();
                algorithm.insertionSortBinary(array, size);
                end = chrono::high_resolution_clock::now();
                break;
            }
            case 3: {
                start = chrono::high_resolution_clock::now();
                algorithm.mergeSort(array, size);
                end = chrono::high_resolution_clock::now();
                break;
            }
            case 4: {
                start = chrono::high_resolution_clock::now();
                algorithm.bubbleSort(array, size);
                end = chrono::high_resolution_clock::now();
                break;
            }
            case 5: {
                start = chrono::high_resolution_clock::now();
                algorithm.heapSort(array, size);
                end = chrono::high_resolution_clock::now();
                break;
            }
            case 6: {
                start = chrono::high_resolution_clock::now();
                algorithm.quickSort(array, size);
                end = chrono::high_resolution_clock::now();
                break;
            }
        }
        chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Sorting time: " << duration.count() << "ms" << endl;

        return duration; // Zwróć czas trwania sortowania
    }

    void generateAraaysToFile() {
        int type = console.getTypeOptions();
        int size = console.printGetArraySize();
        int arrayType = console.printSortedArrayType();

        switch (type) {
            case 1: {
                int *intArray = getArray<int>(size, arrayType);
                fileManager.saveArrayToFile(intArray, size);
                break;
            }
            case 2: {
                double *doubleArray = getArray<double>(size, arrayType);
                fileManager.saveArrayToFile(doubleArray, size);
                break;
            }
            case 3: {
                float *floatArray = getArray<float>(size, arrayType);
                fileManager.saveArrayToFile(floatArray, size);
                break;
            }
            case 4: {
                char *charArray = getArray<char>(size, arrayType);
                fileManager.saveArrayToFile(charArray, size);
                break;
            }
        }
    }
};

#endif //AIZO_SORTOWANIE_CONTROLLER_H
