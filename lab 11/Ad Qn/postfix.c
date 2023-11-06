#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Define a structure for a binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Define a structure for a stack node
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

// Function to create a new binary tree node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new stack node
struct StackNode* createStackNode(struct Node* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode** top, struct Node* data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
struct Node* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct Node* data = temp->data;
    free(temp);
    return data;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to build a binary expression tree from a postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct StackNode* stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            struct Node* node = createNode(ch);
            push(&stack, node);
        } else if (isOperator(ch)) {
            struct Node* rightOperand = pop(&stack);
            struct Node* leftOperand = pop(&stack);
            struct Node* operatorNode = createNode(ch);
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;
            push(&stack, operatorNode);
        }
    }

    return pop(&stack); // The root of the expression tree
}

// Function to evaluate a binary expression tree
int evaluateExpressionTree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (isdigit(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
    }

    return 0;
}

int main() {
    char postfixExpression[] = "23*5+";

    struct Node* root = buildExpressionTree(postfixExpression);

    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result of the Expression: %d\n", evaluateExpressionTree(root));

    return 0;
}
