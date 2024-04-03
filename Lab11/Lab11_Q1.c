#include<stdio.h>
#include<stdlib.h>

//Structure for a binary tree node
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

//Function to perform in-order traversal of the complete binary tree
void inOrderTraversal(struct TreeNode* root);
struct TreeNode* insertNode(struct TreeNode* root , int nodeValue);

int main(){
    //Initialize the root of binary tree
    struct TreeNode* root = NULL;
    int nodeValue, n;
    scanf("%d" , &n); // number of nodes
    for(int i =0 ; i<n ; i++){

        scanf("%d" , &nodeValue); // enter input data to each node
        root = insertNode(root , nodeValue);
    }

    inOrderTraversal(root);

    return 0;
}
struct TreeNode* insertNode(struct TreeNode* root , int nodeValue){
    if(root == NULL){
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = nodeValue;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    // If left is NULL insert node in left if right is NULL insert node in right
    //if neither left nor right is null take left as root and check it's sub tree
    if(root->left == NULL){
        root->left = insertNode(root->left, nodeValue);
    }
    else{
        if(root->right == NULL){
        root->right = insertNode(root->right, nodeValue);
        }else{
            insertNode(root->left , nodeValue);
        }
    }
    
    return root;
}


//inOrderTraversal goes from Left , Root , Right
void inOrderTraversal(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    printf("%d " , root->data);
    inOrderTraversal(root->right);
}

