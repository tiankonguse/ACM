var
i,n:longint;
f:array[0..1000]of longint;
begin
assign(input,'hannoi.in');
assign(output,'hanoi.out');
reset(input);rewrite(output);
readln(n);
f[1]:=1;
for i:=1 to n do f[i]:=2*f[i-1]+1;
writeln(f[n]);
close(output);
end.