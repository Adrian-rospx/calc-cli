// postfix evaluation
#include <string.h>
#include <math.h>

#include "tokenMat.h"
#include "stack.h"
#include "calcTypes.h"

#include "evaluate.h"

int evaluate(TokenMat tokens);

int operate(char* a, char* b, char operator) {
    int numA = convertToInt(a);
    int numB = convertToInt(b);

    switch(operator) {
    case '+':
        return numA + numB;
    case '-':
        return numA - numB;
    case '*':
        return numA * numB;
    case '/':
        return numA / numB;
    case '^':
        return (int)pow(numA, numB);
    default:
        return 0;
    }
}

int evaluate(TokenMat tokens) {
    // use a stack to evaluate each token
    Stack stack;
    stkInit(&stack);
    int result = 0;

    for(int i = 0; i < tokens.size; i++) {
        // numbers are added to the stack
        if(isNumber(tokens.mat[i])) {
            stkPush(&stack, tokens.mat[i]);
        }
        // two items are popped and operated on
        // when an operator is found
        else if(isOperator(tokens.mat[i][0])) {
            char itemB[10];
            strcpy(itemB, stkTop(&stack));
            stkPop(&stack);

            char itemA[10];
            strcpy(itemA, stkTop(&stack));
            stkPop(&stack);
            // perform operation
            int num = operate(itemA, itemB, tokens.mat[i][0]);
            // convert result to a string
            char res[10];
            res[0] = '\0';
            convertIntToStr(res, num);
            // add result back on the stack
            stkPush(&stack, res);
        }
    }

    result = convertToInt(stkTop(&stack));
    return result;
}
