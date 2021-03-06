#ifndef SYS_C
#define SYS_C

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool out;
bool in;
bool filef;
bool math;
bool osf;
bool timef;

bool strin;
int lasti;

class ival
{
private:
  int val;
  string name;
public:
  void setName(string nm)
  {
    name = nm;
  }
  void setValue(int v)
  {
    val = v;
  }

  string getName()
  {
    return name;
  }
  int getValue()
  {
    return val;
  }
};

class sval
{
private:
  string val;
  string name;
public:
  void setName(string nm)
  {
    name = nm;
  }
  void setValue(string v)
  {
    val = v;
  }

  string getName()
  {
    return name;
  }
  string getValue()
  {
    return val;
  }
};

vector<sval> dstr;
vector<ival> dint;

void setI(int i);
void gotof(string m);

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

std::vector<std::string> split(const std::string &text, char sep) {
  std::vector<std::string> tokens;
  std::size_t start = 0, end = 0;
  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

void rff(string arg1, string arg2);

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
      if (z < 9)
      {
        if (s == cells[z])
          return true;
      }
    }
    return false;
  }



  int getCellValueInt(string s)
  {
    for (int z = 0; z < 10; z++)
    {
      if (z < 8)
      {
        if (s == cells[z])
          if (s == iai)
            return ia;
          else if (s == ibi)
            return ib;
          else if (s == idi)
            return id;
          else if (s == iei)
            return ie;
      }
    }
  }

  string getCellValueStr(string s)
  {
    for (int z = 0; z < 10; z++)
    {
      if (z < 8)
      {
        if (s == cells[z])
          if (s == sai)
            return sa;
          else if (s == sbi)
            return sb;
          else if (s == sdi)
            return sd;
          else if (s == sei)
            return se;
      }
    }
  }

  int mvIC(int v, string s, string d = "")
  {
    if (s == iai)
      ia = v;
    else if (s == ibi)
      ib = v;
    else if (s == idi)
      id = v;
    else if (s == iei)
      ie = v;

    else if (s == sai)
      sa = d;
    else if (s == sbi)
      sb = d;
    else if (s == sdi)
      sd = d;
    else if (s == sei)
      se = d;

    else
      printf("[ ERR ] Dieser Error sollte niemals zusatende kommen! Bitte den Entwickler kontaktieren!\n[ ^ ERR ^ ]Fehlercode: #999\n");
  }

  int rmIC(int v, string s, string d = "")
  {
    if (s == iai)
      ia = ia - v;
    else if (s == ibi)
      ib = ib - v;
    else if (s == idi)
      id = id - v;
    else if (s == iei)
      ie = ie - v;

    else if (s == sai)
      replace(sa, d, "");
    else if (s == sbi)
      replace(sb, d, "");
    else if (s == sdi)
      replace(sd, d, "");
    else if (s == sei)
      replace(se, d, "");

    else
      printf("[ ERR ] Dieser Error sollte niemals zusatende kommen! Bitte den Entwickler kontaktieren!\n[ ^ ERR ^ ]Fehlercode: #999\n");
  }

  int divIC(int v, string s, string d = "")
  {

    if (s == iai)
    {
      if (v < ia)
        ia = ia / v;
      else
        printf("[ ERR ] Beim dividieren wird nicht in den Kommabereich gerechnet, desswegen\n        darf die zweite Zahl nicht größer sein als die erste!\n");
    }
    else if (s == ibi)
    {
      if (v < ib)
        ib = ib / v;
      else
        printf("[ ERR ] Beim dividieren wird nicht in den Kommabereich gerechnet, desswegen\n        darf die zweite Zahl nicht größer sein als die erste!\n");
    }
    else if (s == idi)
    {
      if (v < id)
        id = id / v;
      else
        printf("[ ERR ] Beim dividieren wird nicht in den Kommabereich gerechnet, desswegen\n        darf die zweite Zahl nicht größer sein als die erste!\n");
    }
    else if (s == iei)
    {
      if (v < ie)
        ie = ie / v;
      else
        printf("[ ERR ] Beim dividieren wird nicht in den Kommabereich gerechnet, desswegen\n        darf die zweite Zahl nicht größer sein als die erste!\n");
    }
    else if (s == sai)
    {
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (DIV)");
    }
    else if (s == sbi)
    {
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (DIV)");
    }
    else if (s == sdi)
    {
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (DIV)");
    }
    else if (s == sei)
    {
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (DIV)");
    }
    else
    {
      printf("[ ERR ] Dieser Error sollte niemals zusatende kommen! Bitte den Entwickler kontaktieren!\n[ ^ ERR ^ ]Fehlercode: #999\n");
    }
  }

  int mulIC(int v, string s, string d = "")
  {
    if (s == iai)
      ia = ia * v;
    else if (s == ibi)
      ib = ib * v;
    else if (s == idi)
      id = id * v;
    else if (s == iei)
      ie = ie * v;

    else if (s == sai)
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (MUL)");
    else if (s == sbi)
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (MUL)");
    else if (s == sdi)
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (MUL)");
    else if (s == sei)
      printf("[ ERR ] Dies ist eine Rechenoperation, diese ist nicht für Strings gedacht. (MUL)");

    else
      printf("[ ERR ] Dieser Error sollte niemals zusatende kommen! Bitte den Entwickler kontaktieren!\n[ ^ ERR ^ ]Fehlercode: #999\n");
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

string getOsName()
{
    #ifdef _WIN32
    return "Windows32";
    #elif _WIN64
    return "Windows64";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "MacOSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}
} System;

void mov(string arg1, string arg2)
{
  //bool t = System.findCell(arg2);

  if (false)
  {
    printf("[ ERR ] Der eingegebene Wert konnte nicht verschoben werden! (MOV)\n");
  }
  else
  {
    if (arg2 == sai || arg2 == sbi || arg2 == sdi || arg2 == sei)
    {
        string val;
        char* path = getcwd(NULL, 0);
        //printf("%s\n",path);

        if (arg1 == iai)
        {
          val = to_string(ia);
        }
        else if (arg1 == ibi)
        {
          val = to_string(ib);
        }
        else if (arg1 == idi)
        {
          val = to_string(id);
        }
        else if (arg1 == iei)
        {
          val = to_string(ie);
        }
        else if (arg1 == sai)
        {
          val = sa;
        }
        else if (arg1 == sbi)
        {
          val = sb;
        }
        else if (arg1 == sdi)
        {
          val = sd;
        }
        else if (arg1 == sei)
        {
          val = se;
        }
        else if (arg1 == fos && osf == true)
        {
          val = System.getOsName();
        }
        else if (arg1 == "fd" && osf == true)
        {
          val = getcwd(NULL, 0);
        }
        else
        {
          for (int di = 0; di < dstr.size(); di++)
          {
            if (dstr[di].getName().compare(arg1))
            {
              val = dstr[di].getValue();
              return;
            }
          }

          for (int di = 0; di < dint.size(); di++)
          {
            if (dint[di].getName().compare(arg2))
            {
              val = to_string(dint[di].getValue());
              return;
            }
          }

          val = arg1;
        }

        for (int i = 0; i < val.length(); i++) { replace(val, "\\$", "\\\\\\\\\\");replace(val, "\\", "\\\\\\");replace(val, "$", " ");replace(val, "\"", "");replace(val, "\\\\\\", "\"");replace(val, "\\n", "\n"); replace(val, "\\\\\\\\\\", "$"); }
        System.mvIC(0, arg2, val);
        //printf("[ MOV ]:[ STR ] \"%d\" IN \"%s\"\n", val, arg2.c_str());
    }
    else
    {
      int val;

      if (arg1 == iai)
      {
        val = ia;
      }
      else if (arg1 == ibi)
      {
        val = ib;
      }
      else if (arg1 == idi)
      {
        val = id;
      }
      else if (arg1 == iei)
      {
        val = ie;
      }
      else if (arg1 == sai)
      {
        val = stoi(sa);
      }
      else if (arg1 == sbi)
      {
        val = stoi(sb);
      }
      else if (arg1 == sdi)
      {
        val = stoi(sd);
      }
      else if (arg1 == sei)
      {
        val = stoi(se);
      }
      else
      {
        for (int di = 0; di < dstr.size(); di++)
        {
          if (dstr[di].getName().compare(arg1))
          {
            val = stoi(dstr[di].getValue());
            return;
          }
        }

        for (int di = 0; di < dint.size(); di++)
        {
          if (dint[di].getName().compare(arg2))
          {
            val = dint[di].getValue();
            return;
          }
        }

        val = stoi(arg1);
      }
    }
  }
}

void addf(string arg1, string arg2)
{
  bool t = System.findCell(arg2);

  if (!System.isInteger(arg1) && !t)
  {
    printf("[ ERR ] Der eingegebene String %s ist keine Zahl oder es konnte die angegebene Zelle %s nicht gefunden werden! (ADD)\n", arg2.c_str(), arg1.c_str());
  }
  else
  {
    if (arg2 == sai || arg2 == sbi || arg2 == sdi || arg2 == sei)
    {
        string val;

        if (arg1 == iai)
          val = to_string(ia);
        else if (arg1 == ibi)
          val = to_string(ib);
        else if (arg1 == idi)
          val = to_string(id);
        else if (arg1 == iei)
          val = to_string(ie);

        else if (arg1 == sai)
          val = sa;
        else if (arg1 == sbi)
          val = sb;
        else if (arg1 == sdi)
          val = sd;
        else if (arg1 == sei)
          val = se;
        else
          val = arg1;

        for (int i = 0; i < val.length(); i++) { replace(val, "\\", "\\\\\\");replace(val, "$", " ");replace(val, "\"", "");replace(val, "\\\\\\", "\"");replace(val, "\\n", "\n"); }
        System.mvIC(0, arg2, val);
        //printf("\n[ ADD ]:[ STR ] \"%s\" TO \"%s\"\n", val.c_str(), arg2.c_str());
    }
    else
    {
        int val;

        if (arg1 == iai)
          val = ia;
        else if (arg1 == ibi)
          val = ib;
        else if (arg1 == idi)
          val = id;
        else if (arg1 == iei)
          val = ie;

        else if (arg1 == sai)
          val = stoi(sa);
        else if (arg1 == sbi)
          val = stoi(sb);
        else if (arg1 == sdi)
          val = stoi(sd);
        else if (arg1 == sei)
          val = stoi(se);
        else
          val = stoi(arg1);

        val = System.getCellValueInt(arg2)+val;
        //printf("[ ADD ]:[ INT ] V: %d\n", System.getCellValueInt(arg2));

        System.mvIC(val, arg2);
        //printf("\n[ ADD ]:[ INT ] \"%d\" TO \"%s\"\n", val, arg2.c_str());
    }
  }
}

void remf(string arg1, string arg2)
{
  bool t = System.findCell(arg2);

  if (!System.isInteger(arg1) && !t)
  {
    printf("[ ERR ] Der eingegebene String %s ist keine Zahl oder es konnte die angegebene Zelle %s nicht gefunden werden! (ADD)\n", arg2.c_str(), arg1.c_str());
  }
  else
  {
    if (arg2 == sai || arg2 == sbi || arg2 == sdi || arg2 == sei)
    {
        string val;

        if (arg1 == iai)
          val = to_string(ia);
        else if (arg1 == ibi)
          val = to_string(ib);
        else if (arg1 == idi)
          val = to_string(id);
        else if (arg1 == iei)
          val = to_string(ie);

        else if (arg1 == sai)
          val = sa;
        else if (arg1 == sbi)
          val = sb;
        else if (arg1 == sdi)
          val = sd;
        else if (arg1 == sei)
          val = se;
        else
          val = arg1;
        //printf("[ ADD ]:[ STR ] V: %s\n", System.getCellValueStr(arg2).c_str());

        for (int i = 0; i < val.length(); i++) { replace(val, "\\", "\\\\\\");replace(val, "$", " ");replace(val, "\"", "");replace(val, "\\\\\\", "\"");replace(val, "\\n", "\n"); }

        System.rmIC(0, arg2, val);
        //printf("\n[ ADD ]:[ STR ] \"%s\" TO \"%s\"\n", val.c_str(), arg2.c_str());
    }
    else
    {
        int val;

        if (arg1 == iai)
          val = ia;
        else if (arg1 == ibi)
          val = ib;
        else if (arg1 == idi)
          val = id;
        else if (arg1 == iei)
          val = ie;

        else if (arg1 == sai)
          val = stoi(sa);
        else if (arg1 == sbi)
          val = stoi(sb);
        else if (arg1 == sdi)
          val = stoi(sd);
        else if (arg1 == sei)
          val = stoi(se);
        else
          val = stoi(arg1);
        //printf("[ ADD ]:[ INT ] V: %d\n", System.getCellValueInt(arg2));

        System.rmIC(val, arg2);
        //printf("\n[ ADD ]:[ INT ] \"%d\" TO \"%s\"\n", val, arg2.c_str());
    }
  }
}

void mulf(string arg1, string arg2)
{
  bool t = System.findCell(arg2);

  if (!System.isInteger(arg1) && !t)
  {
    printf("[ ERR ] Der eingegebene String %s ist keine Zahl oder es konnte die angegebene Zelle %s nicht gefunden werden! (ADD)\n", arg2.c_str(), arg1.c_str());
  }
  else
  {
    if (arg2 == sai || arg2 == sbi || arg2 == sdi || arg2 == sei)
    {
        string val;

        if (arg1 == iai)
          val = to_string(ia);
        else if (arg1 == ibi)
          val = to_string(ib);
        else if (arg1 == idi)
          val = to_string(id);
        else if (arg1 == iei)
          val = to_string(ie);

        else if (arg1 == sai)
          val = sa;
        else if (arg1 == sbi)
          val = sb;
        else if (arg1 == sdi)
          val = sd;
        else if (arg1 == sei)
          val = se;
        else
          val = arg1;
        //printf("[ ADD ]:[ STR ] V: %s\n", System.getCellValueStr(arg2).c_str());

        for (int i = 0; i < val.length(); i++) { replace(val, "\\", "\\\\\\");replace(val, "$", " ");replace(val, "\"", "");replace(val, "\\\\\\", "\"");replace(val, "\\n", "\n"); }

        System.mulIC(0, arg2, val);
        //printf("\n[ ADD ]:[ STR ] \"%s\" TO \"%s\"\n", val.c_str(), arg2.c_str());
    }
    else
    {
        int val;

        if (arg1 == iai)
          val = ia;
        else if (arg1 == ibi)
          val = ib;
        else if (arg1 == idi)
          val = id;
        else if (arg1 == iei)
          val = ie;

        else if (arg1 == sai)
          val = stoi(sa);
        else if (arg1 == sbi)
          val = stoi(sb);
        else if (arg1 == sdi)
          val = stoi(sd);
        else if (arg1 == sei)
          val = stoi(se);
        else
          val = stoi(arg1);
        //printf("[ ADD ]:[ INT ] V: %d\n", System.getCellValueInt(arg2));

        System.mulIC(val, arg2);
        //printf("\n[ ADD ]:[ INT ] \"%d\" TO \"%s\"\n", val, arg2.c_str());
    }
  }
}

void divf(string arg1, string arg2)
{
  bool t = System.findCell(arg2);

  if (!System.isInteger(arg1) && !t)
  {
    printf("[ ERR ] Der eingegebene String %s ist keine Zahl oder es konnte die angegebene Zelle %s nicht gefunden werden! (ADD)\n", arg2.c_str(), arg1.c_str());
  }
  else
  {
    if (arg2 == sai || arg2 == sbi || arg2 == sdi || arg2 == sei)
    {
        string val;

        if (arg1 == iai)
          val = to_string(ia);
        else if (arg1 == ibi)
          val = to_string(ib);
        else if (arg1 == idi)
          val = to_string(id);
        else if (arg1 == iei)
          val = to_string(ie);

        else if (arg1 == sai)
          val = sa;
        else if (arg1 == sbi)
          val = sb;
        else if (arg1 == sdi)
          val = sd;
        else if (arg1 == sei)
          val = se;
        else
          val = arg1;
        //printf("[ DIV ]:[ STR ] V: %s\n", System.getCellValueStr(arg2).c_str());

        for (int i = 0; i < val.length(); i++) { replace(val, "\\", "\\\\\\");replace(val, "$", " ");replace(val, "\"", "");replace(val, "\\\\\\", "\"");replace(val, "\\n", "\n"); }

        System.divIC(0, arg2, val);
        //printf("\n[ DIV ]:[ STR ] \"%s\" TO \"%s\"\n", val.c_str(), arg2.c_str());
    }
    else
    {
        int val;

        if (arg1 == iai)
          val = ia;
        else if (arg1 == ibi)
          val = ib;
        else if (arg1 == idi)
          val = id;
        else if (arg1 == iei)
          val = ie;

        else if (arg1 == sai)
          val = stoi(sa);
        else if (arg1 == sbi)
          val = stoi(sb);
        else if (arg1 == sdi)
          val = stoi(sd);
        else if (arg1 == sei)
          val = stoi(se);
        else
          val = stoi(arg1);
        //printf("[ DIV ]:[ INT ] V: %d\n", System.getCellValueInt(arg2));

        System.divIC(val, arg2);
        //printf("\n[ DIV ]:[ INT ] \"%d\" TO \"%s\"\n", val, arg2.c_str());
    }
  }
}

void setI(int i)
{
  System.var.i = i;
}

void gotof(string m)
{
  //printf("[ SYS ] JMP TO {%s}! (EQ/GT)\n", m.c_str());
  vector<string> gtnv;
  gtnv = split(m, '*');

  for (int i = 0; i < gtv.size(); i++)
  {
    lasti = System.var.i;

    string marke = gtv[i].substr(0, gtnv[0].size());
    string num = gtv[i].substr(gtnv[0].size()+1, gtv[i].size());

    if (marke == gtnv[0])
    {
      //printf("[ ERR ] Marke erkannt %s (%s)! (EQ/GT)\n", gtnv[0].c_str(), num.c_str());
      setI(stoi(num));
      return;
    }
    else
    {
      //printf("[ SYS ] %s != %s\n", gtnv[0].c_str(), marke.c_str());
    }
  }
  printf("[ ERR ] Marke \"%s\" nicht gefunden! (GT)\n", gtnv[0].c_str());
}

void rtrnf(string arg1, string arg2)
{
  System.var.i = lasti;
}

void ltif(string arg1, string arg2)
{
  for (int i = 0; i < dint.size(); i++)
  {
    if (dint[i].getName().compare(arg1))
    {
      dint[i].setValue(stoi(arg2));
      return;
    }
  }

  ival d;
  d.setName(arg2);
  d.setValue(stoi(arg1));
  dint.push_back(d);
}

void ltsf(string arg1, string arg2)
{
  for (int i = 0; i < dstr.size(); i++)
  {
    if (dstr[i].getName().compare(arg1))
    {
      dstr[i].setValue(arg2);
      return;
    }
  }

  sval d;
  d.setName(arg2);
  d.setValue(arg1);
  dstr.push_back(d);
}

#endif
