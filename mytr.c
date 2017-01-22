#include "mytr.h"


int main(int argc, char *argv[]) {
  char table[256];
  char c;

  if( checkArgsDelete(argc, argv) ) {
    delete(table, argv[2]);
    
  } else {
    /* TRANSLATE */
    genHash(table, argv[1], argv[2]);
    while( (c = getchar()) != EOF ) {
      putchar( *(table + c) );
    }
  }

  return 0;
}
  
