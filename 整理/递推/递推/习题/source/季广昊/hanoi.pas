program hanoi;
var f:array[1..50] of longint;
    i,j:longint;
begin
  assign(input,'hanoi.in');
  assign(output,'hanoi.out');
  reset(input);
  rewrite(output);
  readln(j);
  fillchar(f,sizeof(f),0);
  f[1]:=1;
  for i:=2 to j do
    f[i]:=2*f[i-1]+1;
  writeln(f[j]);
  close(output);
end.