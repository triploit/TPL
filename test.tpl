[use]out
[use]in;

do in,+id;

{main}
  do    out,endline;
  mov   IA:$,~sa;
  mov   IB:$,~sb;

  do    out,~sa;
  mov   +id,+ia;
  do    out,+ia;

  do    out,endline;
  do    out,~sb;
  add   1,+ib;
  do    out,+ib;

  do    out,endline;
  eq    +ib!+ia,nein;
  eq    +ib=+ia,ja;

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
