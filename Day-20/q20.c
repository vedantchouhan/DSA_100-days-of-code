#include <stdio.h>

#define MAX 10000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0, count = 0;

    // Simple frequency array (for range handling)
    int freq[2 * MAX + 1] = {0};
    int offset = MAX;

    // Important: prefix sum 0 seen once
    freq[offset] = 1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        // if prefix seen before → subarray sum = 0
        count += freq[prefix + offset];

        // update frequency
        freq[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}