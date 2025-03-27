// postfix conversion implementation
#include <string.h>
#include <ctype.h>

#include "tokenMat.h"
#include "stack.h"
#include "queue.h"

#include "postfix.h"

void toPostfix(TokenMat* tokens);

// check if last item in stack has precedence over current one
int precedence(char oper, Stack* stack) {
    if(stack->size == 0)
        return 0;
    // precedence for ^ over /*
    if(strchr("+-", oper) && strchr("^*/", stkTop(stack)[0]))
        return 1;
    // precedence for */^ over +-
    if(strchr("*/", oper) && strchr("^", stkTop(stack)[0]))
        return 1;
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
            if(precedence(arr[0], &stack)) {
                // find the same priority operator
                char rev;
                switch(arr[0]) {    
                    case '+': rev = '-'; break;
                    case '-': rev = '+'; break;
                    case '*': rev = '/'; break;
                    case '/': rev = '*'; break;
                    case '^': rev = '^'; break;
                }
                // pop until a same priority operator is found
                do {
                    // pop value from stack
                    char* op = stkTop(&stack);
                    stkPop(&stack);
                    // enqueue it
                    enqueue(&queue, op);
                }while(stkTop(&stack)[0] != arr[0] &&
                       stkTop(&stack)[0] != rev &&
                       stack.size != 0);
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