const mo=10007;
var a,b,k,n,m:longint;
    f:array[0..1000] of int64;
    a1,b1,i,j:longint;
begin
 assign(input,'domino.in');reset(input);
 assign(output,'domino.out');rewrite(output);
readln(n);
f[1]:=1;
f[0]:=1;
for i:=2 to n do
 begin
 f[i]:=f[i-1]+f[i-2];
 end;
writeln(f[n]);
 close(output);
end.
