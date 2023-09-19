#include <stdio.h>
#include <malloc.h>
#define MAX 411
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);
int main()
{
    int choice, val;
    do {
        printf("\n1. Insert an element into a queue ");
        printf("\n2. Delete an element from a queue ");
        printf("\n3. Peek an element form a queue ");
        printf("\n4. Display the queue ");
        printf("\n5. EXIT");
        printf("\n\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            val = delete_element();
            if(val != -1);
            printf("\n The number deleted is : %d", val);
             break;  
            case 3:
            val = peek();
            if(val != -1);
            printf("\n The first value in queue is : %d", val);
            break;
            case 4:
            display();
            break;  
        }
    }
    while(choice != 5);
    return 0;
}
void insert() {
    int num;
    printf("\n Enter the element to be inserted into the queue : ");
    scanf("%d", &num);
    if(rear == MAX-1)
    printf("\n OVERFLOW");
    else if(front == -1 && rear == -1)
    front = rear = 0;
    else
    rear++;
    queue[rear] = num;
}
int delete_element()
{
    int val;
    if(front == -1 || front > rear)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    else {
        val = queue[front];
        front++;
        if(front > rear)
        front = rear = -1;
        return val;
    }
}
int peek()
{
    if(front == -1 || front > rear)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else {
        return queue[front];
    }
}
void display()
{
    int i;
    printf("\n");
    if(front == -1 || front > rear )
    printf("\n QUEUE IS EMPTY");
    else {
        for(i = front;i <= rear ; i++)
        printf("\t %d", queue[i]);
    }
}