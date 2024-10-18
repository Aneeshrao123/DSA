#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    char n[100];               
    struct node *next;        // Points to the next chat
};

// Function to add a new chat at the end of the list
struct node *add_chat(struct node *head, char n[100]) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->n, n);        // Copy the chat name into the node
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;           // If list is empty, new node becomes the head
    }

    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;          // Traverse to the end of the list
    }
    p->next = ptr;            // Append the new chat at the end
    return head;
}

// Function to display all chats, each on a new line
void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%s\n", ptr->n);   // Print each chat name on a new line
        ptr = ptr->next;
    }
}

// Function to delete a chat by name
struct node *delete_chat(struct node *head, char n[100]) {
    if (head == NULL) {
        printf("No chats exist.\n");
        return NULL;
    }
    // Check if the chat to delete is the head
    if (strcmp(head->n, n) == 0) {
        struct node *temp = head;
        head = head->next;     // Move head to the next chat
        free(temp);            // Free the old head
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
    while (q != NULL && strcmp(q->n, n) != 0) {
        p = p->next;           // Traverse the list to find the chat
        q = q->next;
    }

    if (q != NULL) {
        p->next = q->next;     // Remove the chat from the list
        free(q);               // Free the memory of the deleted chat
    } else {
        printf("Chat not found.\n");
    }
    return head;
}

// Function to pin a chat (move it to the top of the list)
struct node *pin_chat(struct node *head, char n[100]) {
    // First, we need to remove the chat from its original position (if it exists)
    struct node *p = head;
    struct node *prev = NULL;

    
    // Check if the head contains the chat to be pinned
    if (head != NULL && strcmp(head->n, n) == 0) {
        return head;  // Already pinned, no need to move it
    }

    // Traverse the list to find the chat
    while (p != NULL && strcmp(p->n, n) != 0) {
        prev = p;
        p = p->next;
    }

    // If the chat is found in the list (i.e., p is not NULL)
    if (p != NULL) {
        if (prev != NULL) {
            prev->next = p->next;  // Remove the chat from its original position
        }
        free(p);  // Free the node that we just removed
    }

    // Now add the chat to the top (pinning it)
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->n, n);         // Copy the chat name into the new node
    new_node->next = head;          // New node points to the current head
    return new_node;                // Return the new node as the head
}

// Function to unpin the first chat (remove from the front)
struct node *unpin_chat(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node *ptr = head;
    head = head->next;         // Move the head pointer to the next chat
    free(ptr);                 // Free the old head
    return head;
}

// Main function to drive the chat messenger interface
int main() {
    struct node *head = NULL;  // Initialize an empty chat list
    int ch = 0;
    char name[100];            // Buffer to store chat names

    // Main menu loop
    while (ch != 5) {
        printf("\n1..Add chat");
        printf("\n2..Pin chat");
        printf("\n3..Delete a chat");
        printf("\n4..Unpin chat");
        printf("\n5..Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);      // Read the user choice

        switch (ch) {
            case 1:
                printf("Enter chat name: ");
                scanf("%s", name);    // Read the chat name
                head = add_chat(head, name);   // Add the new chat
                display(head);                 // Display the updated list
                break;

            case 2:
                printf("Enter chat name: ");
                scanf("%s", name);    // Read the chat name to pin
                head = pin_chat(head, name);   // Pin the chat
                display(head);                 // Display the updated list
                break;

            case 3:
                printf("Enter chat name: ");
                scanf("%s", name);    // Read the chat name to delete
                head = delete_chat(head, name);  // Delete the chat
                display(head);                   // Display the updated list
                break;

            case 4:
                head = unpin_chat(head);         // Unpin the chat
                
                display(head);                   // Display the updated list
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}