#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create list
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Rotate list right by k
struct node* rotateRight(struct node *head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct node *temp = head;
    int n = 1;

    // Find length and last node
    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    // Effective rotation
    k = k % n;

    // Move to (n - k)th node
    int steps = n - k;
    struct node *newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct node *newHead = newTail->next;

    // Break the loop
    newTail->next = NULL;

    return newHead;
}

// Display list
void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct node *head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}