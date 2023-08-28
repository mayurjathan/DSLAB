//[Implement the stack using arrays.]
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
// Structure to represent the stack
struct Stack {
 int items[MAX_SIZE];
 int top;
};
// Function to initialize the stack
void initialize(struct Stack *stack) {
 stack->top = -1;
}
// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
 return stack->top == -1;
}
// Function to check if the stack is full
bool isFull(struct Stack *stack) {
 return stack->top == MAX_SIZE - 1;
}
// Function to push an item onto the stack
void push(struct Stack *stack, int item) {
 if (isFull(stack)) {
 printf("Stack overflow, cannot push %d\n", item);
 return;
 }
   stack->top++;
 stack->items[stack->top] = item;
}
// Function to pop an item from the stack
int pop(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack underflow, cannot pop\n");
 return -1; // Return an error value
 }
 int poppedItem = stack->items[stack->top];
 stack->top--;
 return poppedItem;
}
// Function to peek at the top item of the stack without removing it
int peek(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty, cannot peek\n");
 return -1; // Return an error value
 }
 return stack->items[stack->top];
}
int main() {
 struct Stack stack;
 initialize(&stack);
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
 push(&stack, item);
 break;
 case 2:
 item = pop(&stack);
 if (item != -1)
 printf("Popped item: %d\n", item);
 break;
 case 3:
 item = peek(&stack);
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
