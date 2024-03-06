#include<stdio.h>
#include<stdlib.h>

//Define a structure for a node in the queue

struct Node{
    int data;
    struct Node *next;
};

struct Node* front = NULL; // declare a pointer to the front of the queue
struct Node* rear = NULL; // declare a pointer to the rear of the queue

void enqueue(int x);
void dequeue();
void display();

int main(){
    int n, m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        enqueue(m);
    }

    display();

    dequeue();
    display();

    return 0; //return from the main function
}

//Adding elements to queue
void enqueue(int x){
    struct Node *newNode;

    
    newNode = malloc(sizeof(struct Node)); // allocating memory for new node
    newNode->data=x; 
    newNode-> next =NULL;


    if(rear == NULL){
        front = newNode;
        rear = newNode;
    }else{
            rear -> next = newNode;
            rear = newNode;
    }
}

//Removing elements from queue
void dequeue(){
    if(front == NULL){
        
    }else{
        struct Node *temp = front;
        front = front -> next;
        free(temp);
    }
}

//Printing elements of queue
void display(){
    struct Node* temp = front;
    //checking if queue is empty or not
    if(front == NULL && rear == NULL){ 
        printf("Queue is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

