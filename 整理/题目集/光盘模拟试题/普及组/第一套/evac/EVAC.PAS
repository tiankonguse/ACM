program Evac;
const
  maxr=50;
  maxn=100;
var
  a:array[1..maxr,1..maxr] of byte;
  N:byte;
  cows:array[1..maxn,1..4] of byte;
  R,C:byte;

procedure init;
var i:byte;
begin
   assign(input,'evac.in');
   reset(input);
   assign(output,'evac.out');
   rewrite(output);
   readln(R,C);
   fillchar(a,sizeof(a),0);
   readln(N);
   fillchar(cows,sizeof(cows),0);
   for i:=1 to N do
     begin
       readln(cows[i,1],cows[i,2]);
       a[cows[i,1],cows[i,2]]:=i;
     end;
   close(input);
end;

procedure solve;
var id,i,j,t,t1,x:byte;
    flag:boolean;
begin
  t:=0;
  for id:=1 to N do
    begin
      for i:=1 to cows[id,1]-1 do
        if a[i,cows[id,2]]<>0 then inc(cows[id,3]);
      for j:=cows[id,2]+1 to C do
        if a[cows[id,1],j]<>0 then inc(cows[id,4]);
    end;
  for id:=1 to N do if cows[id,3]*cows[id,4]<>0 then inc(t);
  if t=0 then
    begin writeln(0);exit;end;
  flag:=true;
  for id:=1 to N do
    begin
      t1:=t;
      if cows[id,3]*cows[id,4]<>0 then dec(t1);
      for i:=cows[id,1]+1 to R do
        if a[i,cows[id,2]]>0 then
         begin
          x:=a[i,cows[id,2]];
          if (cows[x,3]=1)and(cows[x,4]<>0) then dec(t1);
         end;
      for j:=1 to cows[id,2]-1 do
        if a[cows[id,1],j]>0 then
         begin
          x:=a[cows[id,1],j];
          if (cows[x,4]=1)and(cows[x,3]<>0) then dec(t1);
         end;
      if t1=0 then
        begin writeln(id);flag:=false; end;
    end;
  if flag then writeln(-1);
end;

begin
  init;
  solve;
  close(output);
end.