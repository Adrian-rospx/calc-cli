#include <string.h>

#include "stack.h"

// add a string on to the stack
void stk_push(Stack stack, char *str) {
    strcpy(stack.stk[stack.top], str);
    stack.top++;
}
// pop off a string from stack
void stk_pop(Stack stack) {
    stack.top--;
}
// get top string
char* stk_top(Stack stack) {
    return stack.stk[stack.top];
}