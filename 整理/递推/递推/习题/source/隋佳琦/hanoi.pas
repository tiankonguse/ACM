var n,i:integer;
    f:array[1..30]of longint;
begin
  assign(input,'hanoi.in');
  reset(input);
  assign(output,'hanoi.out');
  rewrite(output);
  readln(n);
  f[1]:=1;
  for i:=2 to n do f[i]:=f[i-1]*2+1;
  writeln(f[n]);
  close(input);
  close(output);
end.
