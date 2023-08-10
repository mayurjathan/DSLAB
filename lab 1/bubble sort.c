//bubble sort
#include<stdio.h>
int main()
{
  int a[100], i, c, n,temp;
  printf("Enter no of terms : ");
  scanf("%d", &n);
  printf("Enter %d integer ", n);
  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);
 for(i=0;i<n-1;i++)
  for(c = 0;c<n-i-1;c++)
  {
      if(a[c]>a[c+1])
      {
          temp=a[c];
          a[c]=a[c+1];
          a[c+1]=temp;
      }
  }
  printf("sorted array : ");
 for (c = 0; c < n; c++)
    printf("%d,",a[c]);
}