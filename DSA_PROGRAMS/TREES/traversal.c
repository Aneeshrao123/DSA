#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node{
    int data;
    struct node* left;
    struct node *right;
};

// Function to create a new node
struct node *create_node(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// Function to build the binary tree
struct node* buildtree()
{
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if(data == -1) {
        return NULL;  // Return NULL if no node should be created
    }

    // Create a new node with the given data
    struct node* newnode = create_node(data);

    // Build the left subtree
    printf("Enter the left child of %d:\n", data);
    newnode->left = buildtree();

    // Build the right subtree
    printf("Enter the right child of %d:\n", data);
    newnode->right = buildtree();

    return newnode;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct node* node)
{
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Preorder traversal (Root, Left, Right)
void preorder(struct node* node)
{
    if(node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Postorder traversal (Left, Right, Root)
void postorder(struct node* node)
{
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    struct node* root = NULL;
    printf("Build your tree:\n");
    root = buildtree();

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    return 0;
}
