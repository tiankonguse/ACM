var n,i,j:integer;
    f:array[1..50]of int64;
begin
  assign(input,'domino.in');
  reset(input);
  assign(output,'domino.out');
  rewrite(output);
  readln(n);
  f[1]:=1;
  for i:=2 to n do begin
    if odd(i) then begin
       for j:=1 to i div 2 do f[i]:=f[i]+f[j*2];
       inc(f[i]);
    end else begin
       for j:=1 to i div 2 do f[i]:=f[i]+f[j*2-1];
       inc(f[i]);
    end;
  end;
  writeln(f[n]);
  close(input);
  close(output);
end.
