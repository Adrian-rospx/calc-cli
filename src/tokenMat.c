// token mat implementation

#include <stdlib.h>

#include "tokenMat.h"

// initialises the token array, token size = 10 chars!
void tokensInit(TokenMat* tk, int dim) {
    tk->alloc = dim;
    tk->size = dim;

    // allocate memory for the matrix
    tk->mat = malloc(sizeof(int*) * dim);

    // alocate memory for each array
    for(int i=0; i<dim; i++) {
        tk->mat[i] = malloc(sizeof(int) * 10);
    }
}

// free the memory allocated to tokens
void tokenFree(TokenMat* tk) {
    for(int i = 0; i<tk->alloc; i++) {
        free(tk->mat[i]);
    }
    free(tk->mat);
    
    tk->mat = NULL;
    tk->alloc = 0;
    tk->size = 0;
}