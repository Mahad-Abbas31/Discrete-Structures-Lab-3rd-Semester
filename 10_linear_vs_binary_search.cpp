#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    // Linear search (works on unsorted array)
    auto startLinear = high_resolution_clock::now();
    int linearResult = linearSearch(arr, n, key);
    auto endLinear = high_resolution_clock::now();
    auto linearDuration = duration_cast<nanoseconds>(endLinear - startLinear).count();

    // Binary search requires a sorted array
    int sortedArr[n];
    copy(arr, arr + n, sortedArr);
    sort(sortedArr, sortedArr + n);

    auto startBinary = high_resolution_clock::now();
    int binaryResult = binarySearch(sortedArr, n, key);
    auto endBinary = high_resolution_clock::now();
    auto binaryDuration = duration_cast<nanoseconds>(endBinary - startBinary).count();

    cout << "\n--- Linear Search ---" << endl;
    if (linearResult != -1)
        cout << "Found at index " << linearResult << " (unsorted array)" << endl;
    else
        cout << "Element not found." << endl;
    cout << "Time taken: " << linearDuration << " ns" << endl;

    cout << "\n--- Binary Search ---" << endl;
    if (binaryResult != -1)
        cout << "Found at index " << binaryResult << " (sorted array)" << endl;
    else
        cout << "Element not found." << endl;
    cout << "Time taken: " << binaryDuration << " ns" << endl;

    cout << "\nNote: For small inputs, timing differences may not be significant."
         << " Binary search generally outperforms linear search on larger, sorted datasets"
         << " because it has O(log n) complexity compared to linear search's O(n)." << endl;

    return 0;
}
