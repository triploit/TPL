[use] out,A;
[use] in,A;
[use] os,A;

{init}
  mov   9,+ie;
  mov   "Gib$eine$Zahl$ein$(9):$",~sa;

  do    out,~sa;
  do    in,+id;

  eq    +id<+ie,main;
  eq    +id=+ie,exit;
  eq    +id>+ie,exit;

  mov   "Kein$IF$hat$gestimmt!",~sa
  do    out,~sa
  do    out,endline

  end;

{main}
  do    out,endline;
  mov   "IA:$",~sa;
  mov   "IB:$",~sb;

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
  eq    +ib<+ia,errexit;
  eq    +ib>+ia,errexit;

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

{exit}

  mov   "Eingabe$zu$groß!",~sa;
  do    out,~sa;
  do    out,endline;
  end;

{errexit}

  mov   "Es ist ein unöglicher Error aufgetreten, das Programm muss abgebrochen werden!",~sa;
  do    out,~sa
  do    out,endline;
  end;
