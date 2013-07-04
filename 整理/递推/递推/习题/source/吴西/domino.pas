var
f:array[1..100000] of longint;
i,j,n:longint;
begin
assign(input,'domino.in');
assign(output,'domino.out') ;
reset(input);
rewrite(output);
readln(n);
f[1]:=1;
f[2]:=1;
for i:=3 to n do
  f[i]:=f[i-1]+f[i-2];
  writeln(f[n]);
  close(output);
  end.
