program list;
var
  f:text;
  str:string;
  i,n,p1,p2:longint;
  po:array[0..102] of longint;
  st,res:array[0..102] of string;

begin
  assign(f,'list.in');
  reset(f);
  readln(f,n);
  for i:=1 to n do
  begin
    readln(f,st[i]);
    readln(f,str);
    if str='UP' then po[i]:=1;
    if str='SAME' then po[i]:=2;
    if str='DOWN' then po[i]:=3;
  end;
  close(f);

  p1:=1;while (po[p1]<>1) and (p1<n) do inc(p1);
  p2:=1;while (po[p2]<>3) and (p2<n) do inc(p2);
  for i:=1 to n do
  begin
    if po[i]=2 then begin res[i]:=st[i];continue;end;
    if po[p1]=1 then begin res[i]:=st[p1];inc(p1);while (po[p1]<>1) and (p1<n) do inc(p1);continue;end;
    if po[p2]=3 then begin res[i]:=st[p2];inc(p2);while (po[p2]<>3) and (p2<n) do inc(p2);continue;end;
  end;

  assign(f,'list.out');
  rewrite(f);
  for i:=1 to n do
    writeln(f,res[i]);
  close(f);
end.