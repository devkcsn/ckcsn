#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node*nextLink;
};
int main(){

    Node *head;
    head = (Node* ) malloc(sizeof(Node));
    head -> data = 10;
    head -> nextLink = NULL;

    head -> nextLink = (Node* ) malloc(sizeof(Node));
    head -> nextLink -> data = 20;
    head -> nextLink -> nextLink = NULL;

    
    Node *tr = head;
    
    while(tr!= NULL){
    printf("%d " ,tr -> data);
    tr = tr -> nextLink;
    }
return 0;

}