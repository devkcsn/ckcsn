#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push(node** top, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        return;
    }
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

int pop(node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main() {
    node* top = NULL;

    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);

    // Pop 2 items
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));

    // Peek the top of the stack
    int topItem = peek(top);
    if (topItem != -1) {
        printf("Top item on the stack: %d\n", topItem);
    } else {
        printf("Stack is empty\n");
        return 0;
    }

    // Print all elements in stack
    printf("Elements in stack: ");
    
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }

    return 0;
}
