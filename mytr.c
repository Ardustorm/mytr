
#include <stdio.h>


int replace( char str1[], char str2[] );

int main(int argc, char *argv[]) {

  /* This starts by assuming 2 groups */
  
  int i;
  for(i=1 ; i <argc; i++)
    if( argv[i][0] == '-')
      printf("arg: %s\n", argv[i]);
    else
      printf("%s\n", argv[i]);

  replace( argv[1], argv[2] );

  return 0;
}
  


int replace( char str1[], char str2[] ) {

  printf("in replace:%c %s \t  %s\n",str1[1], str1,str2);

  char c =str1[0];
  int i;
  for(i=0 ; c != '\0'; i++) {
    c = str1[i];
    printf( "pair: %c:%c  ", str1[i], str2[i] );
  }
}
