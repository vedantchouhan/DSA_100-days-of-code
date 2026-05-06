#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    heap[heapSize++] = meetings[0].end;

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= heap[0]) {
            heap[0] = meetings[i].end;
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[heapSize] = meetings[i].end;
            heapifyUp(heap, heapSize);
            heapSize++;
        }

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    printf("%d", maxRooms);

    return 0;
}