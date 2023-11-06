/*Let list1 = (x1, x2…..xn) and list2= (y1, y2…..ym). Write a function to merge list1 and
list2 to obtain list3 = (x1, y1, x2, y2….xm,ym,xm+1…xn) for m<=n; and list3=(x1,
y1,x2,y2…..xn, yn, xn+1….xm) for m>n*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to merge two lists list1 and list2 into list3
struct node* merge(struct node* l1, struct node* l2) {
    struct node* l3 = NULL;
    struct node* curr1 = l1;
    struct node* curr2 = l2;

    while (curr1 != NULL || curr2 != NULL) {
        if (curr1 != NULL) {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = curr1->data;
            newnode->next = NULL;

            if (l3 == NULL) {
                l3 = newnode;
            } else {
                struct node* curr3 = l3;
                while (curr3->next != NULL) {
                    curr3 = curr3->next;
                }
                curr3->next = newnode;
            }

            curr1 = curr1->next;
        }

        if (curr2 != NULL) {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = curr2->data;
            newnode->next = NULL;

            if (l3 == NULL) {
                l3 = newnode;
            } else {
                struct node* curr3 = l3;
                while (curr3->next != NULL) {
                    curr3 = curr3->next;
                }
                curr3->next = newnode;
            }

            curr2 = curr2->next;
        }
    }

    return l3;
}

// Function to create a linked list from user input
struct node* createList() {
    int n, value;
    struct node* head = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            struct node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newnode;
        }
    }

    return head;
}

// Function to print a linked list
void printList(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for a linked list
void freeList(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        struct node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    printf("Enter elements for List 1:\n");
    struct node* l1 = createList();
    printf("Enter elements for List 2:\n");
    struct node* l2 = createList();
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    struct node* l3 = merge(l1, l2);
    printf("Merged List 3: ");
    printList(l3);

    // Free the memory allocated for the lists
    free(l1);
    free(l2);
    free(l3);

    return 0;
}
