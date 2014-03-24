program ball1;
var f:array[0..50,0..50] of longint;
    i,j,k,m,n:longint;
begin
  assign(input,'ball1.in');
  assign(output,'ball1.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  for j:=1 to m do
    for i:=0 to n do
      f[i,j]:=f[(i-1+n) mod n,j-1]+f[(i+1) mod n,j-1];
  writeln(f[0,m]);
  close(output);
end.