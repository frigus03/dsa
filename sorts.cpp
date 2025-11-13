#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/**
 * Helper function to print an array
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Helper function to copy an array (avoids sorting the original QOC data)
 */
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// -----------------------------------------------------------------
// TASK 1: INSERTION SORT
// -----------------------------------------------------------------
void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        // Move elements of A[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

// -----------------------------------------------------------------
// TASK 2: SELECTION SORT
// -----------------------------------------------------------------
void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum element is the first
        int minIndex = i;

        // Find the minimum element in unsorted array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = A[minIndex];
            A[minIndex] = A[i];
            A[i] = temp;
        }
    }
}

// -----------------------------------------------------------------
// TASK 3: MERGE SORT
// -----------------------------------------------------------------

/**
 * Merge function for Merge Sort
 */
void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    // Using dynamic allocation as 'vector' is not allowed
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // Merge the temporary arrays back into A[left...right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    // Clean up dynamic memory
    delete[] L;
    delete[] R;
}

/**
 * Main MergeSort function
 */
void mergeSort(int A[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        // Merge the sorted halves
        merge(A, left, mid, right);
    }
}

/**
 * QOC Insertion Sort
 * Counts comparisons and data shifts.
 */
void insertionSort_QOC(int A[], int n, long long& comparisons, long long& shifts) {
    comparisons = 0;
    shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++; // Count the comparison A[j] > key
            if (A[j] > key) {
                A[j + 1] = A[j];
                shifts++;     // Count the shift
                j = j - 1;
            } else {
                break; // Element is in correct position
            }
        }
        A[j + 1] = key;
        shifts++; // Count the final placement as a data movement/shift
    }
}

/**
 * QOC Selection Sort
 * Counts comparisons and swaps.
 */
void selectionSort_QOC(int A[], int n, long long& comparisons, long long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Count the comparison
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        if (minIndex != i) {
            int temp = A[minIndex];
            A[minIndex] = A[i];
            A[i] = temp;
            swaps++; // Count one swap
        }
    }
}

/**
 * QOC Merge function
 * Counts comparisons and data movements (copies).
 */
void merge_QOC(int A[], int left, int mid, int right, long long& comparisons, long long& movements) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
        movements++; // Count copy to temp array
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
        movements++; // Count copy to temp array
    }

    int i = 0, j = 0, k = left;

    // Merge temp arrays back
    while (i < n1 && j < n2) {
        comparisons++; // Count the comparison
        if (L[i] <= R[j]) {
            A[k] = L[i];
            movements++; // Count copy back to main array
            i++;
        } else {
            A[k] = R[j];
            movements++; // Count copy back to main array
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        A[k] = L[i];
        movements++;
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        movements++;
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

/**
 * QOC MergeSort recursive function
 */
void mergeSort_QOC_Recursive(int A[], int left, int right, long long& comparisons, long long& movements) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort_QOC_Recursive(A, left, mid, comparisons, movements);
        mergeSort_QOC_Recursive(A, mid + 1, right, comparisons, movements);
        merge_QOC(A, left, mid, right, comparisons, movements);
    }
}

/**
 * Wrapper for QOC Merge Sort to initialize counters
 */
void mergeSort_QOC_Wrapper(int A[], int n, long long& comparisons, long long& movements) {
    comparisons = 0;
    movements = 0;
    mergeSort_QOC_Recursive(A, 0, n - 1, comparisons, movements);
}

/**
 * Helper function to run and print the full QOC analysis for a given dataset
 */
void runQOCTest(const char* setName, int dataSet[], int size) {
    cout << "\n-------------------------------------------------" << endl;
    cout << "--- Analysis for " << setName << " ---" << endl;
    cout << "-------------------------------------------------" << endl;

    // Create a temp array to be sorted, so we don't destroy the original
    int* tempArr = new int[size];

    long long comparisons, movements;
    clock_t startTime, endTime;
    double cpuTimeElapsed;

    // --- Insertion Sort ---
    copyArray(dataSet, tempArr, size);
    startTime = clock();
    insertionSort_QOC(tempArr, size, comparisons, movements);
    endTime = clock();
    cpuTimeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    cout << "Insertion Sort:" << endl;
    cout << "  Time Taken:   " << setprecision(10) << fixed << cpuTimeElapsed << " seconds" << endl;
    cout << "  Comparisons:  " << comparisons << endl;
    cout << "  Shifts:       " << movements << endl;

    // --- Selection Sort ---
    copyArray(dataSet, tempArr, size);
    startTime = clock();
    selectionSort_QOC(tempArr, size, comparisons, movements);
    endTime = clock();
    cpuTimeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    cout << "\nSelection Sort:" << endl;
    cout << "  Time Taken:   " << setprecision(10) << fixed << cpuTimeElapsed << " seconds" << endl;
    cout << "  Comparisons:  " << comparisons << endl;
    cout << "  Swaps:        " << movements << endl;

    // --- Merge Sort ---
    copyArray(dataSet, tempArr, size);
    startTime = clock();
    mergeSort_QOC_Wrapper(tempArr, size, comparisons, movements);
    endTime = clock();
    cpuTimeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    cout << "\nMerge Sort:" << endl;
    cout << "  Time Taken:   " << setprecision(10) << fixed << cpuTimeElapsed << " seconds" << endl;
    cout << "  Comparisons:  " << comparisons << endl;
    cout << "  Movements:    " << movements << endl;

    delete[] tempArr; // Clean up dynamic memory
}

int main() {

    // --- Task 1: Implement Insertion Sort ---
    int task1Data[] = {23, 87, 45, 12, 67, 34, 90, 56, 78, 11};
    int n1 = sizeof(task1Data) / sizeof(task1Data[0]);
    cout << "\n--- Task 1: Insertion Sort ---" << endl;
    cout << "Original array: ";
    printArray(task1Data, n1);
    insertionSort(task1Data, n1);
    cout << "Sorted array:   ";
    printArray(task1Data, n1);

    // --- Task 2: Implement Selection Sort ---
    int task2Data[] = {12, 23, 34, 45, 56, 67, 78, 87, 90, 99};
    int n2 = sizeof(task2Data) / sizeof(task2Data[0]);
    cout << "\n--- Task 2: Selection Sort ---" << endl;
    cout << "Original array: ";
    printArray(task2Data, n2);
    selectionSort(task2Data, n2);
    cout << "Sorted array:   ";
    printArray(task2Data, n2);
    cout << "(Note: Array was already sorted, so no visible change.)" << endl;

    // --- Task 3: Implement Merge Sort ---
    int task3Data[] = {13, 62, 34, 45, 16, 76, 38, 57, 9, 29}; // (Corrected 09 to 9)
    int n3 = sizeof(task3Data) / sizeof(task3Data[0]);
    cout << "\n--- Task 3: Merge Sort ---" << endl;
    cout << "Original array: ";
    printArray(task3Data, n3);
    mergeSort(task3Data, 0, n3 - 1);
    cout << "Sorted array:   ";
    printArray(task3Data, n3);

    return 0;
}
