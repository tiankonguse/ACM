var n,i:integer;
    f:array[1..50]of int64;
begin
  assign(input,'domino.in');
  reset(input);
  assign(output,'domino.out');
  rewrite(output);
  readln(n);
  f[1]:=1;
  f[2]:=2;
  for i:=3 to n do f[i]:=f[i-1]+f[i-2];
  writeln(f[n]);
  close(input);
  close(output);
end.
