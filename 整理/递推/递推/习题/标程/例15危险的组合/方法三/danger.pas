var n,i,j:integer;
    g:array[0..30,0..2]of longint;
    ans:longint;
begin
    assign(input,'danger.in');
    reset(input);
    assign(output,'danger.out');
    rewrite(output);
    readln(n);
    if n=3 then writeln(1)
    else if n=4 then writeln(3)
    else begin
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
      ans:=1 shl (n-3)+1 shl (n-4);
      for i:=3 to n-2  do inc(ans,g[i-2,0]*(1 shl (n-i-2)));
      writeln(ans);
    end;
    close(input);
    close(output);
end.
