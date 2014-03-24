var n,m,i,j,k,x:integer;
    f,s:array[0..201,0..201,0..201]of int64;
begin
  assign(input,'divide3.in');
  reset(input);
  assign(output,'divide3.out');
  rewrite(output);
  readln(n,m);
  for k:=n downto 1 do
    for i:=k to n do begin
      f[i,1,k]:=1;
      s[i,1,k]:=s[i-1,1,k+1]+1;
    end;
  for j:=2 to m do begin
    for k:=n div j downto 1 do begin
      for i:=j*k to n do begin
        f[i,j,k]:=s[i-k,j-1,k]-s[i-i div j-1,j-1,i div j+1];
        s[i,j,k]:=s[i-1,j,k+1]+f[i,j,k];
      end;
    end;
  end;
  writeln(f[n,m,1]);
  close(input);
  close(output);
end.
