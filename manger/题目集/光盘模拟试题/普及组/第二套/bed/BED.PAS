var
 n,max:longint;
 a:array[1..5000]of longint;
 mo:array [0..1000000] of boolean;
procedure init;
var i:longint;
begin
  assign(input,'bed.in');reset(input);
  read(n);
  for i:=1 to n do read(a[i]);
  close(input);
end;
function prime(n:longint):boolean;
var i:longint;
begin
     i:=2;
     while (i*i<=n) and (n mod i<>0) do i:=i+1;
     if i*i>n then prime:=true else prime:=false
end;
procedure work;
var i,j,k,temp:longint;
begin
     fillchar(mo,sizeof(mo),false);
     max:=0;
     for i:=1 to n-1 do
         for j:=i+1 to n do
         begin
              temp:=abs(a[i]-a[j]);
              mo[temp]:=true;
              if temp>max then max:=temp
         end;
     i:=2;
     while prime(i) and (max div i>=n) do
     begin
          k:=i;
          while max div k>=n do
          begin
               for j:=n to max div k do
                   if mo[j*k] then mo[j]:=true;
               k:=k*i
          end;
          i:=i+1
     end
end;

procedure out;
var k:longint;
begin
  assign(output,'bed.out');rewrite(output);
  k:=n;
  while (k<=max) and mo[k] do k:=k+1;
  write(k);
  close(output);
end;
begin
  init;
  work;
  out;
end.
