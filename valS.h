#ifndef VAL_H
#define VAL_H

#include <iostream>
#include <string>
#include <vector>
#include "parser.c"
#include "sys.c"

#ifndef INC_D
#define INC_D
#include "do.h"
#include "mov.h"
#include "del.h"
#include "use.h"
#include "end.h"
#include "out.h"
#endif

using namespace std;

string sa;
string sb;
string sd;
string se;

int ia;
int ib;
int id;
int ie;

#define iai "+ia"
#define ibi "+ib"
#define idi "+id"
#define iei "+ie"


string cells[10] =
{
  "~sa",
  "~sb",
  "~sd",
  "~se",

  "+ia",
  "+ib",
  "+id",
  "+ie"
};

int noti(string arg1, string arg2)
{
  printf("Diese Nachricht wurd nur ausgegeben wenn ein Keyword noch nicht eingebunden wurde.\n");
}

class Kwords
{
public:
  vector<string> kwords_str;

  void initkwords()
  {
    kwords_str.push_back("mov");
    kwords_str.push_back("use");
    kwords_str.push_back("do");
    kwords_str.push_back("del");
    kwords_str.push_back("out");
    kwords_str.push_back("end");
  }

  void (*kwords_func[6])(string arg1, string arg2) =
  {
    &mov,
    &use,
    &dof,
    &del,
    &out,
    &quit
  };

} Kwords;

#endif
