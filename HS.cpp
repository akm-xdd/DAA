#include <iostream>
#include <random>

using namespace std;

void heapify(int arr[], int n, int i, int &comparisons)
{
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        comparisons++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int &comparisons)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, comparisons);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        comparisons++;

        // call max heapify on the reduced heap
        heapify(arr, i, 0, comparisons);
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

    // Sort array using heap sort
    heapSort(arr, 100, comparisons);

    // Print sorted array
    cout << endl;
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Print number of comparisons
    cout << endl << "Number of comparisons: " << comparisons << endl;

    return 0;
}
