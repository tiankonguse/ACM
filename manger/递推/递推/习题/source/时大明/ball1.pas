program ball;
var m,n,s,a,ans:longint;
function jiecheng(q:longint):longint;
  var t:longint;
  begin
   jiecheng:=1;
  for t:=1 to  q do
   jiecheng:=jiecheng*t;

  end;
begin
 assign(input,'ball1.in');
 assign(output,'ball1.out');
 reset(input);
 rewrite(output);
   readln(n,m); ans:=0;
   for a:=0 to m do
   if (a-m+a) mod n=0 then
   begin
     ans:=ans+jiecheng(m)div (jiecheng(m-a)*jiecheng(a));
   end;
   writeln(ans);
   readln;
   close(output);
    end.
