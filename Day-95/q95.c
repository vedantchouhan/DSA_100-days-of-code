#include <stdio.h>
#include <stdlib.h>

void insertionSort(float bucket[], int n) {
    for (int i = 1; i < n; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float buckets[n][n];
    int bucketCount[n];

    for (int i = 0; i < n; i++) {
        bucketCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index][bucketCount[index]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}