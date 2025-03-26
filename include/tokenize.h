/*
 *  Functions for basic string processing,
 *  preparing data for evaluation
 */

#ifndef TOKENIZE_H
#define TOKENIZE_H

void removeWhitespace(char *text);

void tokenize(char mat[20][10], char *text);

#endif