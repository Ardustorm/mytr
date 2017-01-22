
#include "mytr.h"

char unescape( char c ) {
  switch( c )
    {
    case 't':
      return '\t';
    case 'n':
      return '\n';
    default:
      return c;
    }
}

void delete(char *table,  char *str1 ) {
  char c;
  int i;
  printf("In delete\n");

 /* Pre-Initialize LUT to */
  for(i=0 ; i <256; *(table + i++) = 0)
    ;

  for(i=0; str1[i]; i++) {
    /* check if char should be deleted an update table */
    if ( (c= str1[i]) == '\\')
      c= unescape(str1[++i]);
    *(table + c) = 1;
  }

  /* Loop through input */
  while( (c = getchar()) != EOF ) {
    if( !( *(table + c)) )	/* Check it should print */
      putchar(c);
  }
}


  /* This generates a 'hash' table / LUT for all chars
     such that all chars in st1 are replaced by chars in str2
     if str2 is longer excess chars are ignored, if str1 is
     longer the last char of str2 is repeated.
     TODO:
     * Handle escape chars
     * Deal with stuff
  */
void genHash( char *table, char *str1, char *str2 ) {
  int i,j;
  char c1, c2;

  /* Pre-Initialize LUT to correct valuse (0-255) */
  for(i=0 ; i <256; i++)
    *(table + i) = (char) i;

  /* Goes through str1 & str2 and replaces occurances of str 
     str1 in table with str2. ends when either pointer is null */
  for(i=0, j=0; str1[i] && str2[j]; i++, j++) {

    /* Check for backslash and escapes */
    if ( (c1= str1[i]) == '\\')
      c1 = unescape(str1[++i]);
    
    if ( (c2= str2[j]) == '\\')
      c2 = unescape(str2[++j]);
    
    *(table + c1) = c2;
  }

  
  /* TODO Make Sure String2 length is > 1 */
  /* TODO deal with escaped last char */
  /* Check if str1 is longer, fill with the last char from str2 */
  for( ; str1[i]; i++) {
    if ( (c1= str1[i]) == '\\')
      c1 = unescape(str1[++i]);
  
    *(table + c1) = str2[j-1];
  }

}



/* Returns true if deletes, false for translate
   also checks num of args and exits */
int checkArgsDelete(int argc, char *argv[]) {

  
  /* This block makes sure # of args is correct */
  if(argc < 3) {
    //printf("mytr: missing operand\n");
    fprintf(stderr, "mytr: missing operand\n");
    exit(1);
  }
  if(argc > 3) {
    //printf("mytr: extra operand '%s'\n", argv[3]);
    fprintf(stderr,"mytr: extra operand '%s'\n", argv[3]);
    exit(1);
  }


  /* TODO: maybe check for incorrect flags */
  if( (argv[1][0] == '-') &&	/* check if 1st arg is '-d' */
      (argv[1][1] == 'd') &&
      (argv[1][2] == '\0')) {
    return 1;
  }
  else
    return 0;

}
