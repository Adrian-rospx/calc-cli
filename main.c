#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeWhitespace(char* text);

int main() {
    char* input = (char*)malloc(100 * sizeof(char));

    fgets(input, 100, stdin);

    removeWhitespace(input);

    printf("%s\n", input);

    free(input);
    return 0;
}

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
