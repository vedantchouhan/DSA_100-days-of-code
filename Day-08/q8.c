#include <stdio.h>

int power(int a, int b) {
    if (b == 0)
        return 1;

    int half = power(a, b / 2);

    if (b % 2 == 0)
        return half * half;
    else
        return a * half * half;
}

int main() {
    int a, b;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("Result: %d\n", power(a, b));

    return 0;
}