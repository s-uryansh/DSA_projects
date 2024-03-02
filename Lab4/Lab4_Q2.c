#include<stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Main function where the execution starts
int main() {
    int n, k;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);
    // Input the number of elements then input k value
    
    if(n==0){
        return 0;
    }
    struct Node* head=malloc(sizeof(struct Node));
    
    struct Node* ptr=head;
    scanf("%d" , &head->data);
    // creating the head pointer and allocating memory + creating a pointer & assigning to head
    for(int i=1 ; i< n ; i++){
        
        struct Node* ptr2 = malloc(sizeof(struct Node));
        scanf("%d" , &ptr2-> data);
        ptr->next=ptr2;
        ptr=ptr2;
    }//creation of linked list
    
    ptr->next=head;
    
    //last pointer pointing to head as it is a circular linked list
    scanf("%d" , &k);
    for(int i =0; i<n-k ; i++){
        head= head->next;
        //moving head to rotate list
    }
    struct Node* tra = head;
    do{
        printf("%d " , tra->data);
        tra=tra->next;
        
    }while(tra!= head);
    //printing list
    return 0; // Indicates successful completion of the program
}

