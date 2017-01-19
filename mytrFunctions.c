
#include "mytr.h"

char unescape( char c ) {

  switch( c )
    {
    case 't':
      return '\t';
    case 'n':
      return '\n';
    case '\\':
      return '\\';
    default:
      return c;
    }
}



int replace( char keys[], char values[] ) {
  char c;
  while( (c = getchar()) != EOF ) {
    translate(c, keys, values);
  }
  return 0;
}

void translate( char c , char keys[], char values[]) {
  /* This function will seach for c in keys and 
     replace w/ coresponding pair in value */
  int i;
  for( i=0; (keys[i] != '\0') && (c != keys[i]); i++)
    ;
  if( keys[i] == '\0' )		/* Char not found */
    putchar(c);
  else if( values[0] != '\0' )	/* Char found, translation */
    putchar(values[i]);
  /* else: char is found for deletion, do nothing */
  
}

/* TODO:
 *  * Handle escape chars
 *  * Deal with stuff
 */
int genHash( char *table, char *str1, char *str2 ) {
  /* This generates a 'hash' table / LUT for all chars
     such that all chars in st1 are replaced by chars in str2
     if str2 is longer excess chars are ignored*/
  printf("in genSTring:\n");


  int i;
  for(i=0 ; i <256; i++) {
    *(table + i) = (char) i;
    /* printf("%c ",i); */
  }

  i=0;
  for( ; *(str1) != '\0'; *(table + *str1++) = *str2++) {
    printf("%i ",i++);
  }

  
  for(i=32 ; i <126; i++) {
    //*(table + i) = (char) i;
    /* printf("%c ",i); */
  }
  
  return -1;
}



