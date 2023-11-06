#include <stdio.h>
#include <stdbool.h>
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

// Function to check if two trees are mirror images
bool areMirror(struct Node* root1, struct Node* root2) {
    // If both trees are empty, they are mirror images
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If one of the trees is empty, they are not mirror images
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Recursively check if the left subtree of one tree is the mirror image
    // of the right subtree of the other tree and vice versa
    return (root1->data == root2->data) &&
           areMirror(root1->left, root2->right) &&
           areMirror(root1->right, root2->left);
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    // Create two binary trees
    root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);

    // Check if the two trees are mirror images
    if (areMirror(root1, root2)) {
        printf("The two trees are mirror images.\n");
    } else {
        printf("The two trees are not mirror images.\n");
    }

    // Don't forget to free the memory allocated for the tree nodes

    return 0;
}
