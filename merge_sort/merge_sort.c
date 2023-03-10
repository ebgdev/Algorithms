#include <stdio.h>

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int arr_size) {
    if (arr_size < 2) {
        return;
    }
    
    int mid = arr_size / 2;
    int left[mid], right[arr_size - mid];
    
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    
    for (int i = mid; i < arr_size; i++) {
        right[i - mid] = arr[i];
    }
    
    merge_sort(left, mid);
    merge_sort(right, arr_size - mid);
    merge(arr, left, mid, right, arr_size - mid);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    merge_sort(arr, arr_size);
    
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
