#include<stdio.h>
#include<stdlib.h>

//All wanted declarations
    // TreeNode , height , max , insert , leftRotate , rightRotate , preOrderTraversal

//Structure for a tree node
struct TreeNode {
    int data;
    struct  TreeNode* left;
    struct  TreeNode* right;
    int height; // Height of the node
};
//Function to get the height of a node
int height(struct TreeNode* node);
int max(int a, int b){
    return (a > b) ? a : b;
}
// Function to insert a key into the AVL tree
struct TreeNode* insert(struct TreeNode* root , int key);
struct TreeNode* leftRotate(struct TreeNode* x);
struct TreeNode* rightRotate(struct TreeNode* y);
// Function to perform pre-order traversal of the AVL tree
void preOrderTraversal(struct TreeNode* root);

int main(){
    struct TreeNode* root = NULL;
    int key , n;
    scanf("%d" , &n); // enter the number of nodes

    for(int i= 0 ; i < n ; i++){
        scanf("%d" , &key); // enter key to insert in AVL tree
        root = insert(root , key);
    }

    preOrderTraversal(root); // pre-order Traversal
    // printf("%d " , height(root->right));
    
    return 0;
}

struct TreeNode* insert(struct TreeNode* root, int nodeValue) {

    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = nodeValue;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1; // Height of the newly inserted node is 1
        return newNode;
    }

    if (nodeValue < root->data) {
        root->left = insert(root->left, nodeValue);
    } else if (nodeValue > root->data) {
        root->right = insert(root->right, nodeValue);
    } else {
        return root;
    }
    //Updating Root height
    root->height = 1 + max(height(root->left), height(root->right));
    //Checking the balance condition (-1,0,1)
    int balance = height(root->left) - height(root->right);
    //If the tree is left-heavy & new data is less than current node data, we do right rotation 
    if (balance > 1 && nodeValue < root->left->data)
        return rightRotate(root);
    //If the tree is right-heavy & new data is more than current node data, we do left rotation
    if (balance < -1 && nodeValue > root->right->data)
        return leftRotate(root);
    //If the tree is left-heavy & new data is more than current node data , we do left-right rotation ( double rotation )
    if (balance > 1 && nodeValue > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //Of the tree is right-haevy & new data is less than the current data , we do right-left rotation (double rotation )
    if (balance < -1 && nodeValue < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//Traversing the root in pre-order (root , left , right) and printing the data
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//Checking the height of root or node to keep the balancing condition (-1,0,1)
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int Xl = height(root->left);
        int Xr = height(root->right);
        return 1 + max(Xl, Xr);
    }
}

// Function to perform a right rotation
struct TreeNode* rightRotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation
struct TreeNode* leftRotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}