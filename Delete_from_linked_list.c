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

void deleteFromStart(Node** h) {
    if (*h == NULL) {
        return;  // Empty list
    }

    Node* temp = *h;
    *h = (*h)->nextLink;
    free(temp);
}

void deleteFromEnd(Node** h) {
    if (*h == NULL) {
        return;  // Empty list
    }

    if ((*h)->nextLink == NULL) {
        free(*h);
        *h = NULL;
        return;
    }

    Node* prev = NULL, *current = *h;

    while (current->nextLink != NULL) {
        prev = current;
        current = current->nextLink;
    }

    free(current);
    prev->nextLink = NULL;
}

void deleteFromMiddle(Node** h, int position) {
    if (*h == NULL) {
        return;  // Empty list
    }

    if (position == 1) {  // Delete from start
        deleteFromStart(h);
        return;
    }

    int i;
    Node* prev = *h, *current = (*h)->nextLink;

    for (i = 2; i < position && current != NULL; i++) {
        prev = current;
        current = current->nextLink;
    }

    if (current == NULL && i < position) {  // Position is greater than the number of nodes in the list
        return;
    }

    prev->nextLink = current->nextLink;
    free(current);
}

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    display(head);

    deleteFromStart(&head);

    display(head);

    deleteFromMiddle(&head, 2);

    display(head);

    deleteFromEnd(&head);

    display(head);

    // Free the memory allocated for the linked list when done
    while (head != NULL) {
        Node* temp = head;
        head = head->nextLink;
        free(temp);
    }

    return 0;
}
