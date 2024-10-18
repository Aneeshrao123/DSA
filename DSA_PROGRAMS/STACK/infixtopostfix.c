#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

// Function to return the top element of the stack
int stackTop(struct stack* sp) {
    return sp->arr[sp->top];
}

// Check if the stack is empty
int isEmpty(struct stack *ptr) {
    return (ptr->top == -1) ? 1 : 0;
}

// Check if the stack is full
int isFull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1) ? 1 : 0;
}

// Push a character onto the stack
void push(struct stack* ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Pop a character from the stack
char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Return precedence of an operator
int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

// Check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? 1 : 0;
}

// Convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    // Initialize stack with dynamic size based on the length of the infix expression
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = strlen(infix);  // Make the stack size the length of the infix expression
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    // Allocate memory for the postfix expression
    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition 

    // Loop through the infix expression
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            // If the character is not an operator, add it to the postfix expression
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            // If the precedence of the current operator is greater than the top of the stack
            if (isEmpty(sp) || precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            } else {
                // Pop from the stack and add to postfix until precedence condition is met
                postfix[j] = pop(sp);
                j++;
            }
            
        }
    }

    // Pop remaining operators in the stack
    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';

    // Free the allocated memory for the stack
    free(sp->arr);
    free(sp);

    return postfix;
}

int main() {
    char infix[100];

    // Get the infix expression from the user
    printf("Enter the infix expression: ");
    scanf("%s",infix);

    

    // Convert to postfix and display the result
    printf("Postfix expression is: %s\n", infixToPostfix(infix));

    return 0;
}
