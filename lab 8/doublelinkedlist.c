// Write a menu driven program to perform the following on a doubly linked list
// i.) Insert an element at the rear end of the list
// ii.) Delete an element from the rear end of the list
// iii.) Insert an element at a given position of the list
// iv.) Delete an element from a given position of the list
// v.) Insert an element after another element
// vi.) Insert an element before another element
// vii.) Traverse the list
// viii.) Reverse the list
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct Node* insertRear(struct Node* head, int data)
{
    struct Node* newnode=createNode(data);
    if(head==NULL)
    {
        return newnode;
    }
    struct Node* current= head;
    while(current->next!=NULL)
       current=current->next;
    current->next=newnode;
    newnode->prev=current;
    return head;
}
struct Node* deleteRear(struct Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct Node* current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
    return head;
}
struct Node* insertatposition(struct Node* head, int data, int position){
    if(position<1)
    {
        printf("Invalid positon . Position must be 1 or greater .\n");
    }
    struct Node* newnode=createNode(data);
    if(position==1)
    {
        newnode->next=head;
        head->prev=newnode;
        return newnode;
    }
    struct Node* current=head;
    int currentposition =1;
    while(currentposition<position-1 && current!=NULL)
    {
        current=current->next;
        currentposition++;
    }
    if(current==NULL)
    {
        printf("invalid position. Position is beyond the lenght of the list.\n");
        free(newnode);
        return head;
    }
    newnode->next=current->next;
    if(current->next!=NULL)
    {
        current->next->prev=newnode;
    }
    current->next=newnode;
    newnode->prev=current;
    return head;
}
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return head;
    }
    if (position == 1) {
        struct Node* newHead = head->next;
        free(head);
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        return newHead;
    }
    struct Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Invalid position. Position is beyond the length of the list.\n");
        return head;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

struct Node* insertAfterElement(struct Node* head, int data, int element) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list. Cannot insert after.\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node* insertBeforeElement(struct Node* head, int data, int element) {
    if (head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        return head;
    }
    if (head->data == element) {
        struct Node* newNode = createNode(data);
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    struct Node* current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list. Cannot insert before.\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    return head;
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* reverse(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the rear end\n");
        printf("2. Delete from the rear end\n");
        printf("3. Insert at a given position\n");
        printf("4. Delete from a given position\n");
        printf("5. Insert after another element\n");
        printf("6. Insert before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the rear end: ");
                scanf("%d", &data);
                head = insertRear(head, data);
                break;
            case 2:
                head = deleteRear(head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertatposition(head, data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the element to insert after: ");
                scanf("%d", &element);
                head = insertAfterElement(head, data, element);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the element to insert before: ");
                scanf("%d", &element);
                head = insertBeforeElement(head, data, element);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                head = reverse(head);
                break;
            case 9:
                freeList(head);
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}