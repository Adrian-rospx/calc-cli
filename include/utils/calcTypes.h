/*
 *  functions for identifying and converting 
 *  tokens and numbers
 */

#ifndef TYPES_H
#define TYPES_H

int isOperator(char token);
int isNumber(char* token);

int convertToInt(char* token);
void convertIntToStr(char* str, int num);

#endif