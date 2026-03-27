#include <stdio.h>
#include <stdlib.h>

// -------- Queue (Array Implementation) --------
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// -------- Stack (Array Implementation) --------
int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

// -------- Reverse Queue using Stack --------
void reverseQueue() {
    // Step 1: Push all queue elements into stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Pop from stack back to queue
    while (top != -1) {
        enqueue(pop());
    }
}

// -------- Main --------
int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue();

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}