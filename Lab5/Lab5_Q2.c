#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct Stack{
    struct node* head;
    unsigned int size;
}Stack;

//Stack ADT
void print_stack(Stack* s);
void print_stack_reverse(Stack* s);
void push(Stack* s, char val);
unsigned int count(Stack *s);
void pop(Stack *s);
char top(Stack *s);

int main(){
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];

    scanf("%s",temp);
    for(int i=0;i<50;i++){
        if(temp[i]=='\0')
            break;
        push(s, temp[i]);
    }
    print_stack_reverse(s);
    pop(s);
    scanf("%s",temp);
    for(int i=0;i<50;i++){
        if(temp[i]=='\0')
            break;
        push(s, temp[i]);
    }
    print_stack_reverse(s);
    
    return 0;
}
void print_stack_reverse_helper(node* current);

void print_stack(Stack* s) {
    node* current = s->head;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");
}
//Printing elements from STACK

void print_stack_reverse(Stack* s) {
    if (s->head == NULL) {
        return;
    }
    print_stack_reverse_helper(s->head);
    printf("\n");
}
//Printing same stack but in reverse order

void print_stack_reverse_helper(node* current) {
    if (current == NULL) {
        return;
    }
    print_stack_reverse_helper(current->next);
    printf("%c", current->data);
}

void push(Stack* s, char val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = s->head;
    s->head = new_node;
    s->size++;
}
//pushing elements to stack

unsigned int count(Stack* s) {
    return s->size;
}
//Checks elements present in stack

void pop(Stack* s) {
    if (s->head == NULL) {
        return;
    }
    node* temp = s->head;
    s->head = s->head->next;
    free(temp);
    s->size--;
}
//Popping element out of stack

char top(Stack* s) {
    if (s->head == NULL) {
        return '\0'; // Return null character for empty stack
    }
    return s->head->data;
}
//Returns the value of the element at the top of the stack without removing it