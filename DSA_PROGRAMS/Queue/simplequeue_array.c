#include <stdio.h>
#include <stdlib.h>

struct queue {
    int f, r, size;
    int *arr;
};

// Function to enqueue an element into the queue
void enqueue(struct queue *q, int val) {
    if (q->r == q->size - 1) {
        printf("Queue is full, cannot enqueue\n");
    } else {
        if (q->f == -1) { // First element to enqueue
            q->f = 0;
        }
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q) {
    if (q->f == -1) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    } else {
        int x = q->arr[q->f];
        if (q->f == q->r) { // If last element is dequeued
            q->f = q->r = -1; // Reset the queue
        } else {
            q->f++;
        }
        return x;
    }
}

// Function to display the elements of the queue
void display(struct queue *q) {
    if (q->f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = q->f; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch, ele, k;
    struct queue q;
    q.f = q.r = -1;

    // Allocate memory for the queue
    printf("Enter size of queue\n");
    scanf("%d", &q.size);
    q.arr = (int *)malloc(sizeof(int) * q.size);

    // Menu-driven loop
    while (1) {
        printf("1...Enqueue\n");
        printf("2...Dequeue\n");
        printf("3...Display\n");
        printf("4...Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                // Enqueue operation
                printf("Enter element to be enqueued\n");
                scanf("%d", &ele);
                enqueue(&q, ele);
                break;

            case 2:
                // Dequeue operation
                k = dequeue(&q);
                if (k != -1) {
                    printf("Dequeued element: %d\n", k);
                }
                break;

            case 3:
                // Display operation
                display(&q);
                break;

            case 4:
                // Exit the program
                free(q.arr); // Free the allocated memory
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
