#include <stdio.h>

int main() {
    int n, key;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    int left = 0, right = n - 1, mid;
    int found = -1;

    while(left <= right) {
        mid = (left + right) / 2;

        if(arr[mid] == key) {
            found = mid;
            break;
        } else if(arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if(found != -1)
        printf("%d", found);
    else
        printf("-1");

    return 0;
}