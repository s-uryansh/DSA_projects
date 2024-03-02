#include <stdio.h>
#include <stdlib.h>
int top;
void push(int* array , int data){
    ++top;
    array[top] = data;
}

void pop(int* array ){
    if(top != 0){
        printf("%d " , array[top]);
        --top;
    }
}
int main() {
    int n;
    scanf("%d", &n);    // input number of elements
    
    top = 0;
    int* stack = (int *)malloc(n*sizeof(int));
    int* temp = (int *)malloc(n*sizeof(int));
    
    //creating stack and a temp array and assigning it dynamic memory
    stack[top] = -1;
    
    for(int i =0 ; i<n ; i++){
        scanf("%d" , &temp[i]);
        push(stack , temp[i]);
    }
    
    //pushing values in stackk
    for(int a =0; a<n ; a++){
        pop(stack);
    }
    
    //popping value out of the stack and printing them
    free(stack);
    free(temp);
    
    //Free'ing stack and temp from memory after use
}

    
