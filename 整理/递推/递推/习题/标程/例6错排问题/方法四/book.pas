var n,i,j,x:integer;
    ans:int64;
    g:array[0..20]of int64;
    c:array[0..20,0..20]of int64;
begin
  assign(input,'book.in');
  reset(input);
  assign(output,'book.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do c[i,0]:=1;
  c[1,1]:=1;
  for i:=2 to n do
    for j:=1 to i do c[i,j]:=c[i-1,j-1]+c[i-1,j];
  g[0]:=1;
  for i:=1 to n do g[i]:=g[i-1]*i;
  x:=-1;
  for i:=0 to n do begin
    x:=-x;
    ans:=ans+x*c[n,i]*g[n-i];
  end;
  writeln(ans);
  close(input);
  close(output);
end.
