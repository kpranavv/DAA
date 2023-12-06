#include <stdio.h>

// Function to perform heapify on a subtree rooted at index i in array arr of size n
void heapify(int arr[], int n, int i, int *swap_count) {
    int largest = i;   // Initialize the largest as the root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        // Swap the largest with the root
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        (*swap_count)++;  // Increment the swap count

        // Recursively heapify the affected subtree
        heapify(arr, n, largest, swap_count);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n, int *swap_count) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swap_count);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        (*swap_count)++;  // Increment the swap count

        // Heapify the reduced heap
        heapify(arr, i, 0, swap_count);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    if (size == 0) {
        printf("-1\n");
        return 0;
    }

    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int swap_count = 0;
    heapSort(arr, size, &swap_count);
    printf("%d\n", swap_count);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}
