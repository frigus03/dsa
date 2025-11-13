#include <iostream>

#include <ctime>      // For clock()

#include <iomanip>    // For setprecision()

#include <algorithm>  // For std::sort



using namespace std;



// Linear Search function

int linearSearch(int arr[], int size, int target) {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == target) {

            return i;

        }

    }

    return -1;

}



// Binary Search function (same as above)

int binarySearch(int arr[], int size, int target) {

    int left = 0;

    int right = size - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {

            return mid;

        } else if (arr[mid] < target) {

            left = mid + 1;

        } else {

            right = mid - 1;

        }

    }

    return -1;

}



int main() {

    const int SIZE = 20000000; // 20 million elements



    // Dynamically allocate a large array

    int* numbers = new int[SIZE];



    cout << "Generating a sorted array with " << SIZE << " elements..." << endl;

    for (int i = 0; i < SIZE; ++i) {

        numbers[i] = i;

    }



    // Target to find (worst case for linear search)

    int target = SIZE - 1;



    clock_t startTime, endTime;

    double cpuTimeElapsed;



    // --- Time Linear Search ---

    cout << "Starting Linear Search for target " << target << "..." << endl;



    startTime = clock();

    int linearResult = linearSearch(numbers, SIZE, target);

    endTime = clock();



    cpuTimeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;



    cout << "Linear Search Result: Index " << linearResult << endl;

    cout << "Linear Search took: " << setprecision(6) << fixed << cpuTimeElapsed << " seconds" << endl;

    cout << "--------------------------------" << endl;



    // --- Time Binary Search ---

    // The array is already sorted, which is a prerequisite

    cout << "Starting Binary Search for target " << target << "..." << endl;



    startTime = clock();

    int binaryResult = binarySearch(numbers, SIZE, target);

    endTime = clock();



    cpuTimeElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;



    cout << "Binary Search Result: Index " << binaryResult << endl;

    cout << "Binary Search took: " << setprecision(6) << fixed << cpuTimeElapsed << " seconds" << endl;



    // Free the dynamically allocated memory

    delete[] numbers;

    numbers = nullptr;



    return 0;

}