#include<stdio.h>
#include<stdlib.h>

// Define stack structure
struct stack {
    int top;
    int size;
    int *s;  // Correct type: stack stores integers, not stack structures
};

// Push function
int push(int val, struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        printf("Stack is full\n");
        return -1;
    } else {
        ptr->top++;
        ptr->s[ptr->top] = val;
        return 1;
    }
}

// Pop function
int pop(struct stack *ptr) {
    if (ptr->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int val = ptr->s[ptr->top];
        ptr->top--;  // Decrement the top after popping the value
        return val;
    }
}

// Display function
void display(struct stack *ptr) {
    if (ptr->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = 0; i <= ptr->top; i++) {  // Correct loop to include top element
            printf("%d\n", ptr->s[i]);
        }
    }
}

int main() {
    int ch, ele, k;

    // Allocate memory for the stack structure
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->top = -1;  // Initialize top

    // Input size of the stack
    printf("Enter size of the stack: ");
    scanf("%d", &ptr->size);

    // Allocate memory for stack array
    ptr->s = (int *)malloc(sizeof(int) * ptr->size);

    while (1) {
        printf("\n1...Push\n");
        printf("2...Pop\n");
        printf("3...Display\n");
        printf("4...Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                k = push(ele, ptr);
                if (k > 0) {
                    printf("%d pushed successfully\n", ele);
                }
                break;

            case 2:
                k = pop(ptr);
                if (k != -1) {
                    printf("Popped element: %d\n", k);
                }
                break;

            case 3:
                display(ptr);
                break;

            case 4:
                // Free allocated memory before exiting
                free(ptr->s);
                free(ptr);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
