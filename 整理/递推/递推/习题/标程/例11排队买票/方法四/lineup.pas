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
    fillchar(f,sizeof(f),0);
    f[0]:=1;
    for i:=1 to n do begin
      for j:=0 to i-1 do begin
        g[i]:=g[i]+f[j]*c[2*(i-j)-1,i-j];
      end;
      f[i]:=c[2*i,i]-g[i];
    end;
    writeln(f[n]*jie[n]*jie[n]);
    close(input);
    close(output);
end.
