var
n,m,i,j:integer;
f:array[0..30,0..30]of longint;
begin
  assign(input,'ball1.in');
  reset(input);
  assign(output,'ball1.out');
  rewrite(output);
  readln(n,m);
  f[0,0]:=1;
  for j:=1 to m do begin
    for i:=0 to n-1 do begin
      f[i,j]:=f[(i-1+n)mod n,j-1]+f[(i+1)mod n,j-1];
    end;
  end;
  writeln(f[0,m]);
  close(input);
  close(output);
end.
