var 
  n,i,j:integer;
  f:array[0..30]of int64;
begin
  assign(input,'bracket.in');
  reset(input);
  assign(output,'bracket.out');
  rewrite(output);
  readln(n);
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  for i:=1 to n do begin
    for j:=1 to i do f[i]:=f[i]+f[j-1]*f[i-j];
  end;
  writeln(f[n]);
  close(input);
  close(output);
end.
