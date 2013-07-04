const mo=10007;
var a,b,k,n,m,i,j,a1,b1:longint;
    f:array[0..1000,0..1000]of longint;


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
    f[1,1]:=a1;
    f[0,1]:=b1;
    for j:=2 to k do begin
      f[0,j]:=f[0,j-1]*b1 mod mo;
      for i:=1 to j do 
        f[i,j]:=(f[i-1,j-1]*a1 mod mo+f[i,j-1]*b1 mod mo)mod mo;
    end;
    writeln(f[n,k]);
  end;
  close(input);
  close(output);
end.
