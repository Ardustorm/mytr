
#include <stdio.h>
#include <stdlib.h>


int genString( char str1[], char str2[] );
int replace( char keys[], char values[] );
void translate( char c , char keys[], char values[]);


int main(int argc, char *argv[]) {

  /* This block makes sure # of args is correct */
  if(argc < 3) {
    printf("mytr: missing operand\n");
    exit(1);
  }
  if(argc > 3) {
    printf("mytr: extra operand '%s'\n", argv[3]);
    exit(1);
  }


  if( (argv[1][0] == '-') &&	/* check if 1st arg is '-d' */
      (argv[1][1] == 'd') &&
      (argv[1][2] == '\0')) {
    printf("wez goingz to delet\n");
    replace( argv[2], "\0");
    
  } else {
    printf("trans\n");
    replace( argv[1], argv[2]);
  }
  /* genString( argv[1], argv[2] ); */

  /* replace( argv[1], argv[2] ); */
  return 0;
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
int genString( char str1[], char str2[] ) {
  /* Will generate equal length strings,by extending str2,
     if str2 is longer excess chars are ignored*/
  printf("in replace:%c %s \t  %s\n",str1[1], str1,str2);


  char c1;
  char c2;
  int i;
  for(i=0 ; str1[i] != '\0'; i++) {
    c1 = str1[i];
    /* vvv   will change this to deal with cases */
    c2 = str2[i];
    
    printf( "%c:%c  ", c1, c2 );
  }
  printf("\n");
  return -1;
}
