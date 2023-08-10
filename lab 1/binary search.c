// binary search
#include <stdio.h>
int main()
{
  int c, f, l, m, n, s, a[100];
  printf("Enter number of elements : ");
  scanf("%d", &n);
  printf("Enter %d integers : ", n);
  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);
  printf("Enter value to find\n");
  scanf("%d", &s);

  f = 0;
  l = n - 1;
  m = (f+l)/2;

  while (f <= l) {
    if (a[m] < s)
      f = m + 1;
    else if (a[m] == s) {
      printf("%d found at location %d.", s, m+1);
      break;
    }
    else
      l = m - 1;

    m = (f + l)/2;
  }
  if (f > l)
    printf(" %d isn't present in the list.", s);
}