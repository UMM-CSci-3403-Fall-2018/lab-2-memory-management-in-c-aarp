#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;

  //I don't trust this size = 100. Where does it come from? Feels very magic-numbery to me.
  size = 100;
  line = (char*) malloc (size + 1);

  /*Passing in the result of disemvowel directly into a printf caused lost memory
  in an impossible to free-way.
  The "gotcha" one needed to spot was storing disemvowel(line) in a temp-variable.

  Notice that freeing line was also neccesary.
  */
  while (getline(&line, &size, stdin) > 0) {
    char *result;
    result = disemvowel(line);
    printf("%s\n", result);
    if(line){
      free(line);
    }
    if(result){
      free(result);
    }
  }
}
