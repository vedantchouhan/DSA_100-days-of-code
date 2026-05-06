#include <stdio.h>

long long merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    return inversions;
}

long long mergeSort(int arr[], int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid + 1, right);

        inversions += merge(arr, left, mid, right);
    }

    return inversions;
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, 0, n - 1);

    printf("%lld", result);

    return 0;
}