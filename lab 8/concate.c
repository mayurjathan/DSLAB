#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* llink;
    int data;
    struct node* rlink;
} node;

node* x1 = NULL;
node* x2 = NULL;

node* insert(node* first, int val) {
    node* cur;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->rlink = NULL;
    temp->llink = NULL;

    if (first == NULL) {
        first = temp;
    }
    else {
        for (cur = first; cur->rlink != NULL; cur = cur->rlink);
        cur->rlink = temp;
        temp->llink = cur;
    }
    return first;
}

void display(node* first) {
    if (first == NULL) {
        printf("Empty List:\n");
    }
    else {
        node* cur;
        for (cur = first; cur != NULL; cur = cur->rlink) {
            printf("%d ", cur->data);
        }
        printf("\n");
    }
}

// ...

int main() {
    int val;
    char choice;

    do {
        printf("Enter a value: ");
        scanf("%d", &val);
        x1 = insert(x1, val);

        printf("Do you want to enter more values? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    display(x1);

    node* cur;
    for (cur = x1; cur->rlink != NULL; cur = cur->rlink); // Fix this line

    do {
        printf("Enter a value for the second list: ");
        scanf("%d", &val);
        x2 = insert(x2, val);

        printf("Do you want to enter more values? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    display(x2);

    if (cur != NULL) { // Check if cur is not NULL before updating rlink
        cur->rlink = x2;
    }

    if (x2 != NULL) {
        x2->llink = cur;
    }

    display(x1);

    return 0;
}
