#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for stack
struct node {
    int data;
    struct node* next;
};

// Push operation
void push(struct node** top, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = *top;
    *top = newnode;
}

// Pop operation
int pop(struct node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {
        // If operand
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        // If operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

// Main function
int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    // Remove newline character
    exp[strcspn(exp, "\n")] = 0;

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}