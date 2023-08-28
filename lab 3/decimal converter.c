/*Write a C program to convert a given decimal number to a number in any base using
stack*/
#include<stdio.h>
#include<math.h>
#define max 50
int top=-1;
int stack[max];
void addtostack(int n)
{
    top++;
    if(top<max)
    {
       stack[top]=n;
    }
    else
        printf("Stack out of bound");

}
void main()
{
    int n,base;
    printf("Enter a number\n");
    scanf("%d",&n);
    printf("Enter the base\n");
    scanf("%d",&base);
    while(n!=0)
    {
        addtostack(n%base);
        n/=base;
    }
    int res=0;
    while(top>=0)
    {
        int pop=stack[top];
        if(pop>=10)
            printf("%c",pop+55);
        else
            printf("%d",pop);
        top--;
    }
}
