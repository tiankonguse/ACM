var n,i,j:integer;
    f:array[0..32]of int64;
begin
    assign(input,'polygon.in');
    reset(input);
    assign(output,'polygon.out');
    rewrite(output);
    readln(n);
    fillchar(f,sizeof(f),0);
    f[2]:=1;
    for i:=3 to n do begin
      for j:=2 to i-1 do f[i]:=f[i]+f[j]*f[i+1-j];
    end;
    writeln(f[n]);
    close(input);
    close(output);
end.
