var
n,i:longint;
f:array[0..1000] of longint;

begin
assign(input,'domino.in');
assign(output,'domino.out');
reset(input);rewrite(output);
readln(n);
f[1]:=1;f[2]:=2;
for i:=3 to n do f[i]:=f[n-1]+f[n-2];
writeln(f[n]);
close(output);
end.