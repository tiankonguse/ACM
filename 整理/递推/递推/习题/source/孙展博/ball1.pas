const mo=10007;
var a,b,k,n,m:longint;
    f:array[0..1000,0..1000] of longint;
    a1,b1,i,j:longint;
begin
 assign(input,'ball1.in');reset(input);
 assign(output,'ball1.out');rewrite(output);
readln(n,m);
f[0,0]:=1;
for i:=1 to n do f[i,0]:=0;
for j:=1 to m do
for i:=0 to n do

 begin
 f[i,j]:=f[(i+n-1) mod n ,j-1]+f[(i+1) mod n,j-1];
 end;
writeln(f[0,m]);
 close(output);
end.
