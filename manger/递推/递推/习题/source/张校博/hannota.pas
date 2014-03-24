program hannota;
 var
  i,j,k,l,m,n:longint;
  f:array[1..100000]of longint;
 begin
 assign(input,'hanoi.in');reset(input);
 assign(output,'hanoi.out');rewrite(output);
  readln(n);i:=0;j:=2;
  if n=1 then writeln(1) else begin
  if n>1 then
   begin
    repeat
     i:=i+1;
     j:=j*2;
    until i=n-1;
    k:=j-1;
   end;
  writeln(k);end;
  close(input);close(output);
 end.
