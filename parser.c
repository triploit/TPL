#ifndef PARSER_C
#define PARSER_C

#include <stdio.h>
#include <stdlib.h>
#include "a1z26.h"
#include <iostream>
#include <vector>
#include <string>
#include "sys.c"
#include "valS.h"
using namespace std;

string afile, mfile;

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
    if (code[i] == ' ' || code[i] == ']' || code[i] == '\t' || code[i] == ';' || code[i] == '\n' || code[i] == '@' || code[i] == ',' || code[i] == '\0' || code[i] == '\"')
    {
      if (strin)
      {
        c += code[i];
      }

      int a = i + 1;
      for (a; code[a] == ' ' || code[a] == '\t' || code[a] == ';' || code[a] == '\n' || code[a] == '@' || code[a] == ',' || code[a] == '\0' || code[a] == '\"'; a++)
      {
        if (strin)
        {
          c += code[i];
        }
        i++;
      }

      replace(c, "[", "");
      cmds.push_back(c);
      c = "";
    }
    else
    {
      if (code[i] == '\"' || code[i] == '"')
      {
        if (strin)
        {
          strin = false;
        }
        else
        {
          strin = true;
        }
      }
      c += code[i];
    }
  }
  execute(c, cmds);

  return 0;
}


#include <string.h>
#include <string>

int execute(string code, vector<string> cmds)
{
  string gk = "{";

  for (System.var.i; System.var.i < cmds.size(); System.var.i++)
  {
    if (cmds[System.var.i].substr(0, 1) == "{")
    {
      string s = cmds[System.var.i];
      char code[cmds[System.var.i].size()+1];
      strcpy(code, s.c_str());
      string str;

      for (int x = 1; code[x] != '}' && x < cmds.size(); x++)
      {
        str += code[x];
      }

      string marke = str+"*"+to_string(System.var.i);
      //printf("[ SYS ] Marke gefunden: %s\n", marke.c_str());
      gtv.push_back(marke);
    }
  }

  System.var.i = 0;

  for (System.var.i; System.var.i < cmds.size(); System.var.i++)
  {
      vector<string> noth;
      noth = split("  ", ' ');

      if (cmds[System.var.i] == " " || cmds[System.var.i] == noth[0] || cmds[System.var.i] == "" || cmds[System.var.i] == "\0" || cmds[System.var.i] == "\n")
      {
        //System.var.i++;
      }
      else if (cmds[System.var.i] == noth[0] || cmds[System.var.i] == noth[1] || cmds[System.var.i] == "\0")
      {
        printf("[ SYS ] NICHTS GELÖSCHT!\n");
      }
      else
      {
        for (int z = 0; z < 10; z++)
        {
          string command = cmds[System.var.i];
          if (z < Kwords.kwords_str.size() && cmds[System.var.i] == Kwords.kwords_str[z])
          {
            if ((System.var.i+2) < cmds.size())
            {

              string arg = System.getArgumentAI(cmds,System.var.i);
              string arg1 = "NOTH";

              if (cmds[System.var.i] != "use")
              {
                arg1 = System.getArgumentAI(cmds,System.var.i);
              }
              else
              {
                System.var.i = System.var.i + 1;
              }

              //printf("[ System ]    ->    Arguments: %s, %s\n", arg.c_str(), arg1.c_str());
              Kwords.kwords_func[z](arg,arg1);
            }
            else if (command == "use" || command == "run" || command == "dd")
            {
              string arg = System.getArgumentAI(cmds,System.var.i);
              Kwords.kwords_func[z](arg,"NOTHING");
              System.var.i;
            }
            else
            {
              Kwords.kwords_func[z]("NOTHING","NOTHING");
            }
          }
      }
  }


  }

  return 0;
}

void rff(string arg1, string arg2)
{
  char* argv[2];

  argv[0] = "";
  argv[1] = arg1.c_str();
  //printf("[ SYS ] Führe RF aus. %s\n", argv[1]);

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
    printf("[ SYS ] Konnte Datei \"%s\" nicht finden bzw. öffnen! (DO/RF)\n", argv[1]);
    return;
  }
  return;
}

#endif
