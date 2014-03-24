var ch:char;
begin
  for ch:='0' to '9' do begin
    assign(output,'lineup'+ch+'.in');
    rewrite(output);
    writeln(ord(ch)-47);
    close(output);
  end;
end.