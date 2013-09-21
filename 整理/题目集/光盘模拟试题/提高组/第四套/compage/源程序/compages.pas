program test1_4;
var a:array[1..100] of 1..1000;
    n:1..100;
    m,count:longint;
procedure init;
var i:integer;
begin
 assign(input,'compages.in');
 reset(input);
 readln(n,m);
 for i:=1 to n do read(a[i]);
 close(input); count:=0;
end;

procedure make(b,h:word);
var i,t:integer;
begin
 for i:=b to n do
  begin
   t:=h;
   t:=t+a[i];
   if t=m then count:=count+1
    else
     if t<m then if b+1<n then make(b+1,t);
  end;
end;

procedure print;
begin
 assign(output,'compages.out');
 rewrite(output);
 writeln(count);
 close(output);
end;

begin
 init;
 make(1,0);
 print;
end.