// postfix conversion implementation
#include <string.h>
#include <ctype.h>

#include "tokenMat.h"
#include "stack.h"
#include "queue.h"

#include "postfix.h"

void toPostfix(TokenMat* tokens);

// return an intager indicating operator precedence
int precedence(char operator) {
    if(operator == '+' || operator == '-')
        return 1;
    else if(operator == '*' || operator == '/')
        return 2;
    else if(operator == '^')
        return 3;
    else 
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
        // just enqueue numbers
        if(isdigit(arr[0])) {
            enqueue(&queue, arr);
        }
        // handle operators:
        else if(strchr("+-*/^", arr[0])) {
            // ensure operators with precedence are first in stack
            if(precedence(arr[0]) < precedence(stkTop(&stack)[0])) 
            while(precedence(arr[0]) <= precedence(stkTop(&stack)[0])
                  && stack.size != 0){
                // pop value from stack
                char* op = stkTop(&stack);
                stkPop(&stack);
                // enqueue it
                enqueue(&queue, op);
            }
            // push symbol
            stkPush(&stack, arr);
        }
        // just add the left paranthesis
        else if(arr[0] == '(')
            stkPush(&stack, arr);
        // when a right parathesis is found pop 
        // from stack until '(' is found
        else if(arr[0] == ')') {
            while(stkTop(&stack)[0] != '(') {
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
    // put all stack items into queue
    while(stack.size != 0) {
        enqueue(&queue, stkTop(&stack));
        stkPop(&stack);
    }

    TokenMat newtokens;
    tokensInit(&newtokens, 30);
    // put queue items into tokenmat
    int i = 0;
    while(queue.size != 0) {
        strcpy(newtokens.mat[i], queueFront(queue));
        dequeue(&queue);
        i++;
    }
    newtokens.size = i;
    // assign and free up the old values
    tokenFree(tokens);
    *tokens = newtokens;
}