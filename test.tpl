[use]out;
[use]in;

{main}
  do    out,endline;
  mov   IA:$,~sa;
  mov   IB:$,~sb;

  do    out,~sa;
  mov   4,+ia;
  do    out,+ia;

  do    out,endline;
  do    out,~sb;
  add   1,+ib;
  do    out,+ib;

  do    out,endline;
  eq    +ib!+ia,nein;
  eq    +ib=+ia,ja;
  end;

{nein}
  mov   "IB$ist$nicht$so$groß$wie$IA!",~sd;
  do    out,~sd;
  do    out,endline;
  run   main;

{ja}
  mov   "IB$ist$so$groß$wie$IA!",~sd;
  do    out,~sd;
  do    out,endline;
  end;
