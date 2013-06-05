var
 a,b:int64;
 k,n,m,i,j,a1,b1,mo,ans:integer;

function c(x,y:integer):int64;
begin
 c:=1;
 for i:=x downto x-y+1 do c:=c*i;
 for i:=2 to y do c:=c div i;
end;

begin
 assign(input,'factor.in');
 reset(input);
 assign(output,'factor.out');
 rewrite(output);
 readln(a,b,k,n,m);
 mo:=10007;
 a1:=a mod mo;
 b1:=b mod mo;
 ans:=1;
 for i:=1 to n do ans:=(ans*a1) mod mo;
 for i:=1 to m do ans:=(ans*b1) mod mo;
 if n<m then
   ans:=(ans*c(k,n)) mod mo
  else
   ans:=(ans*c(k,m)) mod mo;
 writeln(ans);
 close(input);
 close(output);
end.
