#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 199, 12, 41, 2000, 21, 314, 0, 141, 13333, 22, 1435};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertion_sort(arr, n);

    printf("\nAfter sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
