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

// Delete first occurrence of key
struct node* deleteKey(struct node *head, int key) {
    struct node *temp = head, *prev = NULL;

    // Case 1: key at head
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: search in rest
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: key not found
    if(temp == NULL)
        return head;

    // Delete node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct node *head) {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct node *head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    display(head);

    return 0;
}