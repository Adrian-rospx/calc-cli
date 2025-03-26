/*
 *  Creates a struct useful for storing tokens when processing
 */
#include <stdlib.h>

#include "../include/tokenMat.h"

// initialises the token array, token size = 10 chars!
void tokensInit(TokenMat tk, int size) {
    tk.size = size;

    // allocate memory for the matrix
    tk.mat = malloc(sizeof(int*) * size);

    // alocate memory for each array
    for(int i=0; i<size; i++) {
        tk.mat[i] = malloc(sizeof(int) * 10);
    }
}

// free the memory allocated to tokens
void tokenFree(TokenMat tk) {
    for(int i = 0; i<tk.size; i++) {
        free(tk.mat[i]);
    }
    free(tk.mat);
}