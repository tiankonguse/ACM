var n,i,j:integer;
    f:array[0..30]of int64;
begin
    assign(input,'tree.in');
    reset(input);
    assign(output,'tree.out');
    rewrite(output);
    readln(n);
    fillchar(f,sizeof(f),0);
    f[0]:=1;
    for i:=1 to n do begin
      for j:=0 to i-1 do f[i]:=f[i]+f[j]*f[i-1-j];
    end;
    writeln(f[n]);
    close(input);
    close(output);
end.
