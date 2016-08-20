#ifndef PARSER_C
#define PARSER_C

#include <stdio.h>
#include <stdlib.h>
#include "a1z26.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "sys.c"
#include "valS.h"

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

int execute(string code, vector<string> cmds);

int print(string c, string c1 = "", string c2 = "", string c3 = "", string c4 = "", string c5 = "")
{
  c = c+c1+c2+c3+c4+c5;
  cout << c << endl;
  return 0;
}

int valv[10] = {0,0,0,0,0,0,0,0,0,0};//
int valc = 0;

int blocki;
int loopi;

int parse_code(char code[])
{
  string c = "";
  int cmdc = 0;
  vector<string> cmds;

  for (int i = 0; code[i] != '\0'; i++)
  {
    toupper(code[i]);
    if (code[i] == ' ' || code[i] == ';' || code[i] == '\n' || code[i] == '\t' || code[i] == '@' || code[i] == ',' || code[i] == '[' || code[i] == ']')
    {
      c = "";
    }
    else
    {
      c+=code[i];
    }
  }

  c = "";

  for (int i = 0; code[i] != '\0'; i++)
  {
    toupper(code[i]);
    if (code[i] == ' ' || code[i] == '\t' || code[i] == ';' || code[i] == '\n' || code[i] == '@' || code[i] == ',')
    {
      if (code[i] == '@')
      {
        c+=code[i];
      }

      replace(c, "[", "");
      replace(c, "]", "");
      cmds.push_back(c);
      c = "";
    }
    else
    {
      c += code[i];
    }
  }
  execute(c, cmds);

  return 0;
}

int execute(string code, vector<string> cmds)
{
  for (System.var.i; System.var.i < cmds.size(); System.var.i++)
  {
    for (int z = 0; z < 10; z++)
    {
      if (z < 6 && cmds[System.var.i] == Kwords.kwords_str[z])
      {
        if ((System.var.i+2) < cmds.size())
        {

          string arg = System.getArgumentAI(cmds,System.var.i);
          string arg1 = System.getArgumentAI(cmds,System.var.i);

          //printf("[ System ]    ->    Arguments: %s, %s\n", arg.c_str(), arg1.c_str());
          Kwords.kwords_func[z](arg,arg1);
        }
        else
        {
          Kwords.kwords_func[z]("NOTHING","NOTHING");
        }
      }
    }


  }

  return 0;
}

#endif
