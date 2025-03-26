/*
 *  Queue implementation using linked lists
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node{
    char* str;
    Node* next;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
    int size;
} Queue;

#endif