const mo=10007;
var a,b,k,n,m,i,j:longint;
    f:array[0..1000,0..1000]of longint;
    ans:int64;

function g(x,y:longint):int64;
  begin
    if y=0 then g:=1
    else begin
      g:=g(x, y shr 1);
      g:=g*g mod mo;
      if odd(y) then g:=g*x mod mo;
    end;
  end;

begin
  assign(input,'factor.in');
  reset(input);
  assign(output,'factor.out');
  rewrite(output);
  readln(a,b,k,n,m);
  ans:=g(a,n)*g(b,m) mod mo;
  f[1,0]:=1;f[1,1]:=1;
  for i:=2 to k do begin
    f[i,0]:=1;
    for j:=1 to n do f[i,j]:=(f[i-1,j-1]+f[i-1,j])mod mo;
  end;
  writeln(ans*f[k,n] mod mo);
  close(input);
  close(output);
end.
