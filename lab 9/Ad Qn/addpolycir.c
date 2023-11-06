#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expon;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node* NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct Node));
    return x;
}

NODE attach(int coeff, int expon, NODE head) {
    NODE temp, cur;
    temp = getnode();
    temp->coeff = coeff;
    temp->expon = expon;
    cur = head->prev;
    cur->next = temp;
    temp->prev = cur;
    temp->next = head;
    head->prev = temp;
    return head;
}

NODE read_poly(NODE head) {
    int i = 1, coeff, expon;
    printf("Enter the coefficient as -999 to end the polynomial:\n");
    while (1) {
        printf("Enter the %d term:\n", i++);
        printf("Coeff = ");
        scanf("%d", &coeff);
        if (coeff == -999) {
            break;
        }
        printf("Pow x = ");
        scanf("%d", &expon);
        head = attach(coeff, expon, head);
    }
    return head;
}

NODE poly_add(NODE head1, NODE head2, NODE head3) {
    NODE cur1 = head1->next;
    NODE cur2 = head2->next;

    while (cur1 != head1 && cur2 != head2) {
        if (cur1->expon == cur2->expon) {
            int sum = cur1->coeff + cur2->coeff;
            if (sum != 0) {
                head3 = attach(sum, cur1->expon, head3);
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        } else if (cur1->expon > cur2->expon) {
            head3 = attach(cur1->coeff, cur1->expon, head3);
            cur1 = cur1->next;
        } else {
            head3 = attach(cur2->coeff, cur2->expon, head3);
            cur2 = cur2->next;
        }
    }

    while (cur1 != head1) {
        head3 = attach(cur1->coeff, cur1->expon, head3);
        cur1 = cur1->next;
    }

    while (cur2 != head2) {
        head3 = attach(cur2->coeff, cur2->expon, head3);
        cur2 = cur2->next;
    }

    return head3;
}

void display(NODE head) {
    NODE temp = head->next;

    if (temp == head) {
        printf("0");
        return;
    }

    while (temp != head) {
        printf("%dx^%d", temp->coeff, temp->expon);
        temp = temp->next;

        if (temp != head && temp->coeff > 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    NODE head1 = getnode();
    NODE head2 = getnode();
    NODE head3 = getnode();

    head1->next = head1->prev = head1;
    head2->next = head2->prev = head2;
    head3->next = head3->prev = head3;

    printf("Enter the first polynomial:\n");
    head1 = read_poly(head1);

    printf("Enter the second polynomial:\n");
    head2 = read_poly(head2);

    printf("Polynomial 1: ");
    display(head1);
    printf("Polynomial 2: ");
    display(head2);

    head3 = poly_add(head1, head2, head3);

    printf("Polynomial Result: ");
    display(head3);

    return 0;
}
