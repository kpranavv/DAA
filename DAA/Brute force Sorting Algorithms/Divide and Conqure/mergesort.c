#include<stdio.h>

void merge(int start, int arr[], int end, int mid, int *total_compare) {
    // create a temp size of arr
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // create a temp array
    int a1[n1];
    int a2[n2];

    for(int i = 0; i < n1; i++) {
        a1[i] = arr[start + i];
    }

    for(int i = 0; i < n2; i++) {
        a2[i] = arr[mid + 1 + i];
    }

    // creating pointers
    int i = 0;
    int j = 0;
    int k = start;

    while(i < n1 && j < n2) {
        if(a1[i] <= a2[j]) {
            arr[k] = a1[i];
            i++;
        } else {
            arr[k] = a2[j];
            j++;
        }
        k++;
        (*total_compare)++;
    }

    while(i < n1) {
        arr[k] = a1[i];
        k++;
        i++;
    }

    while(j < n2) {
        arr[k] = a2[j];
        k++;
        j++;
    }
}

void mergesort(int arr[], int size, int start, int end, int *total_compare) {
    if(start < end) {
        int mid = start + (end - start) / 2; 
        mergesort(arr, size, start, mid, total_compare);
        mergesort(arr, size, mid + 1, end, total_compare);
        merge(start, arr, end, mid, total_compare);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    if(size == 0) {
        printf("-1\n");
        return 0;
    }

    int arr[size];

    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int total_compare = 0;
    mergesort(arr, size, 0, size - 1, &total_compare);

    if (size % 2 == 1) {
        total_compare--;
    }

    printf("%d\n", total_compare);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
