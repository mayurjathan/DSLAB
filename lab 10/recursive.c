#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode* TreeNodePtr;

// Function to create a new binary tree node
TreeNodePtr createNode(int data) {
    TreeNodePtr newNode = (TreeNodePtr)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
TreeNodePtr insert(TreeNodePtr root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to print a binary tree in in-order traversal
void printInOrder(TreeNodePtr root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to free memory by deleting the binary tree
void deleteTree(TreeNodePtr root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main() {
    TreeNodePtr root = NULL;

    // Insert elements into the binary tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary tree in in-order traversal
    printf("In-order traversal of the binary tree: ");
    printInOrder(root);
    printf("\n");

    // Delete the binary tree and free memory
    deleteTree(root);

    return 0;
}
