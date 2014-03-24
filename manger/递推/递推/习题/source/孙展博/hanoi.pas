const mo=10007;
var a,b,k,n,m:longint;
    f:array[0..1000] of longint;
    a1,b1,i,j:longint;
begin
 assign(input,'hanoi.in');reset(input);
 assign(output,'hanoi.out');rewrite(output);
readln(n);
f[1]:=1;
for i:=2 to n do
 begin
 f[i]:=2*f[i-1]+1;
 end;
writeln(f[n]);
 close(output);
end.
