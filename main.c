#include <stdio.h>
#include <stdlib.h>

#include "tokenMat.h"
#include "tokenize.h"
#include "postfix.h"

int main() {
    char* input = malloc(100 * sizeof(char));

    fgets(input, 100, stdin);

    // function to split up text into tokens
    TokenMat tokens;
    tokenize(&tokens, input);

    for(int i = 0; i < tokens.size; i++) {
        printf("%s", tokens.mat[i]);
    }
    printf("\n");

    // convert to postfix
    toPostfix(&tokens);
    for(int i = 0; i < tokens.size; i++) {
        printf("%s ", tokens.mat[i]);
    }

    // always free up the memory!
    tokenFree(&tokens);
    free(input);
    input = NULL;

    return 0;
}