#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to copy a binary tree
struct Node* copyTree(struct Node* source) {
    if (source == NULL) {
        return NULL;
    }

    // Create a new node with the same data
    struct Node* newNode = createNode(source->data);

    // Recursively copy the left and right subtrees
    newNode->left = copyTree(source->left);
    newNode->right = copyTree(source->right);

    return newNode;
}

// Function to print the binary tree in-order
void printTree(struct Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int main() {
    struct Node* sourceTree = NULL;
    struct Node* copiedTree = NULL;

    // Create a source binary tree
    sourceTree = createNode(1);
    sourceTree->left = createNode(2);
    sourceTree->right = createNode(3);
    sourceTree->left->left = createNode(4);
    sourceTree->left->right = createNode(5);

    // Copy the source tree to another tree
    copiedTree = copyTree(sourceTree);

    // Print the copied tree in-order
    printf("Copied tree (in-order): ");
    printTree(copiedTree);
    printf("\n");

    // Don't forget to free the memory allocated for the tree nodes
    // You can implement a separate function to deallocate the tree memory

    return 0;
}
