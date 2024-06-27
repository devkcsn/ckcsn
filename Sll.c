/*............ Single Link List ..............*/
#include <stdio.h>
#include <stdlib.h>

typedef enum { EMPTY, MEMORYFAILED, SUCCESS, NOTFOUND }FLAGS;

typedef struct Node Node; 
struct Node {
   	int data;
   	Node * nextLink;
};
//user defined functions.....................
Node * getNode(int);
FLAGS append(Node **, int);
FLAGS prepend(Node **h, int item);
FLAGS insertAfter(int item,int afterItem);
void display(Node *);
FLAGS removeItem(Node **h, int item);
FLAGS removeFirst(Node **h);
FLAGS removeLast(Node **h);
void showMessage(FLAGS);
int menu();

int main(){
	Node * head = NULL; //Set SLL to empty…
	FLAGS status;
	int choice,data;
	while(1){
		choice = menu();
		switch(choice){
			case 1:
				printf("Ente any number to be appended : ");
				scanf("%d",&data);
				status = append(&head,data);
				showMessage(status);
				break;
			case 2:
				break;
			case 4:
				showMessage(removeFirst(&head));
				break;
			case 9:
				display(head);
				break;
			case 0: return 0;
			default:puts("Wrong operation code....");		
		}
		puts("\nPress Enter Key to Continue");
		getchar();
	}	
	return 0;
}

Node * getNode(int item){
	Node * temp;
	//[1] create node
	temp = (Node *) malloc(sizeof(Node));
	//[2] if node gets created then set all the fields…
	if(temp != NULL){
		temp -> data = item; 
		temp -> nextLink = NULL;
	}
	return temp;
}

FLAGS append(Node **h, int item){
	Node * temp, *tr;
	//[1]create a node & set all the fields
	temp = getNode(item);
	if(temp == NULL) return MEMORYFAILED;
	//[2]If SLL is empty then the new node becomed the first node
	if(*h == NULL) *h = temp;
	else{
	//[3] Traverse in SLL till we reach to the last node	
		for(tr = *h; tr ->nextLink != NULL; tr = tr -> nextLink );
	//[4] Atach the new node with the last node.	
		 tr -> nextLink = temp;
	} 
	return SUCCESS;
}
	
FLAGS prepend(Node **h, int item){
	Node * temp, *tr;
	//[1]create a node & set all the fields
	temp = getNode(item);
	if(temp ==NULL) return 0;
	//[2]If SLL is empty then the new node becomed the first node
	if(*h == NULL) *h = temp;
	else{
	//[3] Atach the first node with the new node.
		temp->nextLink = *h;
	//[4] Atach the new node with the last node.	
		 *h = temp;
	} 
	return 1;
}

void display(Node *tr){
	if(tr == NULL){
		printf("SLL is Empty….");
		return;
	}
	while(tr != NULL){
		printf("%d  ", tr -> data);
		tr = tr -> nextLink;
	}
}

FLAGS removeItem(Node **h, int item){
	Node *p, *tr;
	
	if(*h == NULL){ return EMPTY; }
	
	//[1] Traverse in SLL till we find the data to be removed	
	for(p=NULL,tr = *h; tr != NULL && tr ->data != item; p=tr, tr -> nextLink );
	
	//[2] Item not found..........
	if(tr == NULL){ return NOTFOUND; }
	
	//[3]Item found in the First Node......
	if(p == NULL){ *h = tr -> nextLink; }
	else   //Item is found in the middle/last node............
	{	p -> nextLink = tr -> nextLink; }
	//deallocate the Node
	free(tr);
	return SUCCESS;
}

FLAGS removeFirst(Node **h){
	//[1] SLL is empty............
	if(*h == NULL){ return EMPTY; }
	Node *temp = *h;
	*h = temp -> nextLink;
	free(temp);
	return SUCCESS;
}

void showMessage(FLAGS status){
	switch(status){
		case EMPTY:	
			puts("\nData Structure is empty");
			break;
		case MEMORYFAILED:
			puts("\nMemory FAiled");
			break;
		case SUCCESS:
			puts("\nOperation Success");
			break;
		case NOTFOUND:
			puts("\nData Not Found");
			break;
		default:
			puts("\nWrong Status");		
	}
}

int menu(){
	int choice;
	system("cls");
	puts("----------------   M A I N    M E N U   -----------");
	puts("APPEND : 1");
	puts("PREPENT: 2");
	puts("REMOVE : 3");
	puts("REMOVE FIRST : 4");
	puts("DISPLAY : 9");
	puts("EXIT : 0");
	printf("Enter the Operation Code : ");
	scanf("%d",&choice);
	return choice;
}


/*
p = NULL;
tr = *h;
while(tr != NULL && tr ->item != item){
	p = tr;
	tr -> nextLink;
}		
*/