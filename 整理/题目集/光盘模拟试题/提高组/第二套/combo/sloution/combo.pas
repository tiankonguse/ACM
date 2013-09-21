program combo(input,output);
var
  m,n:longint;
  i:longint;

begin
  assign(input,'combo.in');
  assign(output,'combo.out');
  reset(input);
  rewrite(output);
  readln(m);
  inc(m,m);
  for i:=trunc(sqrt(2*m)) downto 1 do
    begin
      n:=m div (i+1)-i;
      if n<0 then
        continue;
      if m/(i+1)-i=n then
        if n mod 2=0 then
          writeln(n div 2,' ',n div 2+i);
    end;
  close(input);
  close(output);
end.