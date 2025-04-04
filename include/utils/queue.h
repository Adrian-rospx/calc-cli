/*
 *  Queue implementation using linked lists
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node{
    char str[10];
    struct Node* next;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
    int size;
} Queue;

// basic queue operations
void queueInit(Queue* queue);
void enqueue(Queue* queue, char* str);
void dequeue(Queue* queue);
char* queueFront(Queue queue);

#endif