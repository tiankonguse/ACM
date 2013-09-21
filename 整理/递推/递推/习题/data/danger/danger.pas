var ch:char;
    n,i,j:integer;
    f:array[0..30,0..3]of longint;
begin
  for ch:='0' to '9' do begin
    assign(input,'danger'+ch+'.in');
    reset(input);
    assign(output,'danger'+ch+'.out');
    rewrite(output);
    readln(n);
    fillchar(f,sizeof(f),0);
    f[1,2]:=1;
    f[1,3]:=2;
    for i:=2 to n do begin
      for j:=0 to 3 do begin
        if j=3 then f[i,j]:=1 shl i
        else if i<=3 then f[i,j]:=f[i-1,j+1]
        else f[i,j]:=f[i-1,j+1]+f[i-1,0];
      end;
    end;
    writeln(f[n,0]);
    close(input);
    close(output);
  end;
end.
