#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct curr_node *next;
};

int main(){
    struct Node *curr_node = malloc(sizeof(struct Node));
    //pointer
    struct Node *nodeptr = curr_node;
    for(int i = 1; i <= 100; i++){
        struct Node *next_node = malloc(sizeof(struct Node));
        nodeptr->data = i;
        nodeptr->next = next_node;

        nodeptr = next_node;
    }

    nodeptr = curr_node;

    for(int i = 1; i <= 100; i++){
        printf("%d\n", nodeptr->data);
        nodeptr = nodeptr->next;
    }
}