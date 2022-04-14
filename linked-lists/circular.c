#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

void insertFront(node **head, int value);

void insertEnd(node **head, int value);

void insertInorder(node **head, int value);

void delete(node **head, int value);

void displayList(node *head);

int main()
{
	node *head = malloc(sizeof(node));
	head->data = 0;
	head->next = head;
	displayList(head);
	insertFront(&head, 1);
	displayList(head);
	insertFront(&head, 2);
	displayList(head);
	insertEnd(&head, -1);
	displayList(head);
	delete(&head, 0);
	displayList(head);
	delete(&head, 2);
	displayList(head);
	delete(&head, 1);
	displayList(head);

	return 1;
}

void insertFront(node **head, int value)
{
	node *newNode = malloc(sizeof(node));

	newNode->data = value;

	// Case 0: LL is empty.
	if (!*head)
	{
		newNode->next = newNode;
		printf("%d inserted at the front of the list.\n", value);
		*head = newNode;
		return;
	}
	// Case 1: |LL| > 0
	node *tmp = *head;
	while (tmp->next != *head)
	{
		tmp = tmp->next;
	}
	newNode->next = *head;
	tmp->next = newNode;
	*head = newNode;
	printf("%d inserted at the front of the list.\n", value);
}


void insertEnd(node **head, int value) {
	node * newNode = malloc(sizeof(node));
	
	newNode->data = value;

	// Case 0: |LL| == 0.
	if (!*head)
	{
		newNode->next = newNode;
		printf("%d inserted at the back of the list\n", value);
		*head = newNode;
		return;

	}
	// Case 1 |LL| > 1.
	node *tmp = *head;
	while (tmp->next != *head) {
		tmp = tmp->next;
	}
	newNode->next = *head;
	tmp->next = newNode;
	printf("%d inserted at the end of the list.\n", value);

}

void insertEnd(node **head, int value);

void insertInorder(node ** head, int value);

void delete(node **head, int value)
{

	node *tmp = *head;
	if (!*head)
		printf("LL is empty. Cannot delete %d.\n", value);

	// Case 1: |LL| == 1
	else if ((*head)->next == *head && (*head)->data == value)
	{
		free(*head);
		printf("%d deleted.\n", value);
		*head = NULL;
	}
	// Case 2: Head is the node to be deleted && |LL| > 1
	else if ((*head)->data == value)
	{
		while (tmp->next != (*head) && tmp->next->data != value)
		{
			tmp = tmp->next;
		}
		tmp->next = (*head)->next;
		free(*head);
		printf("%d deleted.\n", value);
		*head = tmp->next;
	}
	// Case 3: |LL| > 1
	else
	{
		while (tmp->next != *head && tmp->next->data != value)
		{
			tmp = tmp->next;
		}
		if (tmp->next->data == value)
		{
			node *del = tmp->next;
			tmp->next = del->next;
			free(del);
			printf("%d deleted.\n", value);
		}
		else
			printf("Node not found.\n");
	}
}

void displayList(node *head)
{
	if (!head)
	{
		printf("LL is empty. Cannot display.\n");
		return;
	}
	node *tmp = head;
	while (tmp->next != head)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("%d->\n", tmp->data);
}
