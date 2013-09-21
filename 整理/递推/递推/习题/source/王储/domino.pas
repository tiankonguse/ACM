var
 a:array[1..100]of longint;
 n,i:integer;
begin
 assign(input,'domino.in');
 reset(input);
 assign(output,'domino.out');
 rewrite(output);
 readln(n);
 a[1]:=1;
 a[2]:=2;
 for i:=3 to n do a[i]:=a[i-1]+a[i-2];
 writeln(a[n]);
 close(input);
 close(output);
end.
