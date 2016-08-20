#ifndef MOVE
#define MOVE

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "sys.c"
#include "valS.h"

void mov(string arg1, string arg2)
{
  bool t = System.findCell(arg2);

  if (!System.isInteger(arg1) && !t)
  {
    printf("[ ERR ] Der eingegebene String ist keine Zahl oder es konnte die angegebene Zelle nicht gefunden werden! (MOV)\n");
  }
  else
  {
    int val = stoi(arg1);
    System.mvIC(val, arg2);
  }
}

#endif
