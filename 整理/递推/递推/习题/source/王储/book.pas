var
 f:array[1..1000]of integer;
 i,n:integer;
begin
 assign(input,'book.in');
 reset(input);
 assign(output,'book.out');
 readln(n);
 f[2]:=1;
 f[3]:=2;
 for i:=4 to n do f[i]:=(i-1)*(f[i-1]+f[i-2]);
 writeln(f[n]);
 close(input);
 close(output);
end.