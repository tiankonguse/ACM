const mo=10007;
var a,b,k,n,m,i,j,a1,b1:longint;
    f:array[0..1000,0..1000]of longint;

function dg(i,j:integer):longint;
  begin
    if f[i,j]<>-1 then exit(f[i,j]);
    if j=1 then begin
       if i=0 then f[i,j]:=b1
       else if i=1 then f[i,j]:=a1
       else f[i,j]:=0;
    end else begin
       if i=0 then f[i,j]:=dg(i,j-1)*b1 mod mo
       else  f[i,j]:=(dg(i-1,j-1)*a1+dg(i,j-1)*b1)mod mo;
    end;
    exit(f[i,j]);
  end;

begin
  assign(input,'factor.in');
  reset(input);
  assign(output,'factor.out');
  rewrite(output);
  readln(a,b,k,n,m);
  if k=0 then begin
     if n=0 then writeln(1) else writeln(0);
  end else begin
    a1:=a mod mo;
    b1:=b mod mo;
    fillchar(f,sizeof(f),255);
    writeln(dg(n,k));
  end;
  close(input);
  close(output);
end.
