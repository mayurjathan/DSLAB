#include <stdio.h>

int multiply(int a, int b, int ind) {
    if (ind == 1) return b;

    return b + multiply(a, b, ind - 1);
}

int main() {
    int a, b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    int res;
    if (a <= 0 || b <= 0) {
        printf("Both numbers must be positive integers.\n");
        return 1;
    } else {
        res = multiply(a, b, a);
        printf("Result: %d\n", res);
    }

    return 0;
}
