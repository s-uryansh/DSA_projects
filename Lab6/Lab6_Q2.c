#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to find intersection of two linked lists */
int findIntersectionPosition(struct Node* list1, struct Node* list2) {
   
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            return list1->data;
        } else if (list1->data < list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
      
    }
    
    return -1; // Indicates no intersection found
}

/* Function to create a new node */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to insert a node at the end of the list */
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

/* Function to print the linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Driver program to test above functions */
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, data;
    
    printf("Enter the number of elements in list 1: ");
    scanf("%d", &n1);
    printf("Enter the elements of list 1: ");
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &data);
        insertAtEnd(&list1, data);//first list is created
    }

    printf("Enter the number of elements in list 2: ");
    scanf("%d", &n2);
    printf("Enter the elements of list 2: ");
    for (int i = 0; i < n2; ++i) {
        scanf("%d", &data);
        insertAtEnd(&list2, data);//second list is created
    }

   

    int position = findIntersectionPosition(list1, list2);

    if (position != -1) {
        printf("%d",position);//the element which is common is printed
    } else {
        printf("-1");//-1 if no intersection is found
    }

    return 0;
}








