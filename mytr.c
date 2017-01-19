#include "mytr.h"


int main(int argc, char *argv[]) {

  char stuff[256];
  
  genHash(stuff, "abcdefghij", "1234567890");
  printf("String:%c\n",stuff[106]);

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
    /* DELETION */
    replace( argv[2], "\0");
    
  } else {
    /* TRANSLATION */
    printf("trans\n");
    replace( argv[1], argv[2]);
  }

  return 0;
}
  
