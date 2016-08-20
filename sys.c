#include <iostream>
#include <vector>
using namespace std;

#ifndef SYS_C
#define SYS_C
#include "valS.h"
#include "parser.c"

void eprint(string err)
{
  cout << "[ ERR ] " << err << endl;
}

void sprint(string sysmsg)
{
  cout << "[ SYS ] " << sysmsg << endl;
}

class System
{
public:

  inline bool isInteger(const std::string & s)
  {
     if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

     char * p;
     strtol(s.c_str(), &p, 10);

     return (*p == 0);
  }
  
  struct var
  {
      int i = 0;
  } var;

  bool findCell(string s)
  {
    for (int z = 0; z < 10; z++)
    {
      if (z < 8)
      {
        if (s == cells[z])
          return true;
      }
    }
    return false;
  }

  int mvIC(int v, string s)
  {
    if (s == iai)
      ia = v;
    else if (s == ibi)
      ib = v;
    else if (s == idi)
      id = v;
    else if (s == iei)
      ie = v;
    else
      printf("[ ERR ] Dieser Error sollte niemals zusatende kommen! Bitte den Entwickler kontaktieren!\n          Fehlercode: #999\n");
  }

  string ignoreSpace(vector<string> cmd, int i)
  {
      return cmd[i+1];
  }

  string getArgumentAI(vector<string> cmds, int i)
  {
    for (int y = 0; y <= 2; y++)
    {
      i = i + 1;
      var.i += 1;
      for (int z = 0; z < 10; z++)
      {
        if (z < 8)
        {
          if (cmds[i] == cells[z])
            return cells[z];
          else
            return cmds[i];
        }
      }
    }
  }
} System;

#include "do.h"
#include "mov.h"
#include "del.h"
#include "use.h"
#include "end.h"
#include "out.h"

#endif
