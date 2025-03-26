// token array for easier manipulation

#ifndef TOKEN_MAT_H
#define TOKEN_MAT_H

typedef struct TokenMat{
    char** mat;
    int size;
    int alloc;
} TokenMat;

void tokensInit(TokenMat* tk, int size);
void tokenFree(TokenMat* tk);

#endif