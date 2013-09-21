program test;
var
  f:text;
  i,j:integer;

  begin
    assign(f,'game.out');
    reset(f);
    readln(f,i);
    close(f);
    assign(f,'game.std');
    reset(f);
    readln(f,j);
    close(f);
    if i<>j then writeln('WRONG') else writeln('OK');
  end.
