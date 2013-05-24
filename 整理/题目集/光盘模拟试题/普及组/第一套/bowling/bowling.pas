program bowling;
const max=20;
var p,fin:string;
    a:array[1..max,1..2] of integer;
    b:array[1..max] of integer;
    c:array[1..max] of string;
    i,j,k,s,y:integer;
begin
  assign(input,'bowling.in');
  assign(output,'bowling.out');
  reset(input);
  rewrite(output);
  read(p);
  fillchar(a,sizeof(a),0);
  i:=1;j:=1;
  while i<=length(p) do
  begin
    while p[i]=' ' do i:=i+1;
    if (p[i]='/') and (a[j,1]=0) then begin a[j,1]:=10; c[j]:='/'; j:=j+1; i:=i+1; end
       else if (a[j,1]<>0) and (p[i]='/')
                         then begin a[j,2]:=10-a[j,1]; c[j]:=chr(a[j,1]+ord('0'))+'/'; j:=j+1; i:=i+1; end
                         else begin
                              if a[j,1]=0 then begin
                                               a[j,1]:=ord(p[i])-ord('0');
                                               i:=i+1;
                                               end
                                          else
                                          begin a[j,2]:=ord(p[i])-ord('0');
                                                c[j]:=chr(a[j,1]+ord('0'))+chr(a[j,2]+ord('0'));
                                                j:=j+1;
                                                i:=i+1;
                                          end;
                              end;
  end;
  k:=j-1;
  fillchar(b,sizeof(b),0);
  for i:=1 to k do
  begin
    if a[i,1]=10
       then begin j:=1; b[i]:=b[i]+10; y:=i+1;
                  while (j<3) and (y<=k-1) do
                  begin
                    if (a[y,1]=10) then
                       begin b[i]:=b[i]+a[y,1]; y:=y+1; j:=j+1; end;
                    if (a[y,1]+a[y,2]=10) and (a[y,1]<10) and (a[y,2]<10) and (j=1)
                       then begin b[i]:=b[i]+10; j:=j+2; end
                       else if (a[y,1]+a[y,2]=10) and (a[y,1]<10) and (a[y,2]<10) and (j=2)
                               then begin b[i]:=b[i]+a[y,1]; j:=j+1; end;
                    if (a[y,1]+a[y,2]<10) and (j=1)
                       then begin b[i]:=b[i]+a[y,1]+a[y,2];j:=j+2;end
                       else if j=2 then begin b[i]:=b[i]+a[y,1]; j:=j+1; end;
                  end;
                  if (j<3) or (b[i]<=10) then b[i]:=-b[i];
            end
       else begin
              if (a[i,1]+a[i,2]=10) and (i<=k-1) then begin b[i]:=b[i]+10+a[i+1,1] end
              if a[i,1]+a[i,2]<10 then begin b[i]:=b[i]+a[i,1]+a[i,2] end;
            end;
  end;
  for i:=1 to k do if b[i]>0 then if i<>k then write(b[i],' ') else write(b[i]);
  writeln;
  s:=0;
  for i:=1 to k do begin
                     if b[i]>0 then s:=s+b[i];
                     if b[i]>0 then if i<>k then write(s,' ') else write(s);
                   end;
  close(input);
  close(output);
end.
