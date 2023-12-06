#include<stdio.h>

void bubbleSort(int size, int arr[size]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i-1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// for(int i=1;i<size;i++){
// for(int j=0;j<size-i;j++)


int main() {
    int size;
    printf("Enter the size:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(size, arr);

    printf("Sorted elements through bubble sort method are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
