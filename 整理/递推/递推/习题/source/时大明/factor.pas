var a,b,n,m,k,i,j:longint; f:array[0..200,0..200]of longint;
begin
  readln(a,b,k,n,m);
  a:=a mod 10007;
  b:=b mod 10007;
  f[1,1]:=a;
  f[0,1]:=b;


   for j:=1 to k do
     for i:=1 to n  do
       begin
        f[0,j]:=f[0,j-1]*a;
   f[i,j]:=f[i-1,j-1]*a mod 10007+f[i,j-1]*b mod 10007;
   writeln(f[n,k]);
   readln;



end.