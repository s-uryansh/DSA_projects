#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int num;
    struct Node* nextptr;
};

// Global head pointer for the linked list
struct Node* head = NULL;

// Function to create a linked list with n nodes
void createNodeList(int n);
void displayList();

// Function to display the linked list
int main() {
    int n;

    // Read the number of nodes from the user
    scanf("%d", &n);

    // Create the linked list
    createNodeList(n);

    // Display the linked list
    displayList();

    return 0;
}

void createNodeList(int n) {
    struct Node* temp = NULL; // Temporary node to traverse the list

    // Create n nodes and add them to the linked list
    for (int i = 0; i < n; i++) {
        // Allocate memory for a new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        
        // Read data for the node from the user
        scanf("%d", &(newNode->num));
        
        // Set the next pointer of the new node to NULL
        newNode->nextptr = NULL;

        // If it's the first node, set it as the head of the list
        if (head == NULL) {
            head = newNode;
        } else {
            // Otherwise, traverse the list to the last node and link the new node
            temp = head;
            while (temp->nextptr != NULL) {
                temp = temp->nextptr;
            }
            temp->nextptr = newNode;
        }
    }
}

void displayList() {
    struct Node* current = head; // Start at the head of the list

    // Traverse the linked list and print the data of each node
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->nextptr;
    }
    printf("\n");
}
