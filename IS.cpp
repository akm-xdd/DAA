#include <iostream>
#include <random>

using namespace std;

void insertionSort(int arr[], int n, int &comparisons)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[100];
    int comparisons = 0;

    // Generate random array
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(30, 1000);
    for (int i = 0; i < 100; i++)
    {
        arr[i] = dis(gen);
    }

    // Print unsorted array
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort array using insertion sort
    insertionSort(arr, 100, comparisons);
    // Print sorted array
    cout << endl;
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Print number of comparisons
    cout << endl
         << "Number of comparisons: " << comparisons << endl;

    return 0;
}
