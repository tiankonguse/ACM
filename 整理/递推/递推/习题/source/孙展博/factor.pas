const mo=10007;
var a,b,k,n,m:longint;
    f:array[0..1000,0..1000] of longint;
    a1,b1,i,j:longint;
begin
 assign(input,'factor.in');reset(input);
 assign(output,'factor.out');rewrite(output);
 readln(a,b,k,n,m);
 if k=0 then
  begin
  if n=0 then writeln(1) else writeln(0);
  halt;
  end;
 a1:= a mod mo;
 b1:= b mod mo;
 fillchar(f,sizeof(f),0);
 f[0,0]:=b1;
 f[0,1]:=a1;
 for i:=2 to k do
  f[0,i]:=f[0,i-1]*b1 mod mo;
 for i:=1 to k do
 for j:=1 to i do
  begin
  f[j,i]:=(a1*f[j-1,i-1]+b1*f[j,i-1]) mod mo;
  end;
 writeln(f[n,k]);
 close(output);
end.
