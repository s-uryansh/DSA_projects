#include<stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* swapPairs(struct Node* head){
    if(head == NULL || head->next == NULL) return head;
    
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    
    dummy-> next = head;
    struct Node* prev = dummy;
    struct Node* curr = head;
    
    while(curr != NULL && curr -> next!= NULL){
        struct Node* nextNode = curr -> next;
        curr->next = nextNode->next;
        nextNode->next=curr;
        prev-> next = nextNode;
        prev = curr;
        curr = curr->next;
    }
    
    head = dummy->next;
    free(dummy);
    return head;
}

// to swap nodes in linked list


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode-> next = NULL;
    return newNode;
}

//Create a new node

void printlist(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp-> data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate swapping pairs in a linked list
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);    
    int data;
    struct Node* head = NULL;
    struct Node* temp = NULL;
    
    for(int i =0 ; i<n ; i++){
        scanf("%d" , &data);
        struct Node* newNode = createNode(data);
        if(head == NULL){
            head = newNode;
            temp = head;
        }else{
            temp ->next = newNode;
            temp = temp->next;
        }
    }
    head = swapPairs(head);
    
    
    printlist(head);
    return 0;
}
