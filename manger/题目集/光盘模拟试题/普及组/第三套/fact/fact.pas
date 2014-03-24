var n,i,k,ans,p2,p5,l:longint;

begin
  assign(input,'fact.in');
  assign(output,'fact.out');
  reset(input);
  rewrite(output);
  read(n);
  p2:=0;
  p5:=0;
  l:=2;
  repeat
    k:=n div l;
    p2:=p2+k;
    l:=l*2
  until k<=0;
  l:=5;
  repeat
    k:=n div l;
    p5:=p5+k;
    l:=l*5
  until k<=0;
  if p5>p2 then writeln(5)
  else begin
         ans:=1;
         for i:=1 to n do
           begin
             k:=i;
             while (k mod 5=0) do k:=k div 5;
             while (p5>0) and (k mod 2=0) do
               begin
                 k:=k div 2;
                 p5:=p5-1
               end;
             ans:=ans*k mod 10;
           end;
         writeln(ans);
       end;
  close(input);
  close(output);
end.
