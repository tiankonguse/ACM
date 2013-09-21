program book;
 var
  i,j,k,l,m,n:longint;
  f:array[-1..50]of longint;
  procedure book(n:longint);
   begin
   f[1]:=0;f[2]:=1;
    for i:=3 to n do
     f[i]:=(i-1)*(f[i-1]+f[i-2]);
   end;
  begin
   assign(input,'book.in');reset(input);
   assign(output,'book.out');rewrite(output);
   readln(n);
   book(n);
   writeln(f[n]);
   close(input);close(output);
  end.
