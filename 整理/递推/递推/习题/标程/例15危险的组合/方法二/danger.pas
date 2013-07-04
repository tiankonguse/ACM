var n,i,j:integer;
    g:array[0..30,0..2]of longint;
begin
    assign(input,'danger.in');
    reset(input);
    assign(output,'danger.out');
    rewrite(output);
    readln(n);
    fillchar(g,sizeof(g),0);
    g[1,0]:=2;
    g[1,1]:=2;
    g[1,2]:=1;
    for i:=2 to n do begin
      for j:=0 to 2 do begin
        if j=2 then g[i,j]:=g[i-1,0]
        else g[i,j]:=g[i-1,j+1]+g[i-1,0];
      end;
    end;
    writeln(1 shl n-g[n,0]);
    close(input);
    close(output);
end.
