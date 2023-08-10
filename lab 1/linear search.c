//linear search
#include<stdio.h>
int main()
{
  int a[100], s, c, n;
  printf("Enter no of terms : ");
  scanf("%d", &n);
  printf("Enter %d integer ", n);
  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);
  printf("Enter the number to be searched : ");
  scanf("%d", &s);
  for (c = 0; c < n; c++)
  {
    if (a[c] == s)
    {
      printf("%d is present at %d.", s, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d is not present in the array.\n", s);

  return 0;
}
