// implement stack using array
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
// Structure to represent the stack
int items[MAX_SIZE];
 int top=-1;

// Function to push an item onto the stack
void push(int item) {
 if (top==(MAX_SIZE-1)) {
 printf("Stack overflow, cannot push %d\n", item);
 }
 else
 items[++top]=item;
}
// Function to pop an item from the stack
int pop() {
 if (top==-1) {
 printf("Stack underflow, cannot pop\n");
 return -1; // Return an error value
 }
 else
 return items[top--];
}
// Function to peek at the top item of the stack without removing it
int peek() {
 if (top==-1) {
 printf("Stack is empty, cannot peek\n");
 return -1; // Return an error value
 }
 else
 return items[top];
}
int main() {
 int choice, item;
 while (true) {
 printf("\n--- Stack Menu ---\n");
 printf("1. Push\n");
 printf("2. Pop\n");
 printf("3. Peek\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the item to push: ");
 scanf("%d", &item);
 push(item);
 break;
 case 2:
 item = pop();
 if (item != -1)
 printf("Popped item: %d\n", item);
 break;
 case 3:
 item = peek();
 if (item != -1)
 printf("Top item: %d\n", item);
 break;
 case 4:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice, please try again.\n");
 }
 }
 return 0;
}
