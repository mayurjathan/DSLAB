/*Let X = (x1, x2….xn) and Y = (y1, y2….yn) be 2 linked lists. Assume that, in each list,
the nodes are in non-decreasing order of the data field values. Write an algorithm to
merge two lists to obtain a new linked list Z in which the nodes are also in the nondecreasing order.
Following the merge, X and Y do not exist as individual lists.
Each node initially in X or Y is now in Z. Do not use additional nodes.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* mergeLists(struct Node* X, struct Node* Y) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->data = 0;
    dummy->next = NULL;
    struct Node* Z = dummy;
    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            Z->next = X;
            X = X->next;
        } else {
            Z->next = Y;
            Y = Y->next;
        }
        Z = Z->next;
    }

    if (X != NULL) {
        Z->next = X;
    } else {
        Z->next = Y;
    }
    struct Node* result = dummy->next;
    free(dummy);
    return result;
}

// Function to create a linked list from user input
struct Node* createList() {
    int n, value;
    struct Node* head = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in non-decreasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    return head;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Enter elements for List X:\n");
    struct Node* X = createList();
    printf("Enter elements for List Y:\n");
    struct Node* Y = createList();
    printf("List X: ");
    printList(X);
    printf("List Y: ");
    printList(Y);
    struct Node* Z = mergeLists(X, Y);
    printf("Merged List Z: ");
    printList(Z);
    while (Z != NULL) {
        struct Node* temp = Z;
        Z = Z->next;
        free(temp);
    }

    return 0;
}
