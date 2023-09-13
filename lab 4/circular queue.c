// circular queue
#include<stdio.h>
#define MAX 5
int cir[5];
int rear=-1;
int front=-1;
void insert(int item)
{
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        cir[rear] = item ;
    }
    else if((rear+1)%MAX==front)
    {
        printf("Queue Overflow n");
    }
    else
    {
        rear=(rear+1)%MAX;
        cir[rear]=item;
    }
}
int delete()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue Overflow n");
    }
    else if(front==rear)
    {
        printf("The element is %d ",cir[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("The element is %d ",cir[front]);
          front=(front+1)%MAX;
    }
}
void display()
{
    int i =front;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while(i!=rear)
        {
            printf("%d ", cir[i]);
            i=(i+1)%MAX;
        }
        if(i==rear&&cir[rear]!=0)
            printf("%d",cir[i]);
    }
}
int main()
{
    int choice=1,x;   // variables declaration

    while(choice<4 && choice!=0)   // while loop
    {
    printf("\nPress 1: Insert an element");
    printf("\nPress 2: Delete an element");
    printf("\nPress 3: Display the element");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("Enter the element which is to be inserted : ");
        scanf("%d", &x);
        insert(x);
        break;
        case 2:
        delete();
        break;
        case 3:
        display();
    }}
}
