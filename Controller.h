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
        bool printArray = console.askIfPrintArray();

        switch (type) {
            case 1: {
                int *intArray = fileManager.getArrayFromFile<int>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                int *intArrayCopy = new int[size];

                do {
                    copy(intArray, intArray + size, intArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<int>(intArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] intArray;
                delete[] intArrayCopy;
                break;
            }
            case 2: {
                double *doubleArray = fileManager.getArrayFromFile<double>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                double *doubleArrayCopy = new double[size];

                do {
                    copy(doubleArray, doubleArray + size, doubleArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<double>(doubleArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] doubleArray;
                delete[] doubleArrayCopy;
                break;
            }
            case 3: {
                float *floatArray = fileManager.getArrayFromFile<float>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                float *floatArrayCopy = new float[size];


                do {
                    copy(floatArray, floatArray + size, floatArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<float>(floatArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] floatArray;
                delete[] floatArrayCopy;
                break;
            }
            case 4: {
                char *charArray = fileManager.getArrayFromFile<char>(filename);
                int size = fileManager.getArraySizeFromFile(filename);
                char *charArrayCopy = new char[size];

                do {
                    copy(charArray, charArray + size, charArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<char>(charArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] charArray;
                delete[] charArrayCopy;
                break;
            }
        }
    }

    void generateOwnDataAndSort() {
        int type = console.getTypeOptions();
        int size = console.printGetArraySize();
        int arrayType = console.printSortedArrayType();
        bool printArray = console.askIfPrintArray();
        switch (type) {
            case 1: {
                int *intArray = getArray<int>(size, arrayType);
                int *intArrayCopy = new int[size];

                do {
                    copy(intArray, intArray + size, intArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<int>(intArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());


                delete[] intArray;
                delete[] intArrayCopy;
                break;
            }
            case 2: {
                double *doubleArray = getArray<double>(size, arrayType);
                double *doubleArrayCopy = new double[size];

                do {
                    copy(doubleArray, doubleArray + size, doubleArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<double>(doubleArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] doubleArray;
                delete[] doubleArrayCopy;
                break;
            }
            case 3: {
                float *floatArray = getArray<float>(size, arrayType);
                float *floatArrayCopy = new float[size];

                do {
                    copy(floatArray, floatArray + size, floatArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<float>(floatArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] floatArray;
                delete[] floatArrayCopy;
                break;
            }
            case 4: {
                char *charArray = getArray<char>(size, arrayType);
                char *charArrayCopy = new char[size];

                do {
                    copy(charArray, charArray + size, charArrayCopy);
                    int algorithmType = console.printSortingAlgorithmsOptions();
                    runSortingAlgorithmVerification<char>(charArrayCopy, size, algorithmType, printArray);

                } while (console.askIfWantToCheckOtherAlgorithm());

                delete[] charArray;
                delete[] charArrayCopy;
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
    void runSortingAlgorithmVerification(T *array, int size, int algorithmType, bool printArray) {
        switch (algorithmType) {
            case 1: {
                printArray ? console.printArray(array, size) : void();
                algorithm.insertionSort(array, size);
                printArray ? console.printArray(array, size) : void();
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 2: {
                printArray ? console.printArray(array, size) : void();
                algorithm.insertionSortBinary(array, size);
                printArray ? console.printArray(array, size) : void();
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 3: {
                printArray ? console.printArray(array, size) : void();
                algorithm.mergeSort(array, size);
                printArray ? console.printArray(array, size) : void();
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 4: {
                printArray ? console.printArray(array, size) : void();
                algorithm.bubbleSort(array, size);
                printArray ? console.printArray(array, size) : void();
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 5: {
                printArray ? console.printArray(array, size) : void();
                algorithm.heapSort(array, size);
                printArray ? console.printArray(array, size) : void();
                console.printIfCorrectlySorted(algorithm.isSorted(array, size));
                break;
            }
            case 6: {
                printArray ? console.printArray(array, size) : void();
                algorithm.quickSort(array, size);
                printArray ? console.printArray(array, size) : void();
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
        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
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
