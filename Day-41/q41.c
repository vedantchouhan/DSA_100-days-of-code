#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Front and Rear pointers
struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct node *temp = front;
    printf("%d\n", front->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[5];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "ENQ") == 0) {
            scanf("%d", &x);
            enqueue(x);
        } else if (strcmp(op, "DEQ") == 0) {
            dequeue();
        }
    }

    return 0;
}