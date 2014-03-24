var n,k,i,min,sum,answer,yourans:longint;
    h,order,f:array [1..10000] of longint;

procedure error(no:longint);
begin
     writeln;
     if no=1 then writeln('Your Answer is error!');
     if no=2 then writeln('Your solution is error!');
     writeln;
     halt
end;

begin
     assign(input,'wedding.in');
     reset(input);
     read(n,k);
     for i:=1 to n do read(h[i]);
     close(input);
     assign(input,'wedding.ans');
     reset(input);
     read(answer);
     close(input);
     assign(input,'wedding.out');
     reset(input);
     read(yourans);
     if yourans<>answer then error(1);
     for i:=1 to n do read(order[i]);
     close(input);
     for i:=1 to n do f[i]:=0;
     for i:=1 to n do f[order[i]]:=f[order[i]]+1;
     for i:=1 to n do
         if f[order[i]]<>1 then error(2);
     i:=2; min:=0; sum:=0;
     while i<=n do
     begin
          if (order[i]<=k) and (order[i]<=min) then error(2);
          sum:=sum+abs(h[order[i]]-h[order[i-1]]);
          if order[i]<=k then min:=order[i];
          i:=i+1
     end;
     if sum<>yourans then error(2);
     writeln;
     writeln('Your answer and solution is all right!');
     writeln
end.
