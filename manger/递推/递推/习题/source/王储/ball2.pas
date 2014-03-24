var
 f:array[0..100,0..100]of longint;
 n,r,i,j:integer;
begin
 assign(input,'ball2.in');
 reset(input);
 assign(output,'ball2.out');
 rewrite(output);
 readln(n,r);
 for i:=1 to 100 do f[i,0]:=0;
 for i:=1 to 100 do f[0,i]:=0;
 for i:=1 to n do
  for j:=1 to r do
   begin
    if i=j then f[i,j]:=1;
    if i>j then f[i,j]:=j*f[i-1,j]+f[i-1,j-1];
   end;
 writeln(f[n,r]);
 close(input);
 close(output);
end.
