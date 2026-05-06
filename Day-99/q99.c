#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;
}

int main() {
    int target, n;

    scanf("%d", &target);
    scanf("%d", &n);

    Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(Car), compare);

    double lastTime = 0;
    int fleets = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d", fleets);

    return 0;
}