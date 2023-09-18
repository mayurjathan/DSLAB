/*Write a program to perform following string operations without using string handling
functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring*/
#include<stdio.h>
int length(char []);
void concate(char [], char []);
int compare(char [], char []);
void insert(char [],char [],int );
void deletesub(char [],char []);
int main()
{
    int n=0,p;
    char s1[20],s2[20];
    do{
    printf(" 1.length of the string \n 2.string concatenation \n 3.string comparison\n 4.to insert a sub string\n 5.to delete a substring\n 6.exit \n");
    printf("Enter your option : ");
    scanf("%d",&n);
    
    switch(n)
    {
    case 1:
        printf("Enter the string : ");
        scanf("%s",s1);
        printf("length of %s is %d\n",s1,length(s1));
        break;
    case 2:
        printf("Enter the first string : ");
        scanf("%s",s1);
        printf("Enter the second string : ");
        scanf("%s",s2);
        concate(s1,s2);
        printf("concatenation string is %s \n",s1);
        break;
    case 3:
        printf("Enter the first string : ");
        scanf("%s",s1);
        printf("Enter the second string : ");
        scanf("%s",s2);
        if (compare(s1, s2) == 0)
            printf("Equal strings.\n");
        else
            printf("Unequal strings.\n");
        break;
    case 4:
        printf("Enter the string : ");
        scanf("%s",s1);
        printf("Enter the sub string to be insert : ");
        scanf("%s",s2);
        printf("Enter the position to insert : ");
        scanf("%d", &p);
        insert(s1,s2,p);
        printf("the string is %s\n",s1);
        break;
    case 5:
        printf("Enter the string : ");
        scanf("%s",s1);
        printf("Enter the sub string to be deleted : ");
        scanf("%s",s2);
        deletesub(s1,s2);
        printf("the string is %s\n",s1);
        break;
    case 6:
        exit(0);
    default:
        printf("Invalid option!\n");
    }
    }
    while(1);
}

int length(char s1[])
{
   int c = 0;
   while (s1[c] != '\0')
      c++;

   return c;
}
void concate(char s1[], char s2[])
{
   int c, d;
   c = 0;
   while (s1[c] != '\0') {
      c++;
   }
   d = 0;
   while (s2[d] != '\0') {
      s1[c] = s2[d];
      d++;
      c++;
   }

   s1[c] = '\0';
}
int compare(char s1[], char s2[])
{
   int c = 0;

   while (s1[c] == s2[c]) {
      if (s1[c] == '\0' || s2[c] == '\0')
         break;
      c++;
   }

   if (s1[c] == '\0' && s2[c] == '\0')
      return 0;
   else
      return -1;
}
void insert(char s1[], char s2[], int p)
{
    int l1 = length(s1);
    int l2 = length(s2);
    if (p < 0 || p > l1) {
        printf("Invalid position to insert!\n");
        return;
    }
    for (int i = l1; i >= p; i--) {
        s1[i + l2] = s1[i];
    }
    for (int i = 0; i < l2; i++) {
        s1[p + i] = s2[i];
    }
    s1[l1 + l2] = '\0';
}
void deletesub(char s1[], char s2[])
{
    int l1, l2, i, j, k, found;

    l1 = length(s1);
    l2 = length(s2);

    for (i = 0; i <= l1 - l2; i++) {
        found = 1;

        for (j = 0; j < l2; j++) {
            if (s1[i + j] != s2[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            // Shift characters to remove the substring
            for (k = i; k < l1 - l2; k++) {
                s1[k] = s1[k + l2];
            }

            // Update the length of the string
            l1 = l1 - l2;
            
            // Null-terminate the string
            s1[l1] = '\0';

            // Adjust the loop variable
            i--;
        }
    }
}

