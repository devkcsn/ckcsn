#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int coef;
    int exp;
}poly;

typedef struct Node {
    poly polynomial;
    struct Node* nextLink;
} Node;

Node* getNode(int coef, int exp) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp != NULL) {
        temp->polynomial.coef = coef;
        temp->polynomial.exp = exp;
        temp->nextLink = NULL;
    }
    return temp;
}

int main()
{ int term,coef,exp;
printf("Number of terms in the expressions: ");
scanf("%d" , &term);
printf("Enter the items of the expression \n");
for(int i=0 ; i<term; i++){
printf("Enter the coefficient of the expression with sign: ");
scanf("%d" , &coef);
printf("Enter the exponent of the expression: ");
scanf("%d" , &exp);
getNode(coef,exp);}




return 0;
}