#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeWhitespace(char** text);

int main() {
    char* input = (char*)malloc(100 * sizeof(char));

    fgets(input, 100, stdin);

    removeWhitespace(input);

    printf("%s\n", input);

    return 0;
}

// remove all whitespace from the string input
void removeWhitespace(char **text) {
    // works using strtok to add 
    // all words ignoring whitespace
    char copy[100];
    char result[100];
    result[0] = 0;

    strcpy(copy, *text);

    char* ptr;
    ptr = strtok(copy, " \n\t");
    while(ptr != NULL) {
        strcat(result, ptr);
        ptr = strtok(NULL, " \n\t");
    }

    *text = result;
}
