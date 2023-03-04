#include <stdio.h>
void bubble_sort(int arr[], int n) ;
int main() {
    int arr[] = {1, 2, 3, 4, 199, 12, 41, 2000, 21, 314, 0, 141, 13333, 22, 1435};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubble_sort(arr, n);

    printf("\nAfter sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}