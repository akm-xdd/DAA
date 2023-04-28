#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random_partition(int arr[], int left, int right) {
    int random_index = left + rand() % (right - left + 1);
    swap(arr[random_index], arr[right]);
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

int randomized_select(int arr[], int left, int right, int k) {
    if (left == right) return arr[left];
    int pivot_index = random_partition(arr, left, right);
    int rank = pivot_index - left + 1;
    if (k == rank) return arr[pivot_index];
    else if (k < rank) return randomized_select(arr, left, pivot_index-1, k);
    else return randomized_select(arr, pivot_index+1, right, k-rank);
}

int main() {
    int arr[] = {3, 7, 9, 2, 4, 6, 1, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    srand(time(NULL));
    int kth_smallest = randomized_select(arr, 0, n-1, k);
    cout << "The " << k << "th smallest element is: " << kth_smallest << endl;
    return 0;
}
