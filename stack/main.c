
// Author: Brandon Gevat
// Basic array-based implementation of stack.
// All operations are O(1) run-time.

#include <stdio.h>
#include <stdlib.h>

// Change this to change the maximum amount of items in the stack.
#define MAX 10

typedef struct stack
{
    int items[MAX];
    int count;
    int top;
} stack;

void initStack(stack *s)
{
    s->count = 0;
    s->top = -1;
}

int isFull(stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

void push(stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->items[s->top] = item;
    s->count++;
}

void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty");
        return;
    }
    printf("%d popped\n", s->items[s->top]);
    s->top--;
    s->count--;
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

// TODO: displayStack
void displayStack(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i < s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Driver code
int main()
{
    // Initialize the stack.
    stack *s = malloc(sizeof(stack));
    initStack(s);

    displayStack(s);

    // Testing isEmpty().
    int empty = isEmpty(s);
    printf("Empty: %d\n", empty);

    // Testing isFull().
    int full = isFull(s);
    printf("Full: %d\n", full);

    // Testing push().
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    displayStack(s);

    // Testing isFull().
    full = isFull(s);
    printf("Full: %d\n", full);

    // Testing pop().
    pop(s);

    // Testing peek().
    int item = peek(s);
    printf("Current top: %d\n", item);

    return 0;
}
