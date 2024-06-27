#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void enqueue(node** front, node** rear, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Queue overflow\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (*rear == NULL) {
        *front = *rear = new_node;
        return;
    }
    (*rear)->next = new_node;
    *rear = new_node;
}

int dequeue(node** front, node** rear) {
    if (*front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    node* temp = *front;
    int data = temp->data;
    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
    }
    free(temp);
    return data;
}

int peek(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

int main() {
    node* front = NULL;
    node* rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 5);

    // Dequeue 2 items
    printf("%d\n", dequeue(&front, &rear));
    printf("%d\n", dequeue(&front, &rear));

    // Peek the front of the queue
    int frontItem = peek(front);
    if (frontItem != -1) {
        printf("Front item in the queue: %d\n", frontItem);
    } else {
        printf("Queue is empty\n");
        return 0;
    }

    // Print all elements in queue
    printf("Elements in queue: ");
    
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }

    return 0;
}
