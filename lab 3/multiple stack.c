/* Write a C program to implement Multiple stacks using arrays.*/
#include<stdio.h>
#define m 12
#define n 3
typedef struct
{
    int key;
}mstack;
mstack s[10];
int top[5],b[5];
int main()
{
    int i;
    for(i=0;i<n;i++)
    top[i]=b[i]=(m/n)*i-1;
    b[i]=m-1;
    push()
}
void push(int i, mstack item)
{
    if(top[i]==b[i+1])
    {

    }
    else
        s[++top[i]]=item;
}
mstack pop(int i)
{
    mstack temp;
    if(top[i]==b[i])
    {
        printf("Empty");
        temp.key=-9999;
    }
    else
        return s[top[i]--];
}
void display(int i)
{
    if(top[i]==b[i])
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int j;
        for(j=b[i]+1;j<=top[i];j++)
        printf("%d",s[j].key);
    }
}
