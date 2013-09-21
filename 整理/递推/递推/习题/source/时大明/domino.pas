var a,s,i,j:longint;f:array[1..200]of int64;
begin
 assign(input,'domino.in');
 assign(output,'domino.out');
 reset(input);
 rewrite(output);
 readln(i);
 f[1]:=1;
 f[2]:=2;
 for j:=3 to i do
 begin
 f[j]:=f[j-1]+f[j-2];
 end;
 writeln(f[i]);
  close(output);
  end.