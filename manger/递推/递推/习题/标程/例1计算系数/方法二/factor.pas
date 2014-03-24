const mo=10007;
var a,b,k,n,m,i,j:longint;
    f:array[0..1000,0..1000]of longint;
    ans,a1,b1,c1,x,y:int64;

function g(x,y:longint):int64;
  begin
    if y=0 then g:=1
    else begin
      g:=g(x, y shr 1);
      g:=g*g mod mo;
      if odd(y) then g:=g*x mod mo;
    end;
  end;

procedure gcd(a,b,c:longint;var x,y:int64);
  var x1,y1:int64;
  begin
    if b=0 then begin
       x:=c div a;
       y:=0;
    end else begin
       gcd(b,a mod b,c,x1,y1);
       x:=y1;
       y:=x1-a div b*y1;
    end;
  end;
begin
  assign(input,'factor.in');
  reset(input);
  assign(output,'factor.out');
  rewrite(output);
  readln(a,b,k,n,m);
  ans:=g(a,n)*g(b,m) mod mo;
  a1:=1;
  for i:=1 to n do a1:=a1*i mod mo;
  b1:=mo;
  c1:=1;
  for i:=k downto k-n+1 do c1:=c1*i mod mo;
  gcd(a1,b1,c1,x,y);
  x:=x mod mo;
  if x<0 then x:=x+mo;
  ans:=ans*x mod mo;
  writeln(ans);
  close(input);
  close(output);
end.
