#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to detect and remove a loop in a linked list
void detectAndRemoveLoop(struct Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return;

    // Initialize two pointers slow and fast
    struct Node *slow = head, *fast = head;

    // Move slow pointer by one and fast pointer by two
    // If there's a loop, they will meet at some point
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // If no loop is found, return
    if (slow != fast)
        return;

    // Move slow pointer to head and keep fast pointer at meeting point
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Set the next pointer of the last node in the loop to NULL
    fast->next = NULL;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    // Ask the user for the number of nodes in the linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        if (head == NULL) {
            head = newNode(data);
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode(data);
        }
    }

    // Ask the user where to create the loop
    int loopIndex;
    printf("Enter the index (0-based) where you want to create the loop (-1 for no loop): ");
    scanf("%d", &loopIndex);

    if (loopIndex != -1) {
        struct Node* loopNode = head;
        while (loopIndex--) {
            loopNode = loopNode->next;
        }
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = loopNode;
    }

    // Detect and remove loop
    detectAndRemoveLoop(head);

    // Print the linked list
    printf("Linked list after removing loop:\n");
    printList(head);

    return 0;
}
