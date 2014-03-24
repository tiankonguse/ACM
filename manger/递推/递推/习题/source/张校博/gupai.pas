program gupai;
 var
  i,j,k,l,m,n:longint;
  f:array[1..100000]of longint;
  procedure gupai(i:longint);
  begin
  f[1]:=1;f[2]:=2;j:=2;f[i]:=0;
  repeat
  j:=j+1;
  f[j]:=f[j-1]+f[j-2];
  until j=i;
  end;
 begin
 assign(input,'domino.in');reset(input);
 assign(output,'domino.out');rewrite(output);
  readln(n);
  if n=1 then writeln(1) else begin if n=2 then writeln(2);end;
  if n>=3 then begin gupai(n);writeln(f[n]); end;
 close(input);close(output);
 end.
