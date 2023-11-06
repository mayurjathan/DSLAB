#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}
void delete(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* current = *head;

    if (current->data == data) {
        if (current->next == current) {
            *head = NULL;
        } else {
            (*head)->next->prev = current->prev;
            current->prev->next = (*head)->next;
            *head = (*head)->next;
        }
        free(current);
        printf("Deleted from the list.\n");
        return;
    }

    Node* nextNode = current->next;

    while (nextNode != *head) {
        if (nextNode->data == data) {
            current->next = nextNode->next;
            nextNode->next->prev = current;
            free(nextNode);
            printf("Deleted from the list.\n");
            return;
        }
        current = nextNode;
        nextNode = nextNode->next;
    }

    printf("Element not found in the list.\n");
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    printf("Doubly Linked Circular List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Back to the start)\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\nDoubly Linked Circular List Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
