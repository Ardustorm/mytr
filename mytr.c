
#include <stdio.h>


int genString( char str1[], char str2[] );
int replace( char keys[], char values[] );
char translate( char c , char keys[], char values[]);


int main(int argc, char *argv[]) {

  /* This starts by assuming 2 groups */
  
  int i;
  for(i=1 ; i <argc; i++)
    if( argv[i][0] == '-')
      printf("arg: %s\n", argv[i]);
    else
      printf("%s\n", argv[i]);

  genString( argv[1], argv[2] );

  replace( argv[1], argv[2] );
  return 0;
}
  

int replace( char keys[], char values[] ) {
  if(values[0] == '\0') {
    /* deal with deletion */
  }
  else {
    char c;
    while( (c = getchar()) != EOF ) {
      
      putchar(translate(c, keys, values));
    }
  }
  return 0;
}

char translate( char c , char keys[], char values[]) {

  int i;
  for( i=0; (keys[i] != '\0') && (c != keys[i]); i++)
    ;
  if( keys[i] == '\0' )
    return c;
  else
    return values[i];

}

int genString( char str1[], char str2[] ) {

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
}
