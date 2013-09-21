program factor;
 var
 i,j,k,l,m,n,p,q,e,f,sum,a,b,z,x,g,h:longint;
 procedure cu(n,k:longint);
  begin
  z:=1;x:=1;
   for i:=k downto k-n+1 do
    z:=z*i;
   for j:=1 to n do
    x:=x*j;
  l:=z div x;
  end;
 procedure aa(a,n:longint);
  begin
   q:=0;e:=a;g:=1;
   repeat
   g:=g*e;
   q:=q+1;
   until q=n;
  end;
 procedure bb(b,m:longint);
  begin
   p:=0;f:=b;h:=1;
   repeat
   h:=h*f;
   p:=p+1;
   until p=m;
  end;
 begin
 assign(input,'factor.in');reset(input);
 assign(output,'factor.out');rewrite(output);
 readln(a,b,k,n,m);
 cu(n,k);
 aa(a,n);
 bb(b,m);
 sum:=l*g*h;
 writeln(sum mod 10007);
 close(input);close(output);
 end.
