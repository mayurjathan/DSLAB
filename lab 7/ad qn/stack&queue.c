//Write a program to implement stack & queue using Singly linked lists
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define the structure of the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear = queue->rear->next = node;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Function to print the queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int sizeOfQueue(struct Queue* queue){
    int size=0;
    for(struct Node* temp=queue->front; temp!=NULL; size++, temp=temp->next);
    return size;
}
//implementation of stack using queue
void push(struct Queue* queue, int data) {
    enqueue(queue, data);
}

void swap(struct Queue** x, struct Queue** y){
    struct Queue* temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int pop(struct Queue** queue) {
    if(isEmpty(*queue)) return -1;
    struct Queue* tempQueue = createQueue();
    while(sizeOfQueue(*queue)!=1)
        enqueue(tempQueue, dequeue(*queue));
    int data = dequeue(*queue);
    swap(queue, &tempQueue);
    free(tempQueue);
    return data;
}

// Main function to test the queue implementation
int main() {
    struct Queue* queue = createQueue();
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    printQueue(queue);
    printf("%d\n", pop(&queue));
    printQueue(queue);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printf("Queue: ");
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Queue: ");
    printQueue(queue);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* newNode(int data) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// struct Stack {
//     struct Node* top;
// };

// struct Queue {
//     struct Node* front;
//     struct Node* rear;
// };

// struct Stack* createStack() {
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = NULL;
//     return stack;
// }

// void push(struct Stack* stack, int data) {
//     struct Node* node = newNode(data);
//     node->next = stack->top;
//     stack->top = node;
// }

// int pop(struct Stack* stack) {
//     if (stack->top == NULL) {
//         return -1; // Stack is empty
//     }
//     int data = stack->top->data;
//     struct Node* temp = stack->top;
//     stack->top = stack->top->next;
//     free(temp);
//     return data;
// }

// int peek(struct Stack* stack) {
//     if (stack->top == NULL) {
//         return -1; // Stack is empty
//     }
//     return stack->top->data;
// }

// int isStackEmpty(struct Stack* stack) {
//     return (stack->top == NULL);
// }

// struct Queue* createQueue() {
//     struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
//     queue->front = queue->rear = NULL;
//     return queue;
// }

// void enqueue(struct Queue* queue, int data) {
//     struct Node* node = newNode(data);
//     if (queue->rear == NULL) {
//         queue->front = queue->rear = node;
//         return;
//     }
//     queue->rear->next = node;
//     queue->rear = node;
// }

// int dequeue(struct Queue* queue) {
//     if (queue->front == NULL) {
//         return -1; // Queue is empty
//     }
//     int data = queue->front->data;
//     struct Node* temp = queue->front;
//     queue->front = queue->front->next;
//     if (queue->front == NULL) {
//         queue->rear = NULL;
//     }
//     free(temp);
//     return data;
// }

// int isQueueEmpty(struct Queue* queue) {
//     return (queue->front == NULL);
// }

// int main() {
//     struct Stack* stack = createStack();
//     struct Queue* queue = createQueue();
//     int choice, data;

//     while (1) {
//         printf("Menu:\n");
//         printf("1. Push (Stack)\n");
//         printf("2. Pop (Stack)\n");
//         printf("3. Peek (Stack)\n");
//         printf("4. Enqueue (Queue)\n");
//         printf("5. Dequeue (Queue)\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter data to push: ");
//                 scanf("%d", &data);
//                 push(stack, data);
//                 break;
//             case 2:
//                 data = pop(stack);
//                 if (data == -1) {
//                     printf("Stack is empty.\n");
//                 } else {
//                     printf("Popped: %d\n", data);
//                 }
//                 break;
//             case 3:
//                 data = peek(stack);
//                 if (data == -1) {
//                     printf("Stack is empty.\n");
//                 } else {
//                     printf("Top element: %d\n", data);
//                 }
//                 break;
//             case 4:
//                 printf("Enter data to enqueue: ");
//                 scanf("%d", &data);
//                 enqueue(queue, data);
//                 break;
//             case 5:
//                 data = dequeue(queue);
//                 if (data == -1) {
//                     printf("Queue is empty.\n");
//                 } else {
//                     printf("Dequeued: %d\n", data);
//                 }
//                 break;
//             case 6:
//                 printf("Exiting the program.\n");
//                 exit(0);
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }

//     return 0;
// }
