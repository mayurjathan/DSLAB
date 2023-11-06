#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
    struct poly *next;
};

struct poly *head1 = NULL;
struct poly *head2 = NULL;
struct poly *head3 = NULL;

void polynsert(int key, int c, int e)
{
    struct poly *newNode = (struct poly *)malloc(sizeof(struct poly));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (key == 1)
    {
        if (head1 == NULL || e < head1->exp)
        {
            newNode->next = head1;
            head1 = newNode;
        }
        else
        {
            struct poly *prev = NULL;
            struct poly *current = head1;
            while (current != NULL && current->exp < e)
            {
                prev = current;
                current = current->next;
            }
            if (current != NULL && current->exp == e)
            {
                current->coeff += c;
                free(newNode);
            }
            else
            {
                prev->next = newNode;
                newNode->next = current;
            }
        }
    }

    if (key == 2)
    {
        if (head2 == NULL || e < head2->exp)
        {
            newNode->next = head2;
            head2 = newNode;
        }
        else
        {
            struct poly *prev = NULL;
            struct poly *current = head2;
            while (current != NULL && current->exp < e)
            {
                prev = current;
                current = current->next;
            }
            if (current != NULL && current->exp == e)
            {
                current->coeff += c;
                free(newNode);
            }
            else
            {
                prev->next = newNode;
                newNode->next = current;
            }
        }
    }

    if (key == 3)
    {
        if (head3 == NULL || e < head3->exp)
        {
            newNode->next = head3;
            head3 = newNode;
        }
        else
        {
            struct poly *prev = NULL;
            struct poly *current = head3;
            while (current != NULL && current->exp < e)
            {
                prev = current;
                current = current->next;
            }
            if (current != NULL && current->exp == e)
            {
                current->coeff += c;
                free(newNode);
            }
            else
            {
                prev->next = newNode;
                newNode->next = current;
            }
        }
    }
}

void polyadd()
{
    struct poly *newNode = (struct poly *)malloc(sizeof(struct poly));
    for (struct poly *temp = head1; temp != NULL; temp = temp->next)
    {
        int e = temp->exp;
        int c = temp->coeff;
        polynsert(3, c, e);
    }
    for (struct poly *temp = head2; temp != NULL; temp = temp->next)
    {
        int e = temp->exp;
        int c = temp->coeff;
        polynsert(3, c, e);
    }
}

void traverse(int key)
{
    struct poly *current;
    if (key == 1)
        current = head1;
    else if (key == 2)
        current = head2;
    else
        current = head3;
    if (current == NULL)
    {
        printf("0");
        return;
    }

    printf("%dx^%d", current->coeff, current->exp);
    current = current->next;
    while (current != NULL)
    {
        printf(" + %dx^%d", current->coeff, current->exp);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n, c, e;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &c, &e);
        polynsert(1, c, e);
    }

    printf("Polynomial 1: ");
    traverse(1);

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &c, &e);
        polynsert(2, c, e);
    }

    printf("Polynomial 2: ");
    traverse(2);

    polyadd();
    printf("Addition: ");
    traverse(3);

    // Free memory
    struct poly *current = head1;
    while (current != NULL)
    {
        struct poly *temp = current;
        current = current->next;
        free(temp);
    }

    current = head2;
    while (current != NULL)
    {
        struct poly *temp = current;
        current = current->next;
        free(temp);
    }

    current = head3;
    while (current != NULL)
    {
        struct poly *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
