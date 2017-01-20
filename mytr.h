
#ifndef MYTRHEADER
#define MYTRHEADER

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

#endif

void genHash( char *table,char *str1, char *str2 );
int replace( char keys[], char values[] );
void translate( char *table);
char unescape(char c);
