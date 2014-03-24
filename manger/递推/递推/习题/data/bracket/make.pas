var ch:char;
begin
  for ch:='0' to '9' do begin
    assign(output,'tree'+ch+'.in');
    rewrite(output);
    writeln(3*(ord(ch)-47));
    close(output);
  end;
end.
