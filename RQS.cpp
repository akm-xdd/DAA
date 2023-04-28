#include <iostream>
#include <random>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomPartition(int arr[], int low, int high, int& comparisons) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    int randomIndex = dis(gen);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high, comparisons);
}

void quickSort(int arr[], int low, int high, int& comparisons) {
    if (low < high) {
        int pivotIndex = randomPartition(arr, low, high, comparisons);
        quickSort(arr, low, pivotIndex - 1, comparisons);
        quickSort(arr, pivotIndex + 1, high, comparisons);
    }
}

int main() {
    int arr[100];
    int comparisons = 0;

    // Generate random array
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(30, 1000);
    for (int i = 0; i < 100; i++) {
        arr[i] = dis(gen);
    }

    // Print unsorted array
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort array using quicksort
    quickSort(arr, 0, 99, comparisons);

    // Print sorted array
    cout << endl;
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print number of comparisons
    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;
}
