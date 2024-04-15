#include<stdio.h>
#include<stdlib.h>

//All wanted declarations
    // TreeNode , height , max , insert , leftRotate , rightRotate , postOrderTraversal , deleteNode , minValueNode

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
struct TreeNode* deleteNode(struct TreeNode* root, int key);//Deleting while balancing the AVL property
struct TreeNode* minValueNode(struct TreeNode* node); //Finding min value 
// Function to perform post-order traversal of the AVL tree
void postOrderTraversal(struct TreeNode* root);

int main(){
    struct TreeNode* root = NULL;
    int key , n;
    scanf("%d" , &n); // enter the number of nodes

    for(int i= 0 ; i < n ; i++){
        scanf("%d" , &key); // enter key to insert in AVL tree
        root = insert(root , key);
    }
    root = deleteNode(root, root->data);
    postOrderTraversal(root); // post-order Traversal
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

//Traversing the root in post-order (LEFT , RIGHT , ROOT) and printing the data
void postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    printf("%d ", root->data);
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

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {

    if (root == NULL)
        return root;

//Finding the key value to be deleted

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If key is the same as root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            struct TreeNode* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            struct TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node, then return
    if (root == NULL)
        return root;
//SAME AS INSERTION MAKING SURE THE AVL PROPERTY IS SATISFIED

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = height(root->left) - height(root->right);

    if (balance > 1 && height(root->left->left) >= height(root->left->right))
        return rightRotate(root);

    if (balance > 1 && height(root->left->left) < height(root->left->right)) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && height(root->right->right) >= height(root->right->left))
        return leftRotate(root);

    if (balance < -1 && height(root->right->right) < height(root->right->left)) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
