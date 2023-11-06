/* Write a menu driven program to perform the following operations on linked list.
i) Insert an element before another element in the existing list
ii) Insert an element after another element in the existing list
iii) Delete a given element from the list
iv) Traverse the list
v) Reverse the list
vi) Sort the list
vii) Delete every alternate node in the list
viii) Insert an element in a sorted list such that the order is maintained.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* first = NULL;

void display()
{
    if(first == NULL) printf("Empty List:");
    node* cur;

    for(cur=first;cur!=NULL; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

void insertAtEnd(int val)
{
    node* cur;
    node* temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if(first==NULL)
    {
        first = temp;
        return;
    }


    for(cur=first;cur->next!=NULL; cur = cur->next);
    cur->next = temp;
}

void insertAtStart(int val)
{
    node* cur;
    node* temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = first;
    first = temp;
}
void del(int val)
{
    node* cur;
    node* prev;
    for(cur=first, prev= first;cur!=NULL; prev = cur, cur = cur->next)
    {
        if(cur->data == val)
        {
            prev->next = cur->next;
            free(cur);
            return;
        }
    }
}

void delAlternate()
{
    node* cur = first;
    node* prev = first;

    int alt = -1;

    while(cur!=NULL)
    {
        if(alt == 1)
        {
            prev->next = cur->next;
            node* temp = cur;
            cur = cur->next;
            free(temp);
            alt = -1;
        }
        else
        {
            alt = 1;
            prev = cur;
            cur = cur->next;
        }
    }
}

void reverseList()
{
    if(first==NULL) return;
    node* temp = (node*)malloc(sizeof(node));
    node* cur = first->next;
    first->next = NULL;

    while(cur!=NULL)
    {
        temp = cur;
        cur = cur->next;
        temp->next = first;
        first = temp;
    }
}

void sort()
{
    node* i;
    node* j;


    for(i=first;i->next!=NULL;i=i->next)
    {
        for(j=first;j->next!=NULL;j=j->next)
        {
            if(j->data > j->next->data)
            {
                node* temp = j->next->data;
                j->next->data = j->data;
                j->data = temp;
            }
        }
    }
}

void insertBefore(int src, int val)// src = position and val = value to be inserted
{
    node* cur;
    node* prev;
    node* temp = (node*) malloc(sizeof(node));
    if(first->data == src)
    {
      insertAtStart(val);
      return;
    }
    for(cur=first,prev=first;cur->next != NULL; prev = cur, cur = cur->next)
    {
        if(cur->data==src)
        {
          temp->data = val;
          prev->next = temp;
          temp->next = cur;
        }
    }
}

void insertAfter(int src, int val)
{
    node* cur;
    node* temp = (node*) malloc(sizeof(node));
    node* curNext;

    if(first->next == NULL)insertAtEnd(val);

    for(cur=first;cur!= NULL; cur = cur->next)
    {
      if(cur->data==src)
      {
        curNext = cur->next;
        if(cur->next==NULL)
        {
            insertAtEnd(val);
        }
        else
        {
            temp->data = val;
            cur->next = temp;
            temp->next = curNext;
        }
      }
    }
}
void sortedInsert(int val)
{
    node* cur = first;
    node* prev = first;
    node* temp = (node*) malloc(sizeof(node));
    temp->data = val;

    if(first == NULL || val < first->data)
    {
        temp->next = first;
        first = temp;
        return;
    }

    for(;cur!=NULL && cur->data < val; prev = cur, cur = cur->next);

    prev->next = temp;
    temp->next = cur;
}


int main()
{
    int n;
    int p,e;
    insertAtStart(10);
    insertAtEnd(50);
    insertAtEnd(30);
    insertAtEnd(20);
    display();
    do{
    printf("\n1) Inserts an element before another element in the existing list\n2) Inserts an element after another element in the existing list\n3) Deletes a given element from the list\n4) Traverses the list\n5) Reverse the list\n6) Sort the list\n7) Delete every alternate node in the list\n8) Inserts an element in a sorted list such that the order is maintained.\n9)Exit\nEnter an option : ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Enter the element : ");
        scanf("%d",&e);
        printf("Enter the element before which to be inserted : ");
        scanf("%d",&p);
        insertBefore(p,e);//takes the element and the position to be inserted
        display();
        break;
    case 2:
        printf("Enter the element : ");
        scanf("%d",&e);
        printf("Enter the element after which to be inserted : ");
        scanf("%d",&p);
        insertAfter(p,e);
        display();
        break;
    case 3:
        printf("Enter the element to be deleted : ");
        scanf("%d",&e);
        del(e);
        display();
        break;
    case 4:
        display();
        break;
    case 5:
        printf("Reversed list : ");
        reverseList();
        display();
        break;
    case 6:
        printf("Sorted list : ");
        sort();
        display();
        break;
    case 7:
        printf("Deleted alternate node : ");
        delAlternate();
        display();
        break;
    case 8:
        printf("Enter the element : ");
        scanf("%d",&e);
        sort();
        sortedInsert(e);
        display();
        break;
    default:
        exit(1);
        break;
    }
    }
    while(n!=0);
}

