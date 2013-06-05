var a,s,n:longint; f:array[1..20000]of longint;
begin
assign(input,'hanoi.in');
assign(output,'hanoi.out');
reset(input);
rewrite(output);
 readln(n);
 f[1]:=1;
 for a:=2 to n do
 f[a]:=2*f[a-1]+1;
 writeln(f[n]);
 close(output);
 end.