#include <stdio.h>

void swap(int *a, int *b, int *swap_count) {
    if (*a != *b) {  // Check if elements are different before swapping
        int temp = *a;
        *a = *b;
        *b = temp;
        (*swap_count)++;
    }
}

int partition(int arr[], int start, int end, int *compare_count, int *swap_count) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        (*compare_count)++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j], swap_count);
        }
    }

    swap(&arr[i + 1], &arr[end], swap_count);
    return i + 1;
}

void quicksort(int arr[], int start, int end, int *compare_count, int *swap_count) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end, compare_count, swap_count);

        quicksort(arr, start, pivotIndex - 1, compare_count, swap_count);
        quicksort(arr, pivotIndex + 1, end, compare_count, swap_count);
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

    int compare_count = 0;
    int swap_count = 0;
    quicksort(arr, 0, size - 1, &compare_count, &swap_count);
    
    printf("%d\n", compare_count);
    printf("%d\n", swap_count);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}