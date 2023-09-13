/* Write a program to implement queue data structure using stack*/
#include<stdio.h>
#define SIZE 100

int stack[SIZE*2];
int top[2] = {-1,SIZE-1};
int limit[2] = {99,199};

void insert(int val)
{
    push(0,val);
}

int delete()
{
    while(top[0] > -1)
    {
        push(1,pop(0));
    }
    int res = pop(1);
    while(top[1] > 99)
    {
        push(0,pop(1));
    }
    return res;
}


void push(int ind, int val)
{
    top[ind]++;
    if(top[ind] > limit[ind])
    {
        printf("Stack out of bound");
        return;
    }

    stack[top[ind]] = val;
}

int pop(int ind)
{
    if(top[ind] < -1 + (SIZE*ind))
    {
        printf("Stack empty\n");
        return -99999;
    }
    return (stack[top[ind]--]);
}

void disp()
{
    for(int i=0;i<=top[0];i++)
    {
        printf("%d  ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int n,ins;
    //Sample input output
    do{
        printf("\n1.Insert\n2.delete\n3.display\n4.Exit\nEnter an option : ");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Enter an number to be inserted : ");
            scanf("%d",&ins);
            insert(ins);
            disp();
        }
        else if(n==2)
        {
            delete();
            disp();
        }
         else if(n==3)
        {
            disp();
        }
        else
            exit(0);
    }
    while(1);
    return 0;
}
