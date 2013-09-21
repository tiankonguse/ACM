var n,m,i,j,k,x:integer;
    f:array[0..50,0..50,0..51]of int64;
begin
  assign(input,'divide3.in');
  reset(input);
  assign(output,'divide3.out');
  rewrite(output);
  readln(n,m);
  for k:=1 to n do
    for i:=k to n do f[i,1,k]:=1;
  for j:=2 to m do begin
    for k:=n div j downto 1 do begin
      for i:=j*k to n do begin
        f[i,j,k]:=f[i,j,k+1]+f[i-k,j-1,k];
      end;
    end;
  end;
  writeln(f[n,m,1]);
  close(input);
  close(output);
end.