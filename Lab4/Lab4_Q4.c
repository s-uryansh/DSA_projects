#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct node {
    int num;
    struct node *preptr;
    struct node *nextptr;
} *stnode, *ennode;

int main() {
    int n;
    stnode = NULL;
    ennode = NULL;
    scanf("%d", &n);    // Input the number of nodes


    stnode=malloc(sizeof(struct node)); //allocating memory to head stnode and ennode
    ennode=malloc(sizeof(struct node));
    
    scanf("%d" , &stnode->num);
    ennode = stnode; //assigning ennode to head
    stnode->preptr=NULL;
    
    for(int i=1 ; i< n ; i++){
        struct node* ptr2=malloc(sizeof(struct node));
        scanf("%d" , &ptr2->num);
        ptr2->preptr=ennode;
        ennode=ptr2;
    }
    
    ennode->nextptr=NULL;
    struct node* ptr= ennode;  //ptr to traverse the linked list
    //PRINTING LINKED LIST
    while(ptr!= NULL){
        printf("%d ", ptr->num);
        ptr = ptr->preptr;
    }

    return 0;
}
