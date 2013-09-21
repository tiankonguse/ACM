program heaven;
const day:array[1..11] of longint
          =(31,29,31,30,31,30,31,31,30,31,30);
var i,j,n,m,d,t,max:longint;
    s:array[1..367] of boolean;
begin
     assign(input,'heaven.in');
     reset(input);
     assign(output,'heaven.out');
     rewrite(output);
     read(n);
     fillchar(s,sizeof(s),false);
     s[367]:=true;
     for i:=1 to n do
     begin
          read(m,d);
          {writeln(m,' ',d);}
          t:=0;
          for j:=1 to m-1 do t:=t+day[j];
          t:=t+d;
          s[t]:=true;
     end;
     t:=0; max:=0;
     for i:=1 to 367 do
         if s[i] then
         begin
              if i-t-1>max then max:=i-t-1;
              t:=i
         end;
     writeln((max*24*60*60+183) div 366);
     close(input);
     close(output);
end.
