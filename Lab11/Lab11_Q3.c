#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int max(int a, int b){
    return (a > b) ? a : b;
}
// Function to insert a node into the binary search tree
struct TreeNode* insertNode(struct TreeNode* root, int value);

// Function to calculate the height of a binary search tree
int treeHeight(struct TreeNode* root);

int main() {
    // Initialize the root of the binary tree
    struct TreeNode* root = NULL;
    int nodeValue, n;
    scanf("%d",&n); // number of nodes
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &nodeValue);    // enter input data to each node
        root = insertNode(root, nodeValue);
    }


    // Calculate and display the height of the binary tree
    int height = treeHeight(root);

    printf("%d" , height);
    return 0;
}

struct TreeNode* insertNode(struct TreeNode* root , int nodeValue) {
    if(root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = nodeValue;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    // If node value is less than root go to left, if greater than root go right sub tree
    if(nodeValue < root->data) {
        root->left = insertNode(root->left, nodeValue);
    } else {
        root->right = insertNode(root->right, nodeValue);
    }
    
    return root;
}
//The height of a binary tree is equal to the largest number of edges from the root to the most distant leaf node

int treeHeight(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }else{
        //Compute height of each subtree
        int Xl = treeHeight(root->left);
        int Xr = treeHeight(root->right);
        //Return larger of two heights +1 for the curremt
        return 1 + max(Xl , Xr);
    }
}