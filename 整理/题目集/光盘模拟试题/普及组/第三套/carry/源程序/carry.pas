program test1_2;
var n,i,j,k:integer;
    num:longint;
    a:array[1..1000] of integer;
    t:boolean;
begin
 assign(input,'carry.in'); assign(output,'carry.out');
 reset(input); readln(n);
 for i:=1 to n do read(a[i]);
 close(input);
 k:=n;
 repeat
  t:=true;
  for i:=1 to k-1 do
   if a[i]>a[i+1] then
    begin
    j:=a[i];a[i]:=a[i+1];a[i+1]:=j;
    num:=num+1;t:=false;
    end;
  k:=k-1;
 until t;
 rewrite(output);writeln(num);close(output);
end.