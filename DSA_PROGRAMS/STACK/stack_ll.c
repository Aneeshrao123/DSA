#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Global top pointer for the stack
struct node *top = NULL;

// Push function to add an element to the stack
struct node* push(int val, struct node *ptr) {
    // Allocate memory for a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return ptr;
    }
    new_node->data = val;  // Set the data value
    new_node->next = ptr;  // Point the new node to the current top
    ptr = new_node;        // Update the top to point to the new node
    printf("%d pushed onto the stack\n", val);
    return ptr;
}

// Pop function to remove an element from the stack
struct node* pop(struct node *ptr) {
    if (ptr == NULL) {
        printf("Stack is empty, nothing to pop\n");
        return NULL;
    }
    struct node *temp = ptr;  // Temporary pointer to hold the top node
    printf("Popped element: %d\n", temp->data);
    ptr = ptr->next;  // Move the top to the next node
    free(temp);  // Free the memory of the popped node
    return ptr;
}

// Display function to show all elements in the stack
void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    struct node *temp = ptr;
    while (temp != NULL) {
        printf("%d\n", temp->data);  // Print each node's data
        temp = temp->next;  // Move to the next node
    }
}

int main() {
    int ch, ele;

    while (1) {
        printf("\n1...Push\n");
        printf("2...Pop\n");
        printf("3...Display\n");
        printf("4...Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                // Push operation
                printf("Enter the element to push: ");
                scanf("%d", &ele);
                top = push(ele, top);  // Update the top after push
                break;

            case 2:
                // Pop operation
                top = pop(top);  // Update the top after pop
                break;

            case 3:
                // Display operation
                display(top);
                break;

            case 4:
                // Exit
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
