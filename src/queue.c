#include <stdlib.h>
#include <string.h>

#include "queue.h"

// initialize queue
void queueInit(Queue* queue) {
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
}

// add strings to queue
void enqueue(Queue* queue, char* str) {
    // allocate memory
    Node* newnode = malloc(sizeof(Node));
    strcpy(newnode->str, str);
    newnode->next = NULL;
    // assign string
    strcpy(newnode->str, str);

    // handle the 0 case
    if(queue->size == 0) {
        queue->tail = newnode;
        queue->head = newnode;
        // assign string and change size
        queue->size = 1;
        return;
    }
    // reassign the tail to the new Node
    queue->tail->next = newnode;
    queue->tail = newnode;

    queue->size++;
}
// eliminate queue element
void dequeue(Queue* queue) {
    // the memory and reassign the head pointer
    Node* pnext = queue->head->next;
    free(queue->head);
    queue->head = pnext;

    queue->size--;
}
// get the first item in the queue
char* queueFront(Queue queue) {
    return queue.head->str;
}