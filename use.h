#ifndef USEE
#define USEE

#include <iostream>
#include "sys.c"
using namespace std;

void use(string arg1, string arg2)
{
  if (arg2 == "use" || arg2.at(0) == '{')
  {
    arg2 = "NOTHING";
    //System.var.i = System.var.i - 1;
  }

  if (arg2 == "A")
  {

  }
  else
  {
    printf("[ SYS ] Warum steht da als Argument 2 von Input kein \"A\"?!");
  }

  // printf("Argument: ARG1: %s ARG2: %s\n", arg1.c_str(), arg2.c_str());

  if (arg1 == "out" || arg2 == "out")
  {
    out = true;
    //printf("[ SYS ] OUT wurde eingebunden!\n");
  }
  else if (arg1 == "in" || arg2 == "in")
  {
    in = true;
    //printf("[ SYS ] IN wurde eingebunden!\n");
  }
  else if (arg1 == "file" || arg2 == "file")
  {
    filef = true;
    //printf("[ SYS ] FILE wurde eingebunden!\n");
  }
  else if (arg1 == "math" || arg2 == "math")
  {
    math = true;
    //printf("[ SYS ] MATH wurde eingebunden!\n");
  }
  else if (arg1 == "os" || arg2 == "os")
  {
    osf = true;
    //printf("[ SYS ] OS wurde eingebunden!\n");
  }
  else if (arg1 == "time" || arg2 == "time")
  {
    timef = true;
    //printf("[ SYS ] TIME wurde eingebunden!\n");
  }
  else
  {
    printf("[ USE ] Konnte \"%s\" oder \"%s\" nicht einbinden!\n", arg1.c_str(), arg2.c_str());
  }
}

#endif
