#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create circular linked list
struct node* createCLL(int n) {
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

    // Make it circular
    if(temp != NULL)
        temp->next = head;

    return head;
}

// Display circular list
void display(struct node *head) {
    if(head == NULL)
        return;

    struct node *temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = createCLL(n);

    display(head);

    return 0;
}