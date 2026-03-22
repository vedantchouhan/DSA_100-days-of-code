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

// Count occurrences
int countOccurrences(struct node *head, int key) {
    int count = 0;
    struct node *temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct node *head = createList(n);

    scanf("%d", &key);

    int result = countOccurrences(head, key);
    printf("%d", result);

    return 0;
}