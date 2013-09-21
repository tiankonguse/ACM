program zip;
var
  f:text;
  now:char;
  i,l,n,p,r,mid:longint;
  used:array[1..10000] of 0..1;
  ch,he,res:array[1..10000] of char;

procedure sort(l,r:longint);
var
  x,y:char;
  i,j:longint;
begin
  i:=l;j:=r;x:=he[(l+r) div 2];
  repeat
    while he[i]<x do inc(i);
    while x<he[j] do dec(j);
    if i<=j then
    begin
      y:=he[i];he[i]:=he[j];he[j]:=y;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  assign(f,'zip.in');
  reset(f);
  readln(f,n);
  for i:=1 to n do read(f,ch[i]);
  readln(f,p);
  close(f);

  he:=ch;
  sort(1,n);

  for i:=1 to n do
    if he[i]=ch[p] then break;
  fillchar(used,sizeof(used),0);
  res[n]:=ch[i];res[1]:=ch[p];now:=res[n];
  for i:=n-1 downto 2 do
  begin
    l:=1;r:=n;
    while r-l>1 do
    begin
      mid:=(r+l) div 2;
      if (he[mid]>now) or ((he[mid]=now) and (used[mid]=1)) then r:=mid else l:=mid;
    end;
    if (he[r]=now) and (used[r]=0) then
    begin
      res[i]:=ch[r];
      used[r]:=1;
    end
    else
    begin
      res[i]:=ch[l];
      used[l]:=1;
    end;
    now:=res[i];
  end;

  assign(f,'zip.out');
  rewrite(f);
  for i:=1 to n do write(f,res[i]);
  writeln(f);
  close(f);
end.