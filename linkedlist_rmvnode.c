#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *newNode(int data){
    Node *nn = malloc(sizeof(Node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

int main(int argc, char **argv){
    if(argc != 3) return -1;
    int size = atoi(argv[1]);
    int n = atoi(argv[2]);
    Node *head = NULL;
    head = newNode(1);
    Node *insert = head;

    for(int i = 2; i <=size + 1; ++i){
        insert->next = newNode(i);
        insert = insert->next;
    }

  	Node *walk = head;
	while (walk->next != NULL) {
		printf("%d ", walk->data);
		walk = walk->next;
	}

    printf("\n");

    Node *curr = head;
    int count = 1;
    while(count < size - n){
        curr = curr->next;
        count++;
    }

    curr->next = curr->next->next;

    walk = head;
    	while (walk->next != NULL) {
		printf("%d ", walk->data);
		walk = walk->next;
	}


	printf("\n");
	// clean up after ourselves
	Node *toFree = head;
	while (toFree) {
		Node *next = toFree->next;
		free(toFree);
		toFree = next;
	}
	return 0;  
}
