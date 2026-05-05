#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for(int i = 0; i < n; i++) {
        if(boards[i] > maxTime) return 0;

        if(currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];
        }

        if(painters > k) return 0;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int left = 0, right = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        if(boards[i] > left) left = boards[i];
        right += boards[i];
    }

    while(left <= right) {
        int mid = (left + right) / 2;

        if(isPossible(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}