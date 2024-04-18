#ifndef AIZO_SORTOWANIE_ALGORITHMS_H
#define AIZO_SORTOWANIE_ALGORITHMS_H

using namespace std;

class Algorithms {
public:
    Algorithms() {

    }

    template<typename T>
    T *insertionSort(T *arr, int size) {
        for (int i = 1; i < size; ++i) {
            T key = arr[i];
            int j = i - 1;

            // Przesuń elementy tablicy większe od klucza o jeden w prawo
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        return arr;
    }

    template<typename T>
    T *insertionSortBinary(T *arr, int size) {
        for (int i = 1; i < size; ++i) {
            T selected = arr[i];
            int loc = binarySearch(arr, selected, 0, i - 1);

            // Move elements to make space for selected element
            for (int j = i - 1; j >= loc; --j)
                arr[j + 1] = arr[j];

            // Insert the selected element at its correct position
            arr[loc] = selected;
        }
        return arr;
    }


    template<typename T>
    T *mergeSort(T *arr, int size) {
        mergeSortHelper(arr, 0, size - 1);
        return arr;
    }

    template<typename T>
    T *bubbleSort(T *arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            // Flaga określająca, czy wystąpiła zamiana w tej iteracji
            bool swapped = false;

            // Przechodzenie przez tablicę i zamiana sąsiednich elementów, jeśli są one w złej kolejności
            for (int j = 0; j < size - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Zamiana elementów
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    // Ustawienie flagi swapped na true, jeśli wystąpiła zamiana
                    swapped = true;
                }
            }

            // Jeśli w danej iteracji nie wystąpiła żadna zamiana, to tablica jest już posortowana, można przerwać pętlę
            if (!swapped)
                break;
        }
        return arr;
    }


    template<typename T>
    T *heapSort(T *arr, int size) {
        // Budujemy kopiec (heapSortHelper) od końca tablicy
        for (int i = size / 2 - 1; i >= 0; --i)
            heapSortHelper(arr, size, i);

        // Sortowanie poprzez pobieranie maksymalnego elementu z kopca i umieszczanie go na końcu tablicy
        for (int i = size - 1; i > 0; --i) {
            swap(arr[0], arr[i]);  // Zamiana korzenia (maksymalnego elementu) z ostatnim elementem tablicy
            heapSortHelper(arr, i, 0);  // Przywracanie właściwości kopca w podtablicy [0, i-1]
        }

        // Zwracamy posortowaną tablicę
        return arr;
    }

    template<typename T>
    T *quickSort(T *arr, int size) {
        quickSortHelper(arr, 0, size - 1);
        return arr;
    }

    template<typename T>
    bool isSorted(const T arr[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false; // If any element is greater than the next one, array is not sorted
            }
        }
        return true; // If loop completes, array is sorted
    }


private:
    template<typename T>
    void merge(T *arr, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Tworzenie tablic pomocniczych
        T *L = new T[n1];
        T *R = new T[n2];

        // Kopiowanie danych do tablic pomocniczych
        for (int i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[middle + 1 + j];

        // Scalanie tablic pomocniczych
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                ++i;
            } else {
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }

        // Kopiowanie pozostałych elementów z L (jeśli takie są)
        while (i < n1) {
            arr[k] = L[i];
            ++i;
            ++k;
        }

        // Kopiowanie pozostałych elementów z R (jeśli takie są)
        while (j < n2) {
            arr[k] = R[j];
            ++j;
            ++k;
        }

        // Zwolnienie pamięci zaalokowanej dynamicznie
        delete[] L;
        delete[] R;
    }

    template<typename T>
    void mergeSortHelper(T *arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            // Sortowanie lewej i prawej połowy
            mergeSortHelper(arr, left, middle);
            mergeSortHelper(arr, middle + 1, right);

            // Scalanie posortowanych połówek
            merge(arr, left, middle, right);
        }
    }


    template<typename T>
    void heapSortHelper(T arr[], int size, int index) {
        int largest = index;  // Inicjalizujemy największy element jako korzeń
        int left = 2 * index + 1;  // Indeks lewego dziecka w kopcu
        int right = 2 * index + 2;  // Indeks prawego dziecka w kopcu

        // Jeśli lewe dziecko jest większe od korzenia
        if (left < size && arr[left] > arr[largest])
            largest = left;

        // Jeśli prawe dziecko jest większe od największego dotychczas elementu
        if (right < size && arr[right] > arr[largest])
            largest = right;

        // Jeśli największy element nie jest korzeniem
        if (largest != index) {
            swap(arr[index], arr[largest]);

            // Rekurencyjnie wywołujemy heapSortHelper na nowym największym elemencie
            heapSortHelper(arr, size, largest);
        }
    }

    template<typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    int partition(T *arr, int low, int high) {
        // Wybierz środkowy element jako pivot
        int middle = low + (high - low) / 2;
        swap(arr[middle], arr[high]);

        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }


    template<typename T>
    void quickSortHelper(T *arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSortHelper(arr, low, pi - 1);
            quickSortHelper(arr, pi + 1, high);
        }
    }

    template<typename T>
    int binarySearch(T arr[], T item, int low, int high) {
        if (high <= low)
            return (item > arr[low]) ? (low + 1) : low;

        int mid = (low + high) / 2;

        if (item == arr[mid])
            return mid + 1;

        if (item > arr[mid])
            return binarySearch(arr, item, mid + 1, high);

        return binarySearch(arr, item, low, mid - 1);
    }

};

#endif //AIZO_SORTOWANIE_ALGORITHMS_H
