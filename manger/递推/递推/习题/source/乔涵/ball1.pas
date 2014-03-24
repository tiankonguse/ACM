var
j,n,i,m:longint;
f:array[0..30,0..30] of longint;

begin
assign(input,'ball1.in');
assign(output,'ball1.out');
reset(input);rewrite(output);
readln(n,m);
for i:=1 to 30 do f[i,0]:=0; f[0,0]:=1;

for j:=1 to m do
 for i:=0 to n-1 do
  f[i,j]:=f[(i+n+1) mod n,j-1]+f[(i+n-1) mod n,j-1];


writeln(f[0,m]);

close(output);


end.
