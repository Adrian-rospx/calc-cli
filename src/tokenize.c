/*
 *  Functions for processing text
 */

#include <string.h>
#include <ctype.h>
#include "../include/tokenize.h"

// remove all whitespace from the string input
void removeWhitespace(char *text) {
    // works using two pointers traversing the string.
    //  one copies if the condition is met
    //  and the other one traverses
    char* dest = text;
    for(char* source = text; *source!='\0'; source++) {
        // when not a whitespace, a character is placed
        // in the original string
        if(!strchr(" \n\t", *source)) {
            *dest = *source;
            dest++;
        }
    }
    *dest = '\0';
}

// split string into tokens
void tokenize(char mat[20][10], char *text) {
    int i = 0; // Token index
    int j = 0; // character index in a token

    for(char* ptr = text; *ptr != '\0'; ptr++) {

        if(isdigit(*ptr)) {
            j = 0;  // store multi digit numbers
            while(isdigit(*ptr)){
                mat[i][j] = *ptr; 
                j++;
                ptr++;
            }
            mat[i][j] = '\0';   // nullifly
            i++;    // move to next token
            ptr--;  // account for extra increment
        }
        // handle operators:
        else if(strchr("+-*/()", *ptr)) {
            mat[i][0] = *ptr;
            mat[i][1] = '\0';
            i++;
        }
    }
}