var
n,i,j:longint;
f:array[0..30] of longint;

begin

assign(input,'tree.in');
assign(output,'tree.out');
reset(input);rewrite(output);

readln(n);

f[1]:=1;
f[0]:=1;

for i:=2 to n do
 begin
 for j:=0 to i-1 do f[i]:=f[i]+f[j]*f[i-j-1];
 end;

writeln(f[n]);

close(output);
end.