var total,pay,year,i:longint;
    rate,l,r,now:real;
begin
     assign(input,'loan.in');
     reset(input);
     readln(total,pay,year);
     r:=1;
     l:=0;
     while r-l > 1e-5 do
     begin
          rate := (l + r) /2 ;
          now := total;
          for i:=1 to year do now := now*(rate+1) - pay;
          if now < 0 then l := rate
          else r := rate;
     end;
     writeln(rate*100:0:2);
end.