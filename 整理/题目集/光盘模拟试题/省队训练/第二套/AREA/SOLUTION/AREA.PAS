 {$N+}var n,a,b,c,i:longint;
          x,y:array[1..200]of longint;
          s:extended;
 function are(x1,y1,x2,y2,x3,y3:longint):extended;
  var a,b,c,p:extended;
  begin
   a:=sqrt(sqr(x1-x2)+sqr(y1-y2));b:=sqrt(sqr(x1-x3)+sqr(y1-y3));c:=sqrt(sqr(x2-x3)+sqr(y2-y3));
   p:=(a+b+c)/2;are:=sqrt(p*(p-a)*(p-b)*(p-c));
  end;
 begin
  assign(input,'area.in');assign(output,'area.out');
  reset(input);rewrite(output);
  read(n);read(x[1],y[1]);read(x[2],y[2]);
  for i:=3 to n do
   begin
    read(x[i],y[i]);
    a:=y[1]-y[i-1];b:=x[i-1]-x[1];c:=x[1]*y[i-1]-x[i-1]*y[1];
    if a*x[i]+b*y[i]+c<0 then
     s:=s-are(x[1],y[1],x[i],y[i],x[i-1],y[i-1]) else
    s:=s+are(x[1],y[1],x[i],y[i],x[i-1],y[i-1]);
   end;
  writeln(abs(s):0:0);close(output);
 end.