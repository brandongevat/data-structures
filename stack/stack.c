#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int top;
	int *arr;
	unsigned cap;
} stack;

struct stack *createStack(unsigned cap);

void displayStack(stack *s);

int isEmpty(stack *s);

int isFull(stack *s);

int size(stack *s);

int peek(stack *s);

int pop(stack *s);

void push(stack *s, int value);

int main()
{
	stack *s = createStack(5);
	push(s, 1);
	push(s, 2);
	push(s, 4);
	push(s, 6);
	push(s, 8);
	displayStack(s);
	pop(s);
	pop(s);
	displayStack(s);
	push(s, 10);
	push(s, 12);
	displayStack(s);
	push(s, 14);

	return 0;
}

int isEmpty(stack *s)
{
	return s->top == -1;
}

int isFull(stack *s)
{
	return s->top == s->cap - 1;
}

int size(stack *s)
{
	return s->top + 1;
}

int peek(stack *s)
{
	if (isEmpty(s))
		exit(EXIT_FAILURE);
	return s->arr[s->top];
}

int pop(stack *s)
{
	if (isEmpty(s))
		exit(EXIT_FAILURE);
	printf("Popping %d.\n", peek(s));
	return s->arr[s->top--];
}

void push(stack *s, int value)
{
	if (isFull(s))
		return;
	s->arr[++s->top] = value;
	printf("Inserted %d.\n", value);
}

struct stack *createStack(unsigned cap)
{
	stack *s = malloc(sizeof(stack));
	s->arr = malloc(cap * sizeof(int));
	s->cap = cap;
	s->top = -1;
	return s;
}

void displayStack(stack *s)
{
	for (int i = s->top; i >= 0; i--)
	{
		printf("%d\n", s->arr[i]);
	}
}
