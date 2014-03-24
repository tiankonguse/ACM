program num(input,output);
var
  n,x,y,f:longint;
  i,j,k:longint;

begin
  assign(input,'num.in');
  reset(input);
  assign(output,'num.out');
  rewrite(output);
  readln(n);
  close(input);
  for i:=100 div n to 300 div n do
    if i*n>=100 then
      for j:=0 to 9 do
        begin
          x:=i*n;
          y:=x mod 100*10+j;
          if y mod n=0 then
            for k:=0 to 9 do
              if ((y mod 100*10+k) mod n=0) and (x*100+j*10+k<=30000) then
                begin
                  writeln(x,j,k);
                  f:=1;
                end;
        end;
  if f=0 then
    writeln('No');
  close(output);
end.