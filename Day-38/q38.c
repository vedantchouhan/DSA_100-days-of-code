#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Check full
int full() {
    return ((rear + 1) % MAX == front);
}

// push_front
void push_front(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// front element
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// back element
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// size
int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

// clear
void clear() {
    front = rear = -1;
}

// reverse
void reverse() {
    if (empty()) return;

    int i = front, j = rear;

    while (i != j && (i + MAX - 1) % MAX != j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

// sort (simple bubble sort)
void sortDeque() {
    int n = size();
    if (n <= 1) return;

    int arr[MAX];
    int idx = 0;

    // copy elements
    for (int i = 0; i < n; i++) {
        arr[i] = deque[(front + i) % MAX];
    }

    // bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    // copy back
    for (int i = 0; i < n; i++) {
        deque[(front + i) % MAX] = arr[i];
    }
}

// display deque
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// MAIN
int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x; scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            int x; scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            get_front();
        }
        else if (strcmp(op, "back") == 0) {
            get_back();
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(op, "clear") == 0) {
            clear();
        }
        else if (strcmp(op, "reverse") == 0) {
            reverse();
        }
        else if (strcmp(op, "sort") == 0) {
            sortDeque();
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}