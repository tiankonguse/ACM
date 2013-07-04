program change;
var i,m,n,v,t:longint;
    ch:char;
    num:string;
begin
     assign(input,'change.in');
     reset(input);
     assign(output,'change.out');
     rewrite(output);
     readln(n);
     readln(num);
     readln(m);
     v:=0;
     for i:=1 to length(num) do
     begin
          case num[i] of
               '0': t:=0;
               '1': t:=1;
               '2': t:=2;
               '3': t:=3;
               '4': t:=4;
               '5': t:=5;
               '6': t:=6;
               '7': t:=7;
               '8': t:=8;
               '9': t:=9;
               'A': t:=10;
               'B': t:=11;
               'C': t:=12;
               'D': t:=13;
               'E': t:=14;
               'F': t:=15
          end;
          v:=v*n+t
     end;
     num:='';
     while v<>0 do
     begin
          case v mod m of
               0: ch:='0';
               1: ch:='1';
               2: ch:='2';
               3: ch:='3';
               4: ch:='4';
               5: ch:='5';
               6: ch:='6';
               7: ch:='7';
               8: ch:='8';
               9: ch:='9';
               10: ch:='A';
               11: ch:='B';
               12: ch:='C';
               13: ch:='D';
               14: ch:='E';
               15: ch:='F'
          end;
          num:=ch+num;
          v:=v div m
     end;
     writeln(num);
     close(input);
     close(output);
end.
