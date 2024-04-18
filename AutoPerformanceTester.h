#ifndef AIZO_SORTOWANIE_AUTOPERFORMANCETESTER_H
#define AIZO_SORTOWANIE_AUTOPERFORMANCETESTER_H


#include "FileManager.h"
#include "ConsoleManager.h"
#include "Controller.h"
#include <iostream>

using namespace std;

class AutoPerformanceTester {

    FileManager fileManager;
    Controller controller;
    DataGenerator generator;
    ConsoleManager console;

public:
    // Metoda do uruchamiania automatycznych testów wydajnościowych
    void runAutoTests() {
        // Pobranie konfiguracji testów z pliku
        string type = fileManager.getConfigFileType();
        int iterations = fileManager.getConfigFileIterations();
        int *sizes = fileManager.getConfigFileArraySize();
        int algorithm = stoi(fileManager.getConfigFileAlgorithm());
        int arrayType = stoi(fileManager.getConfigFileArray());
        auto time = chrono::steady_clock::duration::zero();

        // Wyświetlenie konfiguracji testów
        console.printConfig(type, iterations, sizes, algorithm, arrayType);

        // Wybór odpowiedniego typu danych i przeprowadzenie testów dla każdego przypadku
        if (type == "int") {
            for (int k = 1; k <= 3; ++k) {
                for (int i = 0; i < 7; ++i) {
                    int *array = new int[sizes[i]];
                    for (int j = 0; j < iterations; ++j) {
                        switch (k) {
                            case 1: {
                                array = generator.generateAllRandomArray<int>(sizes[i]);
                                break;
                            }
                            case 2: {
                                array = generator.generate33SortedArray<int>(sizes[i]);
                                break;
                            }
                            case 3: {
                                array = generator.generate66SortedArray<int>(sizes[i]);
                                break;
                            }
                        }
                        time = controller.runSortingAlgorithm(array, sizes[i], algorithm);
                        fileManager.saveResultToFile(time, algorithm, k, sizes[i]);
                    }
                    delete[] array;
                }
            }
            //Analogicznie dla poniższych typów
        } else if (type == "float") {
            for (int k = 1; k <= 3; ++k) {
                for (int i = 0; i < 7; ++i) {
                    float *array = new float[sizes[i]];
                    for (int j = 0; j < iterations; ++j) {
                        switch (k) {
                            case 1: {
                                array = generator.generateAllRandomArray<float>(sizes[i]);
                                break;
                            }
                            case 2: {
                                array = generator.generate33SortedArray<float>(sizes[i]);
                                break;
                            }
                            case 3: {
                                array = generator.generate66SortedArray<float>(sizes[i]);
                                break;
                            }
                        }
                        time = controller.runSortingAlgorithm(array, sizes[i], algorithm);
                        fileManager.saveResultToFile(time, algorithm, k, sizes[i]);
                    }
                    delete[] array;
                }
            }
        } else if (type == "double") {
            for (int k = 1; k <= 3; ++k) {
                for (int i = 0; i < 7; ++i) {
                    double *array = new double[sizes[i]];
                    for (int j = 0; j < iterations; ++j) {
                        switch (k) {
                            case 1: {
                                array = generator.generateAllRandomArray<double>(sizes[i]);
                                break;
                            }
                            case 2: {
                                array = generator.generate33SortedArray<double>(sizes[i]);
                                break;
                            }
                            case 3: {
                                array = generator.generate66SortedArray<double>(sizes[i]);
                                break;
                            }
                        }
                        time = controller.runSortingAlgorithm(array, sizes[i], algorithm);
                        fileManager.saveResultToFile(time, algorithm, k, sizes[i]);
                    }
                    delete[] array;
                }
            }
        } else if (type == "char") {
            for (int k = 1; k <= 3; ++k) {
                for (int i = 0; i < 7; ++i) {
                    char *array = new char[sizes[i]];
                    for (int j = 0; j < iterations; ++j) {
                        switch (k) {
                            case 1: {
                                array = generator.generateAllRandomArray<char>(sizes[i]);
                                break;
                            }
                            case 2: {
                                array = generator.generate33SortedArray<char>(sizes[i]);
                                break;
                            }
                            case 3: {
                                array = generator.generate66SortedArray<char>(sizes[i]);
                                break;
                            }
                        }
                        time = controller.runSortingAlgorithm(array, sizes[i], algorithm);
                        fileManager.saveResultToFile(time, algorithm, k, sizes[i]);
                    }
                    delete[] array;
                }
            }
        }
        cout << "Testy zakonczone pomyslnie" << endl;
    }

};

#endif //AIZO_SORTOWANIE_AUTOPERFORMANCETESTER_H
