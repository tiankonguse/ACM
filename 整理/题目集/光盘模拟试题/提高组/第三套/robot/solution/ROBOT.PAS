program robot;
const
    maxn=50;
    dx:array[0..3]of longint=(0,1,0,-1);
    dy:array[0..3]of longint=(1,0,-1,0);
type
    Tmap=array[0..maxn,0..maxn]of longint;
    Tstt=array[0..maxn,0..maxn,0..3]of longint;
var
    map,nmap:Tmap;
    stp:Tstt;
    m,n,mins,bi,bj,ei,ej,d,i,j,k:longint;
    p:boolean;
    dir:char;
begin
    assign(input,'robot.in');
    reset(input);
    assign(output,'robot.out');
    rewrite(output);
    readln(m,n);
    fillchar(map,sizeof(map),0);
    fillchar(nmap,sizeof(nmap),0);
    for i:=1 to m do
      for j:=1 to n do
        read(map[i,j]);
    for i:=1 to m-1 do
      for j:=1 to n-1 do
        if (map[i,j]=0) and (map[i,j+1]=0) and (map[i+1,j]=0) and (map[i+1,j+1]=0) then
          nmap[i,j]:=1;
    read(bi,bj,ei,ej);
    read(dir);
    while dir=' ' do read(dir);
    case dir of
    'E':d:=0;
    'S':d:=1;
    'W':d:=2;
    'N':d:=3;
    end;
    fillchar(stp,sizeof(stp),$7f);
    if nmap[bi,bj]=1
      then stp[bi,bj,d]:=0;
    p:=true;
    while p do
    begin
      p:=false;
      for i:=1 to m-1 do
        for j:=1 to n-1 do
          for k:=0 to 3 do
            if (nmap[i,j]=1) and (stp[i,j,k]<10000) then
            begin
              if nmap[i+dx[k],j+dy[k]]=1 then
              begin
                if stp[i+dx[k],j+dy[k],k]>stp[i,j,k]+1 then
                begin
                  stp[i+dx[k],j+dy[k],k]:=stp[i,j,k]+1;
                  p:=true;
                end;
                if nmap[i+2*dx[k],j+2*dy[k]]=1 then
                begin
                  if stp[i+2*dx[k],j+2*dy[k],k]>stp[i,j,k]+1 then
                  begin
                    stp[i+2*dx[k],j+2*dy[k],k]:=stp[i,j,k]+1;
                    p:=true;
                  end;
                  if nmap[i+3*dx[k],j+3*dy[k]]=1 then
                    if stp[i+3*dx[k],j+3*dy[k],k]>stp[i,j,k]+1 then
                    begin
                      stp[i+3*dx[k],j+3*dy[k],k]:=stp[i,j,k]+1;
                      p:=true;
                    end;
                end;
              end;
              if stp[i,j,(k+1) mod 4]>stp[i,j,k]+1 then
              begin
                stp[i,j,(k+1) mod 4]:=stp[i,j,k]+1;
                p:=true;
              end;
              if stp[i,j,(k+3) mod 4]>stp[i,j,k]+1 then
              begin
                stp[i,j,(k+3) mod 4]:=stp[i,j,k]+1;
                p:=true;
              end;
            end;
    end;
    mins:=10000;
    for k:=0 to 3 do
      if mins>stp[ei,ej,k] then
        mins:=stp[ei,ej,k];
    if mins=10000
      then writeln(-1)
      else writeln(mins);
    close(input);
    close(output);
end.
