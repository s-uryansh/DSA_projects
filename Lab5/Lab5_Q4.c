#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct Stack{
    struct node* head;
    unsigned int size;
}Stack;

//Stack ADT
// Use the code from Q2 for below functions
void print_stack(Stack* s);
void print_stack_reverse(Stack* s);
void push(Stack* s, char val);
unsigned int count(Stack *s);
void pop(Stack *s);
char top(Stack *s);

    
typedef struct String{
    unsigned int size;
    char *str;
}String;


void InfixToPostfix(String *infix, String *postfix);

void print_stack_reverse_helper(node* current);
int precedence(char op);

void print_stack(Stack* s) {
    node* current = s->head;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_stack_reverse(Stack* s) {
    if (s->head == NULL) {
        return;
    }
    print_stack_reverse_helper(s->head);
    printf("\n");
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}


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

unsigned int count(Stack* s) {
    return s->size;
}

void pop(Stack* s) {
    if (s->head == NULL) {
        return;
    }
    node* temp = s->head;
    s->head = s->head->next;
    free(temp);
    s->size--;
}

char top(Stack* s) {
    if (s->head == NULL) {
        return '\0'; // Return null character for an empty stack
    }
    return s->head->data;
}
void InfixToPostfix(String* infix, String* postfix) {
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;

    for (unsigned int i = 0; i < infix->size; i++) {
        if (isalnum(infix->str[i])) {
            postfix->str = realloc(postfix->str, (postfix->size + 1) * sizeof(char));
            postfix->str[postfix->size++] = infix->str[i];
        } else if (infix->str[i] == '(') {
            push(stack, '(');
        } else if (infix->str[i] == ')') {
            while (count(stack) > 0 && top(stack) != '(') {
                postfix->str = realloc(postfix->str, (postfix->size + 1) * sizeof(char));
                postfix->str[postfix->size++] = top(stack);
                pop(stack);
            }
            pop(stack); // Discard the '('
        } else {
            while (count(stack) > 0 && precedence(infix->str[i]) <= precedence(top(stack))) {
                postfix->str = realloc(postfix->str, (postfix->size + 1) * sizeof(char));
                postfix->str[postfix->size++] = top(stack);
                pop(stack);
            }
            push(stack, infix->str[i]);
        }
    }

    while (count(stack) > 0) {
        postfix->str = realloc(postfix->str, (postfix->size + 1) * sizeof(char));
        postfix->str[postfix->size++] = top(stack);
        pop(stack);
    }

    // Add null terminator to make it a valid string
    postfix->str = realloc(postfix->str, (postfix->size + 1) * sizeof(char));
    postfix->str[postfix->size] = '\0';

    for (unsigned int i = 0; i < postfix->size; i++) {
        // Check if the current character is an operator and the next is an operand
        if (i > 0 && !isalnum(postfix->str[i - 1]) && isalnum(postfix->str[i])) {
            printf(" ");
        }

        printf("%c", postfix->str[i]);
    }
    printf("\n");
    // Free memory allocated for the stack
    while (stack->head != NULL) {
        pop(stack);
    }
    free(stack);
}



int main(){

    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];

    scanf("%s",temp);
    String *infix = malloc(sizeof(String));
    infix->size = 0;
    // Read the temp into infix structure

    infix->size = strlen(temp);
    infix->str = strdup(temp); // Copy input expression to infix structure
    String *postfix = malloc(sizeof(String));
    postfix->size = 0;
    postfix->str = NULL;
    // Save the postfix expressions in postfix string
    InfixToPostfix(infix, postfix);


    // Free allocated memory
    free(infix->str);
    free(infix);
    free(postfix->str);
    free(postfix);
    printf("%s\n",postfix->str);
    return 0;
}
