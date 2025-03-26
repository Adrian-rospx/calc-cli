#include <stdlib.h>

#include "queue.h"

// initialise queue
void queueInit(Queue queue) {
    queue.size = 0;
}

// add strings to queue
void enqueue(Queue queue, char* str) {
    if(queue.size == 0) {
        // allocate memory
        queue.tail = malloc(sizeof(Node));
        queue.head = malloc(sizeof(Node));
        queue.head = queue.tail;
        // assign string and change size
        strcpy(queue.tail->str, str);
        queue.size++;
        return;
    }
    // reassign the tail to the new Node
    queue.tail->next = malloc(sizeof(Node));
    queue.tail = queue.tail->next;
    // assign string and change size
    strcpy(queue.tail->str, str);
    queue.size++;
}
// eliminate queue element
void dequeue(Queue queue) {
    // the memory and reassign the head pointer
    Node* next = queue.head->next;
    free(queue.head);
    queue.head = next;

    queue.size--;
}
// get the first item in the queue
char* queueFront(Queue queue) {
    return queue.head;
}

