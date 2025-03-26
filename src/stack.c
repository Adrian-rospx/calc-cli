// stack array basic functions
#include <string.h>

#include "stack.h"

// start the stack values
void stkInit(Stack* stack) {
    stack->size = 0;
}
// add a string on to the stack
void stkPush(Stack* stack, char *str) {
    strcpy(stack->stk[stack->size], str);
    stack->size++;
    // handle stack overflow?
}
// pop off a string from stack
void stkPop(Stack* stack) {
    stack->size--;
    // handle stack underflow?
}
// get top string
char* stkTop(Stack* stack) {
    printf("%s\n", stack->stk[stack->size-1]);
    return stack->stk[stack->size-1];
}