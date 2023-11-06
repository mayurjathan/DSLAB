// Write recursive functions for i) Creating a linked list ii) Traversing a linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};
struct node* createlinkedlist()
{
    int val;
    printf("Enter a value (or -1 to end input): ");
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }
     struct node* newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=val;
     newnode->next=createlinkedlist();
     return newnode;
}
void traverse(struct node* Node)
{
    if(Node==NULL)
    {
        printf("Null\n");
        return;
    }
    printf("%d->",Node->data);
    traverse(Node->next);
}
int main()
{
    struct node* head= createlinkedlist();
    printf("linked list : ");
    traverse(head);
    while(head=NULL)
    {
        struct node* temp=head;
        head=head->next;
        free(temp);
    }
}
