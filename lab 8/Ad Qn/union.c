//Write a program to implement union and intersection of two doubly linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** list, int data) {
    Node* newNode = createNode(data);
    if (*list == NULL) {
        *list = newNode;
    } else {
        newNode->next = *list;
        (*list)->prev = newNode;
        *list = newNode;
    }
}

void display(Node* list) {
    Node* current = list;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* getUnion(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* current = list1;

    while (current != NULL) {
        insert(&result, current->data);
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        if (result == NULL || !contains(result, current->data)) {
            insert(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

Node* getIntersection(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* current = list1;

    while (current != NULL) {
        if (contains(list2, current->data)) {
            insert(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

int contains(Node* list, int data) {
    Node* current = list;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void clearList(Node** list) {
    while (*list != NULL) {
        Node* temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* unionList = NULL;
    Node* intersectionList = NULL;
    int choice, data;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Calculate Union\n");
        printf("6. Calculate Intersection\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert into List 1: ");
                scanf("%d", &data);
                insert(&list1, data);
                break;
            case 2:
                printf("Enter a value to insert into List 2: ");
                scanf("%d", &data);
                insert(&list2, data);
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                break;
            case 4:
                printf("List 2: ");
                display(list2);
                break;
            case 5:
                unionList = getUnion(list1, list2);
                printf("Union: ");
                display(unionList);
                break;
            case 6:
                intersectionList = getIntersection(list1, list2);
                printf("Intersection: ");
                display(intersectionList);
                break;
            case 7:
                clearList(&list1);
                clearList(&list2);
                clearList(&unionList);
                clearList(&intersectionList);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
