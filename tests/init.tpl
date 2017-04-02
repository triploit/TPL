[use] out,A;
[use] in,A;
[use] os,A;

{init}
  lts   abc,"12s3";
  mov   abc,~sa;
  do    out,+ia;
  do    out,endline;
  end;

  mov   "1.$Eins\\n",~sa;
  mov   "2.$Zwei\\n",~sb;
  mov   "3.$Ende\\n",~sd;

  do    out,~sa;
  do    out,~sb;
  do    out,~sd;
  do    in,~sa;

  mov   "1",~sb;
  mov   "2",~sd;
  mov   "3",~se;

  eq    ~sa=~sb,m1;
  eq    ~sa=~sd,m2;
  eq    ~sa=~se,m3;

  end;

{m1}
  mov   "Aha!\\n",~sd;
  do    out,~sd;
  run   init;

{m2}
  mov   "Ok!?\\n",~sd;
  do    out,~sd;
  run   init;

{m3}
  mov   "Tschuess!\\n",~sd;
  do    out,~sd;
  end;
