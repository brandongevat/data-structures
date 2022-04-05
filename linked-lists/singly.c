#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

void displayLL(node *head);

node *createNode(int value);

void insertFront(node **head, int value);

void insertEnd(node **head, int value);

void deleteNode(node **head, int value);

node *recursiveDelete(node **head, int value);

void insertSort(node **head, int value);

int main()
{
	node *head = malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;
	displayLL(head);
	insertFront(&head, 5);
	displayLL(head);
	insertEnd(&head, 10);
	displayLL(head);
	recursiveDelete(&head, 5);
	recursiveDelete(&head, 10);
	displayLL(head);
	insertSort(&head, 5);
	displayLL(head);
}

node *createNode(int value)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = value;
	tmp->next = NULL;
	return tmp;
}

void insertFront(node **head, int value)
{
	node *newNode = createNode(value);
	if (*head == NULL)
		*head = newNode;
	else
	{
		newNode->next = *head;
		*head = newNode;
	}
	printf("%d inserted at the front.\n", value);
}

void insertSort(node **head, int value)
{

	node *newNode;
	node *tmp;

	newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;

	if (*head == NULL | (*head)->data >= value)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL && tmp->next->data < value)
			tmp = tmp->next;
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	printf("%d inserted at it's respective location.\n", value);
}

node *recursiveDelete(node **head, int value)
{
	if (*head == NULL)
		return *head;

	if ((*head)->data == value)
	{
		node *tmp;
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		printf("%d deleted recursively.\n", value);
		return *head;
	}
	(*head)->next = recursiveDelete(&((*head)->next), value);
	return *head;
}

void insertEnd(node **head, int value)
{
	node *tmp = *head;
	node *newNode = malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	if (*head == NULL)
		*head = tmp;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	printf("%d inserted at the end.\n", value);
}

void displayLL(node *head)
{

	node *tmp = head;
	if (head == NULL)
		printf("Linked list is empty. Cannot display.\n");
	else
	{
		printf("%d->", tmp->data);
		while (tmp->next != NULL)
		{
			printf("%d->", tmp->next->data);
			tmp = tmp->next;
		}
		printf("NULL\n");
	}
}

void deleteNode(node **head, int value)
{
	node *prev = NULL;
	node *tmp = *head;
	if (*head == NULL)
		printf("LL is empty. Cannot delete %d.\n", value);
	while (tmp->next != NULL)
	{
		if (tmp->data == value)
		{
			if (prev != NULL)
			{
				prev->next = tmp->next;
				*head = prev;
			}
			else
				*head = tmp->next;
			free(tmp);
			printf("%d deleted.\n", value);
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	printf("Node with value %d not found.\n", value);
}
