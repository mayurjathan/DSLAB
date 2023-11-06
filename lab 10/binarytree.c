#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Tree Node Structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode* TreeNodePtr;

// Function to create a new tree node
TreeNodePtr createNode(int data) {
    TreeNodePtr newNode = (TreeNodePtr)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In-order Traversal (Iterative)
void inOrderIterative(TreeNodePtr root) {
    if (root == NULL) {
        return;
    }
    
    TreeNodePtr stack[100];
    int top = -1;
    TreeNodePtr current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Post-order Traversal (Iterative)
void postOrderIterative(TreeNodePtr root) {
    if (root == NULL) {
        return;
    }

    TreeNodePtr stack1[100];
    TreeNodePtr stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) {
        TreeNodePtr current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }

        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Pre-order Traversal (Iterative)
void preOrderIterative(TreeNodePtr root) {
    if (root == NULL) {
        return;
    }

    TreeNodePtr stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        TreeNodePtr current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }

        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

// Function to print the parent of the given element
TreeNodePtr findParent(TreeNodePtr root, int key, TreeNodePtr parent) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == key) {
        return parent;
    }

    TreeNodePtr leftResult = findParent(root->left, key, root);
    if (leftResult != NULL) {
        return leftResult;
    }

    TreeNodePtr rightResult = findParent(root->right, key, root);
    return rightResult;
}

// Function to find the depth of the tree
int findDepth(TreeNodePtr root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to print the ancestors of a given element
bool printAncestors(TreeNodePtr root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(TreeNodePtr root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int leftLeaves = countLeafNodes(root->left);
    int rightLeaves = countLeafNodes(root->right);

    return leftLeaves + rightLeaves;
}

int main() {
    TreeNodePtr root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("In-order traversal: ");
    inOrderIterative(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderIterative(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderIterative(root);
    printf("\n");

    int elementToFind = 5;
    TreeNodePtr parent = findParent(root, elementToFind, NULL);
    if (parent != NULL) {
        printf("Parent of %d is %d\n", elementToFind, parent->data);
    } else {
        printf("Element not found or it is the root node\n");
    }

    int depth = findDepth(root);
    printf("Depth of the tree is: %d\n", depth);

    int targetElement = 5;
    printf("Ancestors of %d: ", targetElement);
    printAncestors(root, targetElement);
    printf("\n");

    int leafNodes = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafNodes);

    return 0;
}
