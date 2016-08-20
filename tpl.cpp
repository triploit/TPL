#include <stdio.h>
#include <stdlib.h>
#include "parser.c"
#include "valS.h"

int main(int argc, char* argv[]) {

  Kwords.initkwords();

  char c;
  FILE *datei;
  char code[3000000];

  datei=fopen(argv[1], "r");
  if(datei != NULL)
  {
    for (int i = 0; (c=fgetc(datei)) != EOF; i++)
    {
      code[i] = c;
    }

    parse_code(code);
  }
  else
  {
    printf("Konnte Datei \"%s\" nicht finden bzw. öffnen!\n", argv[1]);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
