var
n,i:longint;
k:int64;
begin
assign(input,'hanoi.in');
reset(input);
assign(output,'hanoi.out');
rewrite(output);
readln(n);
k:=1;
for i:=1 to n do
k:=k*2;
k:=k-1;
writeln(k);
close(input);
close(output);
end.
