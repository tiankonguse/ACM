program factor;
const mo=10007;
var i,j,k,m,n,a,b,a1,b1,c:longint;
    f:array[0..1000,1..1000] of longint;
begin
  assign(input,'factor.in');
  assign(output,'factor.out');
  reset(input);
  rewrite(output);
  readln(a,b,k,n,m);
  fillchar(f,sizeof(f),0);
  a1:=a mod mo;
  b1:=b mod mo;
  f[1,1]:=a1;
  f[0,1]:=b1;
  for j:=2 to k do
  begin
    f[0,j]:=(f[0,j-1]*a1) mod mo;
    for i:=1 to n do
    f[i,j]:=(f[i-1,j-1]*a1+f[i,j-1]*b1) mod mo;
  end;
  writeln(f[n,k]);
  close(output);
end.