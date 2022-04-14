#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *createNode(int value);

void insertFront(node **head, int value);

void displayLL(node *head);

int main()
{
    node *head = createNode(5);
    insertFront(&head, 1);
    displayLL(head);
    return 1;
}

node *createNode(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(node **head, int value)
{
    // Case 0: |LL| == 0.
    if (!*head)
        *head = createNode(value);
    // Case 0: |LL| > 0.
    else
    {
        node *newNode = createNode(value);
        node *tmp = *head;
        tmp->prev = newNode;
        newNode->next = tmp;
        *head = newNode;
    }
}

void displayLL(node *head)
{
    while (head)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}