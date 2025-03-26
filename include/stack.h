/*
 *  Stack implementation using arrays
 *  for implementing postfix conversion
 */

typedef struct Stack {
    char stk[30][10];
    int top = 0;
    int size = 30;
}Stack;

void stk_push(Stack stack, char* str);
void stk_pop(Stack stack);
void stk_top(Stack stack);