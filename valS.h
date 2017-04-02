#ifndef VAL_H
#define VAL_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
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
#include "add.h"

void eqf(string arg1, string arg2);
void inf(string arg1, string arg2);
void remf(string arg1, string arg2);
void addf(string arg1, string arg2);
void mulf(string arg1, string arg2);
void divf(string arg1, string arg2);
void rtrnf(string arg1, string arg2);
void ltf(string arg1, string arg2);

void rff(string arg1, string arg2);
void ltif(string arg1, string arg2);
void ltsf(string arg1, string arg2);

#include "a1z26.h"
vector<string> gtv;
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

#define sai "~sa"
#define sbi "~sb"
#define sdi "~sd"
#define sei "~se"

#define fos "fos"


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
    kwords_str.push_back("add");
    kwords_str.push_back("do");
    kwords_str.push_back("dd");
    kwords_str.push_back("end");
    kwords_str.push_back("eq");
    kwords_str.push_back("rem");
    kwords_str.push_back("run");
    kwords_str.push_back("mul");
    kwords_str.push_back("div");
    kwords_str.push_back("rf");
    kwords_str.push_back("lts");
    kwords_str.push_back("lti");
    //kwords_str.push_back("ml");
    //kwords_str.push_back("gtl");
  }

  void (*kwords_func[15])(string arg1, string arg2) =
  {
    &mov,
    &use,
    &addf,
    &dof,
    &del,
    &quit,
    &eqf,
    &remf,
    &gotof,
    &mulf,
    &divf,
    &rff,
    &ltsf,
    &ltif
    //&pl,
    //&min,
    //&ml,
    //&gtl
  };

} Kwords;

void dof(string arg1, string arg2)
{

  if (arg1 == "out" && out)
  {
    outf(arg1, arg2);
  }
  else if (arg1 == "in" && in)
  {
    inf(arg1, arg2);
  }
  else if (arg1 == "wt" && osf)
  {
    int wait = stoi(arg2);
    sleep(wait);
  }
  else if (arg1 == "rf" && osf)
  {
    string name;

      if (arg2 == "~sa")
        name = sa;
      else if (arg2 == "~sb")
        name = sb;
      else if (arg2 == "~sd")
        name = sd;
      else if (arg2 == "~se")
        name = se;
      else
        name = arg2;

    string file = name;
    rff(file, "");
  }
  else if (arg1 == "cd" && osf)
  {
    string name;

      if (arg2 == "~sa")
        name = sa;
      else if (arg2 == "~sb")
        name = sb;
      else if (arg2 == "~sd")
        name = sd;
      else if (arg2 == "~se")
        name = se;
      else
        name = arg2;
    chdir(name.c_str());
  }
  else if (arg1 == "df" && osf)
  {
    string name;

      if (arg2 == "~sa")
        name = sa;
      else if (arg2 == "~sb")
        name = sb;
      else if (arg2 == "~sd")
        name = sd;
      else if (arg2 == "~se")
        name = se;
      else
        name = arg2;

    remove(name.c_str());
  }
  else if (arg1 == "ld" && osf)
  {
    string name;

    if (arg2 == "~sa")
      name = sa;
    else if (arg2 == "~sb")
      name = sb;
    else if (arg2 == "~sd")
      name = sd;
    else if (arg2 == "~se")
      name = se;
    else
      name = arg2;

    rmdir(name.c_str());
  }
  else if (arg1 == "mf" && osf)
  {
    string name;

      if (arg2 == "~sa")
        name = sa;
      else if (arg2 == "~sb")
        name = sb;
      else if (arg2 == "~sd")
        name = sd;
      else if (arg2 == "~se")
        name = se;
      else
        name = arg2;
    fstream(name, ios::out);
  }
  else if (arg1 == "md" && osf)
  {
    string name;

      if (arg2 == "~sa")
        name = sa;
      else if (arg2 == "~sb")
        name = sb;
      else if (arg2 == "~sd")
        name = sd;
      else if (arg2 == "~se")
        name = se;
      else
        name = arg2;
    #ifdef _WIN32
    mkdir(name.c_str());
    #elif _WIN64
    mkdir(name.c_str());
    #elif __unix || __unix__
    mkdir(name.c_str(), 755);
    #elif __APPLE__ || __MACH__
    mkdir(name.c_str(), 755);
    #elif __linux__
    mkdir(name.c_str(), 755);
    #elif __FreeBSD__
    mkdir(name.c_str(), 755);
    #else
    mkdir(name.c_str(), 755);
    #endif
  }
  else if (arg1 == "etr" && in)
  {
    for (int i = stoi(arg2); i > 0; i--)
      cin.get();
  }
  else if (arg1 == "cls" && out)
  {
    for (int i = stoi(arg2); i > 0; i--)
    {
      system("clear");
    }
  }
  else if (arg1 == "slp" && timef)
  {
    sleep(stoi(arg2));
  }
  else if (arg1 == "rnd")
  {
    int num;
    srand (time(NULL));
    num = rand();

    if (arg2 == iai)
      ia = num;
    else if (arg2 == ibi)
      ib = num;
    else if (arg2 == idi)
      id = num;
    else if (arg2 == iei)
      ie = num;
    else
      cout << "[ ERR ] Zelle \"" << arg2 << "\" konte nicht gefunden oder besdhrieben werden! (RND)" << endl;
  }
  else
  {
    printf("[ ERR ] Konnte die Aufgabe \"%s\" nicht finden! (DO)\n", arg1.c_str());
  }
}

