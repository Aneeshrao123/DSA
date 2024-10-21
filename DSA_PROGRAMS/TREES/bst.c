#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct node {
    int data;
    struct node *left, *right;
};
// Insert function without using double pointers
struct node* insert(struct node *root, int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;

    if (root == NULL) {
        return temp;  // Return new node as root if tree is empty
    }

    struct node *curr = root;
    struct node *prev = NULL;

    // Traverse to find the correct position
    while (curr != NULL) {
        prev = curr;
        if (x > curr->data) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (x > prev->data) {
        prev->right = temp;
    } else {
        prev->left = temp;
    }

    return root;  // Return the root of the tree
}

// Preorder traversal
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Count the total number of nodes in the tree
int count(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

// Count the number of leaf nodes
int leafcount(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leafcount(root->left) + leafcount(root->right);
}

// Find the height of the tree
int height(struct node *root) {
    if (root == NULL) {
        return -1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

// Iterative search for a key in the tree
int search(struct node *root, int key) {
    struct node *curr = root;

    while (curr != NULL) {
        if (curr->data == key) {
            return 1;  // Key found
        }
        if (key > curr->data) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return 0;  // Key not found
}

// Recursive search for a key in the tree
int rsearch(struct node *root, int key) {
    if (root == NULL) {
        return 0;  // Key not found
    }
    if (root->data == key) {
        return 1;  // Key found
    }
    if (key < root->data) {
        return rsearch(root->left, key);  // Search in the left subtree
    }
    return rsearch(root->right, key);  // Search in the right subtree
}

// Find the minimum value in the tree
int minimum(struct node *root) {
    if (root == NULL) {
        return -1;  // Tree is empty
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Find the maximum value in the tree
int maximum(struct node *root) {
    if (root == NULL) {
        return -1;  // Tree is empty
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Delete a node from the tree
struct node* delete_node(struct node *root, int key) {
    if (root == NULL) {
        return root;  // Tree is empty
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, find inorder successor
        struct node *temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        // Replace root with inorder successor
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}



// Main function
int main() {
    struct node *root = NULL;  // Initialize the root to NULL
    int ch, num, result;

    while (1) {
        printf("\n1. Insert");
        printf("\n2. Preorder");
        printf("\n3. Postorder");
        printf("\n4. Inorder");
        printf("\n5. Count nodes");
        printf("\n6. Count leaf nodes");
        printf("\n7. Height of tree");
        printf("\n8. Search");
        printf("\n9. Recursive search");
        printf("\n10. Find minimum");
        printf("\n11. Find maximum");
        printf("\n12. Delete a node");
        printf("\n13. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &num);
                root = insert(root, num);  // Capture the updated root
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                printf("Number of nodes: %d\n", count(root));
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", leafcount(root));
                break;
            case 7:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &num);
                result = search(root, num);
                if (result) printf("Key found\n");
                else printf("Key not found\n");
                break;
            case 9:
                printf("Enter the element to search (recursively): ");
                scanf("%d", &num);
                result = rsearch(root, num);
                if (result) printf("Key found\n");
                else printf("Key not found\n");
                break;
            case 10:
                printf("Minimum value: %d\n", minimum(root));
                break;
            case 11:
                printf("Maximum value: %d\n", maximum(root));
                break;
            case 12:
                printf("Enter the element to delete: ");
                scanf("%d", &num);
                root = delete_node(root, num);
                break;
            case 13:
                exit(0);
        }
    }
    return 0;
}

