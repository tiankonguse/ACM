program coin;
const max=100;
var
  n:integer;
  rest:integer;
  state:array[1..max] of integer;

procedure init;
begin
  assign(input,'coin.in');
  assign(output,'coin.out');
  reset(input);
  rewrite(output);
  readln(n);
end;

procedure out;
var i:integer;
begin
  for i:=1 to n do write(state[i]);
  writeln;
end;

procedure doit;
var i,j:integer;
begin
  writeln(n);
  fillchar(state,sizeof(state),0);
  rest:=0;
  for i:=1 to n do
    begin
      for j:=1 to n do state[j]:=1-state[j];
      j:=1;
      while state[j]<>1-rest do inc(j);
      state[j]:=rest;
      out;
      rest:=1-rest;
    end;
end;

begin
  init;
  doit;
  close(input);
  close(output);
end.
