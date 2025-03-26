// postfix conversion implementation
#include <string.h>
#include <ctype.h>

#include "tokenMat.h"
#include "stack.h"
#include "queue.h"

#include "postfix.h"

void toPostfix(TokenMat* tokens);

// check if last item in stack has precedence over current one
int precedence(char* str, Stack stack) {
    if(stack.size == 0) {
        return 0;
    }
    if(strchr("*/", str[0])) {
        return 0;
    }
    // precedence for */ over +-
    if(strchr("+-", str[0]) && strchr("*/", stkTop(&stack)[0])) {
        return 1;
    }
    return 0;
}

void toPostfix(TokenMat* tokens) {
    // begin the queue
    Queue queue;
    queueInit(&queue);
    // begin the stack
    Stack stack;
    stkInit(&stack);

    for(int i = 0; i<tokens->size; i++) {
        char* arr = tokens->mat[i];
        if(isdigit(arr)) {
            enqueue(&queue, arr);
        }
        else if(!strcmp(arr, "("))
            stkPush(&stack, arr);
        // handle operators:
        else if(strchr("+-*/", arr[0])) {
            if(precedence(arr, stack)) {
                // pop value from stack
                char* op = stkTop(&stack);
                stkPop(&stack);
                // enqueue it
                enqueue(&queue, op);
                // push symbol
                stkPush(&stack, arr);
            }
            else
                stkPush(&stack, arr);
        }
        // when a right parathesis is found pop from stack until (
        else if(!strcmp(arr, ")")) {
            while(!strchr(stkTop(&stack), '(')) {
                // pop from stack
                char* op = stkTop(&stack);
                stkPop(&stack);
                // enqueue
                enqueue(&queue, op);
            }
            // pop the left parathesis
            stkPop(&stack);
        }
    }
    // now the queue contains the whole postfix notation
    TokenMat newtokens;
    tokensInit(&newtokens, 30);
}