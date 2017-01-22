
#ifndef MYTRHEADER
#define MYTRHEADER

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

#endif

void genHash( char *table,char *str1, char *str2 );
void delete(char *table,  char *str1 );
char unescape(char c);

int checkArgsDelete(int argc, char *argv[]);
