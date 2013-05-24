var i,j,k:longint;
begin
  assign(input,'combo.in');
  reset(input);
  assign(output,'combo.out');
  rewrite(output);
  readln(k);
  k:=2*k;
  for i:=trunc(sqrt(k)) downto 2 do
    if k mod i=0 then
      if ((k div i-i+1) mod 2=0)and((k div i-i+1)>0)and((k div i+i-1) mod 2=0)and((k div i+i-1)>0) then
        writeln((k div i-i+1) div 2,' ',(k div i+i-1) div 2);
  close(input);
  close(output);
end.