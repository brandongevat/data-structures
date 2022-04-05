#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} node;

node * createNode(int value);

void insertNode(node ** root, node * newNode);

void displayPreOrder(node * root);

void displayInOrder(node * root);

void displayPostOrder(node * root);

int main() {
    node * root = createNode(5);
    node * newNode = createNode(3);
    insertNode(&root, newNode);
    newNode = createNode(4);
    insertNode(&root, newNode);
    newNode = createNode(2);
    insertNode(&root, newNode);
    newNode = createNode(6);
    insertNode(&root, newNode);
    printf("Pre-order:\n");
    displayPreOrder(root);
    printf("In-order:\n");
    displayInOrder(root);
    printf("Post-order:\n");
    displayPostOrder(root);
    return 1;
}

node * createNode(int value) {
    node * newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(node ** root, node * newNode) {
    if (*root == NULL) {
        *root = newNode;
    } else if ((*root)->data < newNode->data) {
        insertNode(&((*root)->right), newNode);
    } else {
        insertNode(&((*root)->left), newNode);
    } 
}

void displayPreOrder(node * root) {
    if (!root)
        return;
    printf("%d\n", root->data);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayInOrder(node * root) {
    if (!root)
        return;
    displayInOrder(root->left);
    printf("%d\n", root->data);
    displayInOrder(root->right);
}

void displayPostOrder(node * root) {
    if (!root)
        return;
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    printf("%d\n", root->data);
}