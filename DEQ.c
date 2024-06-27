#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

void initializeDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

bool isEmpty(struct Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

bool isFull(struct Deque *deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void pushFront(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->arr[deque->front] = data;
}

void pushBack(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->arr[deque->rear] = data;
}

int popFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }
    int data = deque->arr[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    return data;
}

int popBack(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }
    int data = deque->arr[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return data;
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    pushBack(&deque, 1);
    pushBack(&deque, 2);
    pushFront(&deque, 3);
    pushFront(&deque, 4);

    printf("Front element: %d\n", deque.arr[deque.front]);
    printf("Rear element: %d\n", deque.arr[deque.rear]);

    popFront(&deque);
    popBack(&deque);

    printf("Remaining elements: ");
    int i = deque.front;
    while (i != deque.rear) {
        printf("%d ", deque.arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");

    return 0;
}