void outf(string arg1, string arg2)
{
  if (arg2 == "+ia")
    printf("%d",ia);
  else if (arg2 == "+ib")
    printf("%d",ib);
  else if (arg2 == "+id")
    printf("%d",id);
  else if (arg2 == "+ie")
    printf("%d",ie);

  else if (arg2 == "endline")
    printf("\n");

  else if (arg2 == "~sa")
    printf("%s", sa.c_str());
  else if (arg2 == "~sb")
    printf("%s", sb.c_str());
  else if (arg2 == "~sd")
    printf("%s", sd.c_str());
  else if (arg2 == "~se")
    printf("%s", se.c_str());

  else
    cout << "[ ERR ] Zelle \"" << arg2 << "\" konte nicht gefunden werden! (DO/OUT)" << endl;
}

void eqf(string arg1, string arg2)
{
  //printf("[ SYS ] EQ gefunden! %s %s\n", arg1.c_str(), arg2.c_str());
  int iar1 = 0;
  int iar2 = 0;

  bool notf = false;
  bool gr = false;
  bool kl = false;

  string sar1 = "0";
  string sar2 = "0";

  vector<string> sarg;

  if (arg1.find("=") != string::npos)
  {
    sarg = split(arg1, '=');
  }
  else if (arg1.find("!") != string::npos)
  {
    sarg = split(arg1, '!');
    notf = true;

    sar1 = "a";
    sar2 = "e";

    iar1 = 0;
    iar2 = 1;
  }
  else if (arg1.find("<") != string::npos)
  {
    sarg = split(arg1, '<');
    kl = true;

    sar1 = "a";
    sar2 = "ae";

    iar1 = 0;
    iar2 = 1;
  }
  else if (arg1.find(">") != string::npos)
  {
    sarg = split(arg1, '>');
    gr = true;

    sar1 = "ae";
    sar2 = "a";

    iar1 = 1;
    iar2 = 0;
  }
  else
  {
    printf("[ ERR ] Ungültiger Ausdruck in %s! (EQ) \n[ SYS ] Bekannte Ausdrücke: < > ! = (EQ)", arg1.c_str());
  }

  if (sarg[0] == iai)
    iar1 = ia;
  else if (sarg[0] == ibi)
    iar1 = ib;
  else if (sarg[0] == idi)
    iar1 = id;
  else if (sarg[0] == iei)
    iar1 = ie;

  else if (sarg[0] == sai)
    sar1 = sa;
  else if (sarg[0] == sbi)
    sar1 = sb;
  else if (sarg[0] == sdi)
    sar1 = sd;
  else if (sarg[0] == sei)
    sar1 = se;
  else
    cout << "[ ERR ] Zelle \"" << sarg[0] << "\" konte nicht gefunden werden! (EQ1)" << endl;

  if (sarg[1] == iai)
    iar2 = ia;
  else if (sarg[1] == ibi)
    iar2 = ib;
  else if (sarg[1] == idi)
    iar2 = id;
  else if (sarg[1] == iei)
    iar2 = ie;

  else if (sarg[1] == sai)
    sar2 = sa;
  else if (sarg[1] == sbi)
    sar2 = sb;
  else if (sarg[1] == sdi)
    sar2 = sd;
  else if (sarg[1] == sei)
    sar2 = se;
  else
    cout << "[ ERR ] Zelle \"" << sarg[1] << "\" konte nicht gefunden werden! (EQ2)" << endl;

  //cout << " SAR1: " << sar1 << endl << "- SAR2: " << sar2 << endl << "-- IAR1: " << iar1 << endl << "--> IAR2: " << iar2 << endl;

  if (notf)
  {
    if (sar1 != sar2 && iar1 != iar2)
    {
      gotof(arg2);
      //printf("[ SYS ] TRUE (EQ)\n");
    }
    else
    {
      //printf("[ SYS ] FALSE (EQ)\n");
    }
  }
  else if (gr)
  {
    if (sar1 > sar2 && iar1 > iar2)
    {
      //printf("[ SYS ] TRUE %d %d GRÖßER(EQ)\n", iar1, iar2);
      gotof(arg2);
    }
    else
    {
      //printf("[ SYS ] FALSE %d %d GRÖßER (EQ)\n", iar1, iar2);
    }
  }
  else if (kl)
  {
    if (sar1 < sar2 && iar1 < iar2)
    {
      gotof(arg2);
      //printf("[ SYS ] TRUE %d %d (EQ)\n", iar1, iar2);
    }
    else
    {
      //printf("[ SYS ] FALSE (EQ)\n");
    }
  }
  else
  {
    if (sar1 == sar2 && iar1 == iar2)
    {
      gotof(arg2);
      //printf("[ SYS ] TRUE (EQ)\n");
    }
    else
    {
      //printf("[ SYS ] FALSE (EQ)\n");
    }
  }

}

