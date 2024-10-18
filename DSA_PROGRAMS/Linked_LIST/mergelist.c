#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertend(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;  // New node becomes the head if the list is empty
    }

    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

void display(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* merge(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;  // If list 1 is empty, return list 2
    if (head2 == NULL) return head1;  // If list 2 is empty, return list 1

    struct node *p = head1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = head2;
    return head1;
}

int main() {
    int n1, n2, ch;
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter number of nodes in list 1: ");
    scanf("%d", &n1);
    printf("Enter elements of list 1:\n");
    for (int i = 0; i < n1; i++) {
        int element;
        scanf("%d", &element);
        head1 = insertend(head1, element);
    }

    printf("Enter number of nodes in list 2: ");
    scanf("%d", &n2);
    printf("Enter elements of list 2:\n");
    for (int i = 0; i < n2; i++) {
        int element;
        scanf("%d", &element);
        head2 = insertend(head2, element);
    }

    while (1) {
        printf("1...Display list 1\n");
        printf("2...Display list 2\n");
        printf("3...Merge both lists\n");
        printf("4...Display merged list\n");
        printf("5...Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                display(head1);
                break;
            case 2:
                display(head2);
                break;
            case 3:
                head1 = merge(head1, head2);
                printf("Lists merged successfully.\n");
                break;
            case 4:
                display(head1);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
}
