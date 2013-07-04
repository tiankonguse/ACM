var
f:array[1..10000]of longint;
i,j,k,l,n:longint;
begin
  assign(input,'hanoi.in');
  assign(output,'hanoi.out');
  reset(input);
  rewrite(output);
readln(n) ;
f[1]:=1;
for i:=2  to n do
f[i]:=2*f[i-1]+1;
writeln(f[n]);
close(input);
close(output);
end.
