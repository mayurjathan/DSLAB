//selection sort
#include<stdio.h>
int main()
{
  int a[100], s,i, c, n,temp;
  printf("Enter no of terms : ");
  scanf("%d", &n);
  printf("Enter %d integer ", n);
  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);
  for(i=0;i<n-1;i++)
  for(c=i+1;c<n;c++)
  {
      s=i;
      if(a[s]>a[c])
      {
          s=c;
          if(s!=i)
          {
          temp=a[i];
          a[i]=a[s];
          a[s]=temp;
      }
  }
  }
   printf("sorted array : ");
 for (c = 0; c < n; c++)
    printf("%d,",a[c]);
}
