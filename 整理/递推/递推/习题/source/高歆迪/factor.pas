const mo=10007;
var
f:array[0..1000,0..1000]of longint;
a,b,k,n,m,a1,b1,i,j:longint;
ans:longint;
begin
assign(input,'factor.in');
reset(input);
assign(output,'factor.out');
rewrite(output);
ans:=1;
readln(a,b,k,n,m);
a1:=a mod mo;
b1:=b mod mo;
fillchar(f,sizeof(f),0);
f[0,0]:=1;
f[1,0]:=1;
f[1,1]:=1;
for i:=1 to 1000 do begin
 f[i,0]:=1;
 for j:=1 to 1000 do
  f[i,j]:=(f[i-1,j-1] mod mo+f[i-1,j]mod mo)mod mo;
end;
for i:=1 to n do
 ans:=ans*a1 mod mo;
for j:=1 to m do
 ans:=ans*b1 mod mo;
ans:=ans*f[k,n] mod mo;
writeln(ans);
close(input);
close(output);
end.
