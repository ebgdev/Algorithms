deneme
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} heap;

heap* create_heap(int capacity) {
    heap *h = malloc(sizeof(heap));
    h->data = malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heap_push(heap *h, int value) {
    if (h->size == h->capacity) {
        return;
    }
    h->data[h->size] = value;
    int current = h->size;
    int parent = (current - 1) / 2;
    while (current > 0 && h->data[current] < h->data[parent]) {
        int temp = h->data[current];
        h->data[current] = h->data[parent];
        h->data[parent] = temp;
        current = parent;
        parent = (current - 1) / 2;
    }
    h->size++;
}

int heap_pop(heap *h) {
    if (h->size == 0) {
        return -1;
    }
    int value = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    int current = 0;
    while (1) {
        int left_child = 2 * current + 1;
        int right_child = 2 * current + 2;
        int min_child = current;
        if (left_child < h->size && h->data[left_child] < h->data[min_child]) {
            min_child = left_child;
        }
        if (right_child < h->size && h->data[right_child] < h->data[min_child]) {
            min_child = right_child;
        }
        if (min_child == current) {
            break;
        }
        int temp = h->data[current];
        h->data[current] = h->data[min_child];
        h->data[min_child] = temp;
        current = min_child;
    }
    return value;
}

int main() {
    heap *h = create_heap(10);
    heap_push(h, 5);
    heap_push(h, 2);
    heap_push(h, 7);
    heap_push(h, 3);
    heap_push(h, 6);
    while (h->size > 0) {
        printf("%d ", heap_pop(h));
    }
    printf("\n");
    return 0;
}
