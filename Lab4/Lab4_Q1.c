#include<stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteNode(struct Node* head, struct Node* tra){
   struct Node* ctr=head; 
   struct Node* ftr=tra;
   while(ctr->next!=tra){
       ctr=ctr->next;
   }
   ctr->next=tra->next;
   tra->next=NULL;
   free(ftr);
   return ctr;
   
}//To del node
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);

    if(n==0){
        return 0;
    }
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    scanf("%d" , &head->data);
    for(int i=1 ; i<n ; i++){
        struct Node* ptr2=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d" , &ptr2->data);
        ptr->next=ptr2;
        ptr=ptr2;
    }
    //created the head , pointer and link list in end
    
    ptr->next=NULL;
    struct Node* tra=head;
    int arr[n];
    int d=0;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<i;j++){
            
            if(arr[j] == tra->data){
                
                d=1;
                break;
            }else{
                d=0;
            }
        }
        if(d==1){
            tra=deleteNode(head,tra);
        }else if(d==0){
            arr[i]=tra->data;
        }
            tra=tra->next;
        }//del node if it have data if there is no data , data will be added
        struct Node* tra2=head;
        while(tra2!=NULL){
            printf("%d ",tra2->data);
            tra2=tra2->next;
        }//printing list
    

    return 0; // Indicates successful completion of the program
}
