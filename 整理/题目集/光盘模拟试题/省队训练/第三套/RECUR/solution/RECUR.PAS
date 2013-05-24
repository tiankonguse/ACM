program recur;
 {$N+}
 var
  kn,qn,f1,f0,a,b,q,k:extended;
  n,i:longint;
  f:array[0..20]of extended;
 function fang(x:extended;n:longint):extended;
  var
   t:extended;
   i:longint;
  begin
   t:=1;
   for i:=1 to n do
    t:=t*x;
   fang:=t;
  end;
 begin
  assign(input,'recur.in');
  assign(output,'recur.out');
  reset(input);rewrite(output);
  read(f0,f1,a,b,n);
  if n=1 then
   begin
    writeln(f1:0:0) ;
    close(output);halt;
   end else
  if n=0 then
   begin
    writeln(f0:0:0);
    close(output);halt;
   end ;
  q:=(a+sqrt(a*a+4*b))/2;
  k:=(-a+sqrt(a*a+4*b))/2;
  if n<1e6 then
   begin
    qn:=fang(q,n);
    kn:=fang(-k,n);
    writeln((qn*(f1+k*f0)-kn*(f1-q*f0))/(q+k):0:0);
   end else
  begin
   k:=-k;
   if abs(q-1)<1e-6 then qn:=1 else
   if abs(q+1)<1e-6 then begin if odd(n) then qn:=-1 else qn:=1; end else qn:=0;
   if abs(k-1)<1e-6 then kn:=1 else
   if abs(k+1)<1e-6 then begin if odd(n) then kn:=-1 else kn:=1; end else kn:=0;
   k:=-k;
   writeln((qn*(f1+k*f0)-kn*(f1-q*f0))/(q+k):0:0);
  end;
  close(output);
 end.