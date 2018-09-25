
#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* string) {

  int i;
  int j = 0;
  int len = strlen(string);
  int count = 0;

  for(i = 0; i < len; ++i){
    if(!(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')){
      ++count;
    }
  }

  char* noVow;
  noVow = calloc(count + 1, sizeof(char));

  for(i = 0; i < len; ++i){
    if(!(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')){
      noVow[j] = string[i];
      ++j;
    }
   }

  return noVow;
}
