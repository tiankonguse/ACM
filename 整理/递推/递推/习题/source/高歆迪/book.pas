var
  n,i:integer;
  f:array[1..20]of int64;
  ch:char;
begin
  assign(input,'book.in');
  reset(input);
  assign(output,'book.out');
  rewrite(output);
  readln(n);
  f[1]:=0;
  f[2]:=1;
  for i:=3 to n do f[i]:=(i-1)*(f[i-1]+f[i-2]);
  writeln(f[n]);
  close(input);
  close(output);
end.