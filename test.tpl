[use]out;
[use]in;

{main}
  do out,endline;
  mov IA:$,~sa;
  mov IB:$,~sb

  do out,~sa;
  mov 0,+ia;
  do out,+ia;
  mov 9,+ib;

  do out,endline;
  do out,~sb;
  rem 1,+ib;
  do out,+ib;

  do out,endl;
  eq +ia!+ib,main;

  do out,endline;
  end
