// Author: Brandon Gevat
// Array-based implementation of queue
// Disadvantage(s): static size

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front, rear, size;
    int *arr;
    int cap;
} queue;

queue *createQueue(int cap);

int isFull(queue *q);

int isEmpty(queue *q);

void enqueue(queue *q, int value);

int dequeue(queue *q);

int peek(queue *q);

void displayQueue(queue *q);

int main()
{
    // Testing initialization
    queue *q = createQueue(10);

    // Testing enqueue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    displayQueue(q);

    // Testing dequeue
    dequeue(q);
    displayQueue(q);
    enqueue(q, 3);
    displayQueue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    displayQueue(q);

    return 0;
}

queue *createQueue(int cap)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->cap = cap;
    q->front = q->size = 0;
    q->rear = cap - 1;
    q->arr = (int *)malloc(q->cap * sizeof(int));
}

int isFull(queue *q)
{
    return q->size == q->cap;
}

int isEmpty(queue *q)
{
    return q->size == 0;
}

void enqueue(queue *q, int value)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = value;
    q->size++;
    printf("Enqueue: %d\n", value);
}

int dequeue(queue *q)
{
    if (isEmpty(q))
        return -1;
    int ret = peek(q);
    q->front = (q->front + 1) % q->cap;
    q->size--;
    return ret;
}

int peek(queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->arr[q->front];
}

void displayQueue(queue *q)
{
    int index = 0;
    for (int i = 0; i < q->size; i++)
    {
        index = (q->front + i) % q->cap;
        printf("%d ", q->arr[index]);
    }
    printf("\n");
}
