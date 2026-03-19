#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    int start = 0;
    int end = strlen(s) - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            printf("NO");
            return 0;
        }
        start++;
        end--;
    }

    printf("YES");
    return 0;
}