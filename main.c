#include "include/tokenize.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    char* input = (char*)malloc(100 * sizeof(char));
    char tokens[20][10];

    fgets(input, 100, stdin);

    removeWhitespace(input);
    tokenize(tokens, input);

    printf("%s\n", input);

    for(int i = 0; tokens[i][0] != '\0'; i++) {
        printf("%s\n", tokens[i]);
    }

    free(input);
    return 0;
}
