[use]out;
[use]in;
[use]file;

{main}
  do out,endline;
  mov HALLO$WELT!,~sa;
  do out,~sa;
  do out,endline;
  end

  Versuchen hinzuzufügen:

     [use]math;
     pl +ia-+ib,+id      => Ergebnis von ia und ib wurd in id gespeichert (Plus)
     min +ia-+ib,+id     => Ergebnis von ia und ib wurd in id gespeichert (Minus)
     ml +ia-+ib,+id      => Ergebnis von ia und ib wurd in id gespeichert (Mal)
     gtl +ia-+ib,+id     => Ergebnis von ia und ib wurd in id gespeichert (Geteielt)
