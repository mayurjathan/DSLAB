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

// Function to check the equality of two binary trees
bool areTreesEqual(struct Node* root1, struct Node* root2) {
    // If both trees are empty, they are equal
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If one of the trees is empty, they are not equal
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Recursively check if the data of the current nodes are equal
    // and if their left and right subtrees are also equal
    return (root1->data == root2->data) &&
           areTreesEqual(root1->left, root2->left) &&
           areTreesEqual(root1->right, root2->right);
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
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    // Check for equality
    if (areTreesEqual(root1, root2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    // Don't forget to free the memory allocated for the tree nodes

    return 0;
}
