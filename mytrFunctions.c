
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
    /* translate(c, keys, values); */
  }
  return 0;
}

void translate( char *table) {

  char c;
  while( (c = getchar()) != EOF ) {
    putchar( *(table + c) );
  }
  
}

/* TODO:
 *  * Handle escape chars
 *  * Deal with stuff
 */
void genHash( char *table, char *str1, char *str2 ) {
  /* This generates a 'hash' table / LUT for all chars
     such that all chars in st1 are replaced by chars in str2
     if str2 is longer excess chars are ignored, if str1 is
     longer the last char of str2 is repeated.
  */
  int i,j;

  printf("in genSTring:\n");

  /* Pre-Initialize LUT to correct valuse (0-255) */
  for(i=0 ; i <256; i++) {
    *(table + i) = (char) i;
  }

  /* Goes through str1 & str2 and replaces occurances of str 
     str1 in table with str2. ends when either pointer is null */
  /* for( ; *(str1) && *(str2); *(table + *str1++) = *str2++) ; */

  for(i=0, j=0; str1[i] && str2[j]; i++, j++) {
    *(table + str1[i]) = str2[j];
  }

  
  /* TODO Make Sure String2 length is > 1 */
  /* Check if str1 is longer, fill with the last char from str2 */
  /* for( ; *(str1) != '\0'; *(table + *str1++) = *(str2-1)) */
  /*   ; */
  for( ; str1[i]; i++) {

    *(table + str1[i]) = str2[j-1];
  }


}



