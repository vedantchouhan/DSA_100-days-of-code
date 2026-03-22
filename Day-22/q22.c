#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create linked list
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

// Function to count nodes
int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = createList(n);

    int result = countNodes(head);
    printf("%d", result);

    return 0;
}