/*Write a C program to check whether a given string is a palindrome or not using stacks*/
#include<stdio.h>
#define max 50
int top=-1;
char stack[max];
void addstring(char s[100])//adding string to stack
{
    top=0;
    while(s[top]!='\0'&&top<max-1)
    {
        stack[top]=s[top];
        top++;
    }
    stack[top]='\0';
}
void main()
{
    char s[100];
    int flag=1;
    printf("Enter the string : ");
    scanf("%s",s);
    addstring(s);
    int i;
    top--;
    while(top>=0)
    {
        if(stack[top]!=s[i])
        {
            printf("Not a Palindrome");
            flag=0;
            break;
        }
        i++;
        top--;
    }
    if(flag==1)
    printf("Its a Palindrome");
}
