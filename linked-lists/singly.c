#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node;

void displayLL(node*head);

node * createNode(int data);

node * insertFront(node* head, int data);

node * insertEnd(node * head, int data);

node * deleteNode(node * head, int data);

node * recursiveDelete(node * head, int data);

node * insertSort(node * head, int data);

int main() {
	node * head = malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;
	displayLL(head);
	head = insertFront(head, 5);
	displayLL(head);
	head = insertEnd(head, 10);
	displayLL(head);
	head = recursiveDelete(head, 5);
	displayLL(head);
	head = insertSort(head, 5);
	displayLL(head);
}


node * insertSort(node * head, int data) {

	node * newNode;
	node * tmp;

	newNode = (node *) malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL | head->data >= data) {
		newNode->next = head;
		head = newNode;
	} else {
		tmp = head;
		while (tmp->next != NULL && tmp->next->data < data)
			tmp = tmp->next;
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	return head;
}


node * recursiveDelete(node * head, int data) {
	if (head == NULL)
		return head;

	if (head->data == data) {
		node *tmp;
		tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}
	head->next = recursiveDelete(head->next, data);
	return head;
}

node * createNode(int data) {
	node * tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

node * insertFront(node* head, int data) {
	node * newNode = createNode(data);		
	if (head == NULL)
		head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
	return head;
}

node * insertEnd(node * head, int data) {
	node * tmp = head;
	node * newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
		head = tmp;
	else {
		while(tmp->next != NULL) {
		    tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	return head;
}

void displayLL(node*head) {
 
    node * tmp = head;
    if (head == NULL)
        printf("Linked list is empty.\n");
    else {
        printf("%d->", tmp->data);
        while (tmp->next != NULL) {
            printf("%d->", tmp->next->data);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}

node * deleteNode(node * head, int data) {
    node * prev = NULL;	
    node * tmp = head;
    if (head == NULL)
        printf("List is empty\n");
    while (tmp->next != NULL) {
        if (tmp->data == data) {
            if(prev != NULL) {
                prev->next = tmp->next;
	        head = prev;
	    }
	    else head = tmp->next;
            free(tmp);
            printf("%d deleted.\n", data); 
            return head;
        }
	prev = tmp;
	tmp = tmp->next;
    }
    printf("Node with value %d not found.\n", data);
}
