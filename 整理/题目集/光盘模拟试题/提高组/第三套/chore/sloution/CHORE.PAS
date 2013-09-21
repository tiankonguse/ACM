program chores;

const
  inputfile='chore.in';
  outputfile='chore.out';
  MaxN=10000;

var
  f1,f2:text;
  f:array[1..MaxN]of longint;
  N:integer;
  last:longint;

procedure init;
begin
   assign(f1,inputfile);
   reset(f1);
   assign(f2,outputfile);
   rewrite(f2);
end;

procedure solve;
var i,id,list:integer;
    max:longint;
    long:byte;
begin
  readln(f1,N);
  fillchar(f,sizeof(f),0);
  last:=0;
  for i:=1 to N do
    begin
      read(f1,id);read(f1,long);
      max:=0;
      read(f1,list);
      while list <>0 do
        begin
          if f[list]>max then max:=f[list];
          read(f1,list);
        end;
      f[i]:=max+long;
      if f[i]>last then last:=f[i];
    end;
end;

procedure out;
begin
  close(f1);
  writeln(f2,last);
  close(f2);
end;

begin
  init;
  solve;
  out;
end.