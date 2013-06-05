const mo=10007;
var a,b,k,n,m,r:longint;
    f:array[0..1000,0..1000] of longint;
    a1,b1,i,j:longint;
begin
 assign(input,'ball2.in');reset(input);
 assign(output,'ball2.out');rewrite(output);
readln(n,r);
fillchar(f,sizeof(f),0);
f[0,0]:=1;
f[1,1]:=1;

for i:=0 to n do f[i,1]:=1 ;


for j:=1 to r do
for i:=j to n do                 {}{}{}{}{}{}{}

 begin
 if i=j then f[i,j]:=1 else
 f[i,j]:=f[i-1,j]*j+f[i-1,j-1];
 end;
writeln(f[n,r]); close(output);  {}
end.
