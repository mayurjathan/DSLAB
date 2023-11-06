#include <stdio.h>
#include <string.h>

// Function to add two long positive integers represented as strings
char* addLongIntegers(const char* num1, const char* num2) {
    int maxLen = (strlen(num1) > strlen(num2)) ? strlen(num1) : strlen(num2);
    char result[maxLen + 2];  // +1 for possible carry and +1 for null terminator
    int carry = 0;
    int i, j, k;

    for (i = strlen(num1) - 1, j = strlen(num2) - 1, k = maxLen; k >= 0; i--, j--, k--) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';
    }

    // If there's a carry after the loop, prepend it to the result
    if (carry > 0) {
        result[0] = carry + '0';
        result[maxLen + 1] = '\0';
    } else {
        // If there's no carry, adjust the result to exclude any leading zeros
        memmove(result, result + 1, maxLen + 1);  // Remove leading zero
    }

    return strdup(result);
}

int main() {
    char num1[1000], num2[1000];

    printf("Enter the first long positive integer: ");
    scanf("%s", num1);

    printf("Enter the second long positive integer: ");
    scanf("%s", num2);

    char* result = addLongIntegers(num1, num2);
    printf("Result: %s\n", result);

    return 0;
}
