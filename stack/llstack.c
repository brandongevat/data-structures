#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
	int data;
	struct stackNode * next;
} stackNode;

void displayStack(stackNode * top);

stackNode * createNode(int data); 

int isEmpty(stackNode *top);

void push(stackNode ** top, int data);

int pop(stackNode ** top);

int peek(stackNode * top);
	
int main() {
	stackNode * top = createNode(0);
	displayStack(top);
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	displayStack(top);
	pop(&top);
	displayStack(top);
}

void displayStack(stackNode *top) {
	stackNode *tmp = top;
	
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

stackNode * createNode(int data) {
	stackNode * newNode = malloc(sizeof(stackNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int isEmpty(stackNode *top) {
	return top == NULL;
}

void push(stackNode ** top, int data) {
	stackNode *newNode = createNode(data);

	newNode->next = *top;
	*top = newNode;
}

int pop(stackNode ** top) {
	stackNode * tmp = *top;
	if (isEmpty(*top)) 
		exit(EXIT_FAILURE);
	*top = (*top)->next;
	int ret = (*top)->data;
	free(tmp);
	return ret;
	
	
}


int peek(stackNode * top) {
	if (isEmpty(top))
		exit(EXIT_FAILURE);
	return top->data;
}
