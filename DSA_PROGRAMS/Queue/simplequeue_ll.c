#include<stdio.h>
#include<stdlib.h>

// Define node structure
struct node {
    int data;
    struct node* next;
};

// Initialize front (f) and rear (r) pointers
struct node* f = NULL;
struct node* r = NULL;

// Function to enqueue an element into the queue
void enqueue(int val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Queue is full (Memory allocation failed)\n");
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL) {  // Queue is empty
            f = r = n;
        } else {
            r->next = n;
            r = n;
        }
        printf("Enqueued element: %d\n", val);
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    int val = -1;
    struct node* ptr = f;
    if (f == NULL) {
        printf("Queue is empty\n");
    } else {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

// Function to display the queue
void display(struct node* ptr) {
    if (ptr == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        int ch, ele, k;
        printf("1...Enqueue\n");
        printf("2...Dequeue\n");
        printf("3...Display\n");
        printf("4...Exit\n");
        scanf("%d", &ch);  // Corrected scanf format

        switch (ch) {
            case 1:
                printf("Enter element\n");
                scanf("%d", &ele);
                enqueue(ele);
                break;

            case 2:
                k = dequeue();
                if (k != -1) {
                    printf("Dequeued element is: %d\n", k);  // Corrected printf
                }
                break;

            case 3:
                display(f);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
