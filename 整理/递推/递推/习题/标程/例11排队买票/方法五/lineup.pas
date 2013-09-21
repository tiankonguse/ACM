var n,i,j:integer;
    f,g:array[0..10]of int64;
    c:array[0..20,0..20]of int64;
    jie:array[0..10]of int64;
begin
    assign(input,'lineup.in');
    reset(input);
    assign(output,'lineup.out');
    rewrite(output);
    readln(n);
    c[1,0]:=1;c[1,1]:=1;
    for i:=2 to n*2 do begin
      c[i,0]:=1;
      for j:=1 to i do c[i,j]:=c[i-1,j-1]+c[i-1,j];
    end;
    jie[0]:=1;
    for i:=1 to n do jie[i]:=jie[i-1]*i;
    writeln(c[2*n,n]div (n+1)*jie[n]*jie[n]);
    close(input);
    close(output);
end.
