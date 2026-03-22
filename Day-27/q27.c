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

// Find first common value
int findIntersection(struct node *l1, struct node *l2) {
    struct node *temp1 = l1, *temp2;

    while(temp1 != NULL) {
        temp2 = l2;

        while(temp2 != NULL) {
            if(temp1->data == temp2->data) {
                return temp1->data;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return -1; // No intersection
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node *list1 = createList(n);

    scanf("%d", &m);
    struct node *list2 = createList(m);

    int result = findIntersection(list1, list2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}