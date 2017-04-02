#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include <stdlib.h>
#include "parser.c"
#include "valS.h"

int main(int argc, char* argv[]) {

  if (argc < 2 || argc == 0)
  {
    printf("[ ERR ] Es wurde keine Datei angegeben!\nEnter drücken um fortzufahren... ");
    cin.get();
    return 0;
  }

  Kwords.initkwords();

  char c;
  FILE *datei;
  char code[999999];

  datei=fopen(argv[1], "r");
  afile = argv[1];
  mfile = argv[1];

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

#endif
