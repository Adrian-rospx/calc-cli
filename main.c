#include <stdio.h>
#include <stdlib.h>

#include "tokenMat.h"
#include "tokenize.h"
#include "postfix.h"
#include "evaluate.h"

int main() {
    char* input = malloc(100 * sizeof(char));
    TokenMat tokens;
    int result;

    fgets(input, 100, stdin);

    // function to split up text into tokens
    tokenize(&tokens, input);

    printf("Starting tokens:\n");
    for(int i = 0; i < tokens.size; i++) {
        printf("%s ", tokens.mat[i]);
    }
    printf("\n");

    // convert to postfix
    toPostfix(&tokens);

    printf("Postfix conversion:\n");
    for(int i = 0; i < tokens.size; i++) {
        printf("%s ", tokens.mat[i]);
    } 
    printf("\n");

    // evaluate the postfix expression
    result = evaluate(tokens);
    
    // output result:
    printf("Final result:\n");
    printf("%d\n", result);

    // always free up the memory!
    tokenFree(&tokens);
    free(input);
    input = NULL;

    return 0;
}