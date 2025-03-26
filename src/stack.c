// stack array basic functions
#include <string.h>

#include "stack.h"

// start the stack values
void stkInit(Stack stack) {
    stack.size = 0;
    stack.top = -1;
}
// add a string on to the stack
void stkPush(Stack stack, char *str) {
    strcpy(stack.stk[stack.top], str);
    stack.top++;
}
// pop off a string from stack
void stkPop(Stack stack) {
    stack.top--;
}
// get top string
char* stkTop(Stack stack) {
    return stack.stk[stack.top];
}