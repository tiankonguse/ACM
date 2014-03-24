var
 f:array[0..30,0..100] of integer;
 n,m,i,j:integer;
begin
 assign(input,'ball1.in');
 reset(input);
 assign(output,'ball1.out');
 rewrite(output);
 readln(n,m);
 f[0,0]:=1;
 for i:=1 to n-1 do f[i,0]:=0;
 for j:=1 to m do
  for i:=0 to n-1 do
     f[i,j]:=f[(i+1) mod n,j-1]+f[(i+n-1) mod n,j-1];
 writeln(f[0,m]);
 close(input);
 close(output);
end.
