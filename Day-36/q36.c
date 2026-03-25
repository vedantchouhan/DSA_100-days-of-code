#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (front == NULL) {
        front = rear = newnode;
        rear->next = front;
    } else {
        newnode->next = front;
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue
void dequeue() {
    if (front == NULL) return;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

// Display
void display() {
    if (front == NULL) return;

    struct node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}