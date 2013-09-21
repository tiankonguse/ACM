var ch:char;
    n,m:integer;
begin
  for ch:='0' to '9' do begin
    assign(output,'divide1'+ch+'.in');
    rewrite(output);
    n:=5*(ord(ch)-47);
    m:=n div 2;
    writeln(n,' ',m);
    close(output);
  end;
end.