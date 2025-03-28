// token and number conversion
#include <string.h>

int isOperator(char token) {
    if(strchr("+-*/^()", token));
        return 1;
    return 0;
}

int isNumber(char* token) {
    for(int i=0; i<strlen(token); i++) {
        // return 0 when a non digit char is found
        if(token[i] < '0' || token[i] > '9')
            return 0;
    }
    return 1;
}

int convertToInt(char* token) {
    int num = 0;
    for(int i = 0; i<strlen(token); i++) {
        // convert the char to a digit
        int digit = token[i] - '0';
        if(token[i] == '0') digit = 0;
        // add to num
        num *= 10;
        num += digit;
    }
    return num;
}