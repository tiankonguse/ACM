    {Spring 2000 ,Junior ,Li Rui}
program num;
const
     inf='num.in';
     ouf='num.out';
var
   j1,j2,low,high,tar:longint;

function all(x:longint):integer;
var
   i,j,t:integer;
   a:array[1..40]of integer;
   y:longint;
   f:boolean;
begin
     t:=0;
     for i:=j1 to j2 do
     begin
          y:=x;
          j:=0;
          f:=true;
          while y<>0 do
          begin
               inc(j);
               a[j]:=y mod i;
               y:=y div i;
               if j>2 then
                if a[j]<>a[j-2] then
                 begin f:=false; break end;
               if j>1 then
                if a[j]=a[j-1] then
                 begin f:=false; break end;
          end;
          if f then inc(t);
          if t > tar then break;
     end;
     all:=t;
end;

var
   test:longint;
begin
     assign(input,inf);reset(input);
     assign(output,ouf);rewrite(output);
     readln(j1,j2,low,high,tar);

     for test:=low to high do
      if all(test) = tar then
            writeln(test);

     close(input);close(output);
end.
