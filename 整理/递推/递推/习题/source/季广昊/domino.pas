program domino;
var f:array[1..100] of int64;
    k,j:longint;
begin
  assign(input,'domino.in');
  assign(output,'domino.out');
  reset(input);
  rewrite(output);
  readln(k);
  fillchar(f,sizeof(f),0);
  f[1]:=1;
  f[2]:=2;
  case k of
  1:writeln(1);
  2:writeln(2);
  else begin
  for j:=3 to k do
    f[j]:=f[j-1]+f[j-2];
    writeln(f[k],' ');
  end;
  end;
  close(output);
end.