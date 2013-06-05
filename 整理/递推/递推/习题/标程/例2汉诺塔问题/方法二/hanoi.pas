var n:longint;
begin
  assign(input,'hanoi.in');
  reset(input);
  assign(output,'hanoi.out');
  rewrite(output);
  readln(n);
  writeln(1 shl n-1);
  close(input);
  close(output);
end.
