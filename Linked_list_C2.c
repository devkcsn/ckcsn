#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node* nextLink;
};

Node* getNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = item;
        temp->nextLink = NULL;
    }
    return temp;
}

int append(Node** h, int item) {
    Node* temp, *tr;

    temp = getNode(item);
    if (temp == NULL) {
        return 0;  // Memory allocation failed
    }

    if (*h == NULL) {
        *h = temp;
    } else {
        for (tr = *h; tr->nextLink != NULL; tr = tr->nextLink);
        tr->nextLink = temp;
    }
    return 1;  // Success
}

void display(Node* h) {
    Node* current = h;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->nextLink;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int status;

    status = append(&head, 10);
    if (status == 1) {
        puts("Success");
    } else {
        puts("Failed");
    }

    status = append(&head, 20);
    if (status == 1) {
        puts("Success");
    } else {
        puts("Failed");
    }

    status = append(&head, 30);
    if (status == 1) {
        puts("Success");
    } else {
        puts("Failed");
    }

    display(head);
    
    // Don't forget to free the memory allocated for the linked list when you're done with it
    while (head != NULL) {
        Node* temp = head;
        head = head->nextLink;
        free(temp);
    }

    return 0;
}
