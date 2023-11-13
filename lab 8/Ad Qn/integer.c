//. Write a program to implement addition of two long positive integer numbers.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new doubly linked list node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a digit at the front of a doubly linked list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to add two numbers represented by doubly linked lists
struct Node* addNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* current1 = num1;
    struct Node* current2 = num2;
    int carry = 0;

    while (current1 || current2 || carry) {
        int sum = carry;
        if (current1) {
            sum += current1->data;
            current1 = current1->next;
        }
        if (current2) {
            sum += current2->data;
            current2 = current2->next;
        }

        carry = sum / 10;
        sum %= 10;
        insertAtFront(&result, sum);
    }

    return result;
}

// Function to print a doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create two numbers represented as doubly linked lists
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    // Example numbers: 12345 and 6789
    int number1[] = {1, 2, 3, 5, 6};
    int number2[] = {5, 7, 8, 9};

    for (int i = 0; i < 5; i++) {
        insertAtFront(&num1, number1[i]);
    }

    for (int i = 0; i < 4; i++) {
        insertAtFront(&num2, number2[i]);
    }

    // Perform addition and print the result
    struct Node* result = addNumbers(num1, num2);
    printf("Result of addition: ");
    printList(result);

    return 0;
}