void inf(string arg1, string arg2)
{
  if (arg2 == iai)
    cin >> ia;
  else if (arg2 == ibi)
    cin >> ib;
  else if (arg2 == idi)
    cin >> id;
  else if (arg2 == iei)
    cin >> ie;
  else if (arg2 == sai)
    getline(cin, sa);
  else if (arg2 == sbi)
    getline(cin, sb);
  else if (arg2 == sdi)
    getline(cin, sd);
  else if (arg2 == sei)
    getline(cin, se);
  else
    cout << "[ ERR ] Zelle \"" << arg2 << "\" konte nicht gefunden werden! (DO/IN)" << endl;

  //cout << "IA " << ia << endl;
  //cout << "IB " << ib << endl;
  //cout << "ID " << id << endl;
  //cout << "IE " << ie << endl;

  //cout << "SA " << sa << endl;
  //cout << "SB " << sb << endl;
  //cout << "SD " << sd << endl;
  //cout << "SE " << se << endl;
}

void del(string arg1, string arg2)
{
  if (arg2 != "0")
  {
    cout << "[ ERR ] Als Argument 2 muss 0 stehen! (DD)\nProgramm abgebrochen." << endl;
    exit(1);
  }

  if (arg1 == iai)
    ia = 0;
  else if (arg1 == ibi)
    ib = 0;
  else if (arg1 == idi)
    id = 0;
  else if (arg1 == iei)
    ie = 0;

  else if (arg1 == sai)
    sa = "";
  else if (arg1 == sbi)
    sb = "";
  else if (arg1 == sdi)
    sd = "";
  else if (arg1 == sei)
    se = "";
  else
    cout << "[ ERR ] Zelle \"" << arg1 << "\" konte nicht gefunden werden! (DD)" << endl;
}

#endif
