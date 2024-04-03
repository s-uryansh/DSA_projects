#include<stdio.h>
#include<stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
int max(int a, int b){
    return (a > b) ? a : b;
}
// Function to perform in-order traversal of the complete binary tree
int treeHeight(struct TreeNode* root);
struct TreeNode* insertNode(struct TreeNode* root , int nodeValue);


int main() {
    // Initialize the root of binary tree
    struct TreeNode* root = NULL;
    int nodeValue, n;
    scanf("%d" , &n); // Number of nodes
    for(int i = 0; i < n; i++) {
        scanf("%d" , &nodeValue); // Enter input data to each node
        root = insertNode(root , nodeValue);
    }

    int h=treeHeight(root);
    printf("%d" , h);
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

int treeHeight(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }else{
        int Xl = treeHeight(root->left);
        int Xr = treeHeight(root->right);
        return 1 + max(Xl , Xr);
    }
}
