#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
} node;

void insertNodeFront(node **head, int value);

void deleteNode(node **head, int value);

void displayList(node *head);

int main()
{
	node *head = malloc(sizeof(node));
	head->data = 0;
	head->next = head;
	head->prev = head;
	insertNodeFront(&head, 1);
	displayList(head);
	insertNodeFront(&head, 2);
	displayList(head);

	return 1;
}

void insertNodeFront(node **head, int value)
{
	node *newNode = malloc(sizeof(node));
	newNode->data = value;

	// Case 0: LL is empty
	if (!*head)
	{
		*head = newNode;
	}

	// Case 1: |LL| == 1
	else if ((*head)->next == (*head))
	{
		newNode->next = (*head);
		newNode->prev = (*head);
		(*head)->next = newNode;
		(*head)->prev = newNode;
		(*head) = newNode;
	}
	// Case 2: |LL| > 1
	else
	{
		(*head)->prev->next = newNode;
		newNode->next = *head;
		newNode->prev = (*head)->prev;
		*head = newNode;
	}
}

void displayList(node *head)
{
	if (!head)
		printf("LL is empty.\n");
	else
	{
		node *tmp = head;
		while (tmp->next != head)
		{
			printf("%d->", tmp->data);
			tmp = tmp->next;
		}
		printf("%d->\n", tmp->data);
	}
}