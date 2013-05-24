program loan;
{$N+}
 var
  x,s,u:longint;
  at,a1,a2,au:extended;
 function mi(a:extended):extended;
  var
   i:longint;
   t:extended;
  begin
   t:=1;
   for i:=1 to u do
    t:=t*a;
   mi:=t;
  end;
 begin
  assign(input,'loan.in');
  assign(output,'loan.out');
  reset(input);rewrite(output);
  read(x,s,u);
  if x=s*u then begin writeln('0.0');close(output);halt;end;
  a1:=1;
  a2:=2;
  au:=mi(a2);
  while x*au-s*(1-au)/(1-a2)<0 do
   begin
    a2:=a2*2;
    au:=mi(a2);
   end;
  while abs(a1-a2)>1e-10 do
   begin
    at:=(a1+a2)/2 ;
    au:=mi(at);
    if x*au-s*(1-au)/(1-at) <0 then
     a1:=at
    else
     a2:=at;
   end;
  writeln((a1-1)*100:0:1);
  close(output);
 end.