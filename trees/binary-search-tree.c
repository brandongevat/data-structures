#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int value);

void insertNode(node **root, node *newNode);

node *findNode(node *root, int value);

node *findMinNode(node *root);

node *deleteNode(node *root, int value);

void displayPreOrder(node *root);

void displayInOrder(node *root);

void displayPostOrder(node *root);

int treeSum(node *root);

int getHeight(node *root);

int main()
{
    node *root = createNode(5);
    printf("First node of the tree:\n%d\n", root->data);

    node *newNode = createNode(3);
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

    int height = getHeight(root);
    printf("Current height: %d\n", height);

    int sum = treeSum(root);
    printf("Sum of the current tree: %d\n", sum);

    root = deleteNode(root, 3);
    printf("In-order:\n");
    displayInOrder(root);

    root = deleteNode(root, 4);
    printf("In-order:\n");
    displayInOrder(root);

    sum = treeSum(root);
    printf("Sum of the current tree: %d\n", sum);

    height = getHeight(root);
    printf("Current height: %d\n", height);

    return 1;
}

node *createNode(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(node **root, node *newNode)
{
    // Case 0: Current node is empty, so add the node to the tree.
    if (!*root)
    {
        *root = newNode;
        printf("%d inserted.\n", newNode->data);
    }

    // Case 1: Current node < node to be inserted, traverse to larger node (right-ways).
    else if ((*root)->data < newNode->data)
        insertNode(&((*root)->right), newNode);

    // Case 2: Current node > node to be insert, traverse to smaller node (left-ways).
    else
        insertNode(&((*root)->left), newNode);
}

node *findNode(node *root, int value)
{
    // Case 0: Tree is empty.
    if (!root)
        return NULL;

    // Case 1: Current node is the node we're looking for.
    else if (root->data == value)
    {
        printf("%d found.\n", value);
        return root;
    }

    // Case 2: Current node is not the value we're looking for. So, traverse down the tree.
    else
    {
        findNode(root->left, value);
        findNode(root->right, value);
    }
}

node *findMinNode(node *root)
{
    node *tmp = root;
    while (tmp && tmp->left)
    {
        tmp = tmp->left;
    }
    return tmp;
}

node *deleteNode(node *root, int value)
{
    // Case 0: Current node is NULL.
    if (!root)
        return root;

    // Case 1: root is < value
    if (root->data < value)
        root->right = deleteNode(root->right, value);

    // Case 2: root is > value
    else if (root->data > value)
        root->left = deleteNode(root->left, value);

    // Case 3: Current node is the node to be deleted.
    else
    {
        node *tmp;
        // Case 3.1: Node has only right child or no children.
        // Thus, set the current node to the right child and free the current node.
        if (root->left == NULL)
        {
            tmp = root->right;
            free(root);
            return tmp;
        }

        // Case 3.2: Node has only left child or no children.
        // Thus, set the current node to the left child and free the current node.
        else if (root->right == NULL)
        {
            tmp = root->left;
            free(root);
            return tmp;
        }

        // Case 3.3: Node has two children. So find the least alue node of the right-most node,
        // and set the current node to that one. Then, find and delete the least value node of
        // the right-most node.
        tmp = findMinNode(root->right);

        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}

void displayPreOrder(node *root)
{
    if (!root)
        return;
    printf("%d\n", root->data);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayInOrder(node *root)
{
    if (!root)
        return;
    displayInOrder(root->left);
    printf("%d\n", root->data);
    displayInOrder(root->right);
}

void displayPostOrder(node *root)
{
    if (!root)
        return;
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    printf("%d\n", root->data);
}

int treeSum(node *root)
{
    if (!root)
        return 0;

    return (root->data + treeSum(root->left) + treeSum(root->right));
}

int getHeight(node *root)
{
    if (!root)
        return -1;
    else
    {
        int l = getHeight(root->left);
        int r = getHeight(root->right);

        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}