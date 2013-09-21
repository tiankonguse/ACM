program zip;
 var
  n,i,p,j,k:longint;
  data:array[1..20000] of char;
  dat:array[1..20000]of char;
  mubiao:array[1..20000]of char;
  ch:char;
 begin
  assign(input,'zip.in');
  assign(output,'zip.out');
  reset(input);
  rewrite(output);
  readln(n);
  if n=0 then
   begin
    writeln;
    close(output);
    halt;
   end;
  for i:=1 to n do
   begin
    read(data[i]);
    dat[i]:=data[i];
   end;
  for i:=1 to n do
   begin
    mubiao[i]:=' ' ;
   end;
  readln;
  read(p);
  for i:=1 to n-1 do
   for j:=1+i to n do
    if dat[i]>dat[j] then
     begin
      ch:=dat[i];
      dat[i]:=dat[j];
      dat[j]:=ch;
     end;
  ch:=data[p] ;
  i:=1 ;
  while dat[i]<>ch do i:=i+1;
  k:=n;
  dat[i]:=' ';
  j:=i;
  repeat
   mubiao[k]:=data[j];
   k:=k-1;
   if k=0 then break;
   ch:=data[j];
   j:=n ;
   while dat[j]<>ch do j:=j-1;
   dat[j]:=' ';
  until k=0;
  for i:=1 to n do
   write(mubiao[i]);
  writeln;
  close(input);close(output);
 end.
