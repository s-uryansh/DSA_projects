#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int ParenMatch(String *par_str);

int main(){
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];
    
    scanf("%s",temp);
    String *par_str = malloc(sizeof(String));
    par_str->size = 0;

    while (temp[par_str->size] != '\0') {
        par_str->size++;
    }

    // Allocate memory for par_str->str and copy characters
    par_str->str = malloc(par_str->size + 1);
    for (int i = 0; i < par_str->size; i++) {
        par_str->str[i] = temp[i];
    }
    par_str->str[par_str->size] = '\0';
    int match = ParenMatch(par_str);
    printf("%d\n", match);


    // Free allocated memory
    free(par_str->str);
    free(par_str);
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

void print_stack_reverse(Stack* s) {
    if (s->head == NULL) {
        return;
    }
    print_stack_reverse_helper(s->head);
    printf("\n");
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
        return '\0'; // Return null character for empty stack
    }
    return s->head->data;
}



int ParenMatch(String *par_str);
int ParenMatch(String *par_str) {
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;

    for (int i = 0; i < par_str->size; i++) {
        if (par_str->str[i] == '(' || par_str->str[i] == '[' || par_str->str[i] == '{') {
            push(s, par_str->str[i]);
        } else if (par_str->str[i] == ')' || par_str->str[i] == ']' || par_str->str[i] == '}') {
            if (count(s) == 0) {
                free(s);
                return 0; // Unmatched closing parenthesis
            }
            char top_char = top(s);
            if ((par_str->str[i] == ')' && top_char != '(') ||
                (par_str->str[i] == ']' && top_char != '[') ||
                (par_str->str[i] == '}' && top_char != '{')) {
                free(s);
                return 0; // Mismatched opening and closing parenthesis
            } else {
                pop(s);
            }
        }
    }

    int result = count(s) == 0 ? 1 : 0;
    free(s); //free'ing space
    return result;
}