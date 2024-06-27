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

    int n, data;

    do {
        printf("Enter an element to be pushed: ");
        scanf("%d", &data);
        push(&top, data);

        printf("\nDo you want to add more elements? Press 1 for Yes, 0 for No: ");
        scanf("%d", &n);
    } while (n != 0);

    while (1) {
        printf("\nPress 1 to pop an element from the stack\nPress 2 to exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int popped_element = pop(&top);
            if (popped_element != -1) {
                printf("Popped element: %d\n", popped_element);
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Print all elements in stack
    printf("\nElements in stack: ");
    
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }

    return 0;
}
