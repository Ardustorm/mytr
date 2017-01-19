
#ifndef MYTRHEADER
#define MYTRHEADER

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

#endif

int genHash( char *table,char *str1, char *str2 );
int replace( char keys[], char values[] );
void translate( char c , char keys[], char values[]);
char unescape(char c);
