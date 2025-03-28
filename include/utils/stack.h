/*
 *  Stack implementation using arrays
 *  for implementing postfix conversion
 */

#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    char stk[30][10];
    int size;
} Stack;

// basic functions:
void stkInit(Stack* stack);
void stkPush(Stack* stack, char* str);
void stkPop(Stack* stack);
char* stkTop(Stack* stack);

#endif