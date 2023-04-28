#include <iostream>
#include <random>

using namespace std;

void merge(int arr[], int l, int m, int r, int &comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r, int &comparisons) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(arr, l, m, comparisons);
    mergeSort(arr, m + 1, r, comparisons);
    merge(arr, l, m, r, comparisons);
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

    // Sort array using Merge Sort
    mergeSort(arr, 0, 99, comparisons);

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
