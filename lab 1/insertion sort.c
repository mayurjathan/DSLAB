//insertion sort
#include<stdio.h>
int main()
{
  int a[100], i,j, c, n,temp;
  printf("Enter no of terms : ");
  scanf("%d", &n);
  printf("Enter %d integer ", n);
  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);
   for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
     printf("sorted array : ");
 for (c = 0; c < n; c++)
    printf("%d,",a[c]);
}