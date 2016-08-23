#ifndef USEE
#define USEE

#include <iostream>
#include "sys.c"
using namespace std;

void use(string arg1, string arg2)
{
  if (arg1 == "out" || arg2 == "out")
  {
    out = true;
    //printf("[ SYS ] OUT wurde eingebungden!\n");
  }
  else if (arg1 == "in" || arg2 == "in")
  {
    in = true;
    //printf("[ SYS ] IN wurde eingebungden!\n");
  }
  else if (arg1 == "file" || arg2 == "file")
  {
    filef = true;
    //printf("[ SYS ] IN wurde eingebungden!\n");
  }
  else if (arg1 == "math" || arg2 == "math")
  {
    math = true;
    //printf("[ SYS ] IN wurde eingebungden!\n");
  }
  else if (arg1 == "os" || arg2 == "os")
  {
    osf = true;
    //printf("[ SYS ] IN wurde eingebungden!\n");
  }
  else if (arg1 == "time" || arg2 == "time")
  {
    timef = true;
    //printf("[ SYS ] IN wurde eingebungden!\n");
  }
  else
  {
    printf("[ USE ] Konnte \"%s\" oder \"%s\" nicht einbinden!\n", arg1.c_str(), arg2.c_str());
  }
}

#endif
