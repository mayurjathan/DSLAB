#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool searchNode(struct Node* root, int data) {
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void printMenu() {
    printf("\nBinary Search Tree Menu:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Search for an element\n");
    printf("4. Print the tree (in-order)\n");
    printf("5. Quit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    bool quit = false;

    while (!quit) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                if (searchNode(root, data)) {
                    printf("Element %d found in the tree.\n", data);
                } else {
                    printf("Element %d not found in the tree.\n", data);
                }
                break;
            case 4:
                printf("Binary Search Tree (in-order): ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                quit = true;
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    // Don't forget to free the memory allocated for the tree nodes

    return 0;
}
