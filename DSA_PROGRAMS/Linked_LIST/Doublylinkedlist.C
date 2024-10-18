#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insert_end(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev=NULL;

    if (head == NULL) {
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev=p;
    return head;
}

void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insert_head(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head->prev=ptr;
    return ptr;
}

struct node *delete_last(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *p = head;
    
    while (p->next != NULL) {
        p = p->next;
       
    }
    p->prev->next = NULL;
    free(p);
    return head;
}

struct node *delete_first(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *delete_node(struct node *head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->data == value) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }

    if (q != NULL) {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main() {
    struct node *head = NULL;
    int ch = 0, n;

    while (ch != 7) {
        printf("\n1..Insert at end");
        printf("\n2..Display");
        printf("\n3..Insert at head");
        printf("\n4..Delete last");
        printf("\n5..Delete first");
        printf("\n6..Delete node by value");
        printf("\n7..Exit\n");

        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                head = insert_end(head, n);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                head = insert_head(head, n);
                break;

            case 4:
                head = delete_last(head);
                break;

            case 5:
                head = delete_first(head);
                break;

            case 6:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &n);
                head = delete_node(head, n);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
                break;
        }
    }
    return 0;
}
