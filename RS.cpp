#include <iostream>
#include <cmath>

using namespace std;

void radix_sort(int arr[], int n) {
    // Find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Count the number of digits in the maximum element
    int num_digits = 0;
    while (max_element > 0) {
        num_digits++;
        max_element /= 10;
    }

    // Initialize count and temp arrays
    int count[10] = {0};
    int temp[n];

    // Perform radix sort for each digit
    for (int digit = 1; digit <= num_digits; digit++) {
        // Count the occurrences of each digit
        for (int i = 0; i < n; i++) {
            int index = (arr[i] / (int)pow(10, digit-1)) % 10;
            count[index]++;
        }

        // Calculate the starting index of each digit
        for (int i = 1; i < 10; i++) {
            count[i] += count[i-1];
        }

        // Move elements to the temp array in sorted order
        for (int i = n-1; i >= 0; i--) {
            int index = (arr[i] / (int)pow(10, digit-1)) % 10;
            temp[count[index]-1] = arr[i];
            count[index]--;
        }

        // Copy the temp array back to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }

        // Reset the count array for the next digit
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);

    radix_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
