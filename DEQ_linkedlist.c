#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void enqueue_front(node** front, node** rear, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Queue overflow\n");
        return;
    }
    new_node->data = data;
    new_node->next = *front;
    if (*front == NULL) {
        *front = *rear = new_node;
        return;
    }
    *front = new_node;
}

void enqueue_rear(node** front, node** rear, int data) {
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

int dequeue_front(node** front, node** rear) {
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

int dequeue_rear(node** front, node** rear) {
    if (*rear == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = (*rear)->data;
    if (*front == *rear) {
        free(*rear);
        *front = *rear = NULL;
        return data;
    }
    node* temp = *front;
    while (temp->next != *rear) {
        temp = temp->next;
    }
    temp->next = NULL;
    free(*rear);
    *rear = temp;
    return data;    
}

int peek(node* front) {
   if (front == NULL) {
      printf("Queue is empty\n");
      return -1; 
   } else {
      return front->data; 
   }  
}

int main() {
   node* front = NULL; 
   node* rear  = NULL;

   enqueue_front(&front, &rear, 1);
   enqueue_front(&front, &rear, 2);
   enqueue_rear(&front, &rear, 3);
   enqueue_rear(&front, &rear, 4);
   enqueue_rear(&front, &rear, 5);

   // Dequeue 2 items
   printf("%d\n", dequeue_front(&front, &rear));
   printf("%d\n", dequeue_rear(&front, &rear));

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
