
{
  Izborne pripreme 2001 - Prvi izborni ispit
  Zadatak SVADBA
  Autor rjesenja Mladen Kolar
  Nesluzbeno rjesenje
}

var
    koji,n,k,min,max,odakle_min,odakle_max,gdje_min,gdje_max:integer;
    a,gdje,rjesenje:array[1..10000] of integer;
    bio:array[1..10000] of boolean;
    visina:longint;

procedure readinp;
var
    f:text;
    i:integer;
begin
    visina:=0;
    assign(f,'WEDDING.in');
    reset(f);
    readln(f,n,k);
    readln(f,a[1]); min:=1; max:=1;
    for i:=2 to k do
        begin
            readln(f,a[i]);
            visina:=visina+abs(a[i-1]-a[i]);
            if a[i]<a[min] then min:=i;
            if a[i]>a[max] then max:=i;
        end;
    for i:=k+1 to n do readln(f,a[i]);
    close(f);
    for i:=1 to n do gdje[i]:=i;
    fillchar(bio,sizeof(bio),false);
end;


procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=gdje[i];
                gdje[i]:=gdje[j];
                gdje[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(k+1,n);
    end;


procedure solve;
var
    ostalo,i,j:integer;

function najmanji(x,y,z:integer):integer;
begin
    najmanji:=1;
    if y<z then if y<x then najmanji:=2;
    if y>z then if z<x then najmanji:=3;
end;


begin
    ostalo:=n-k;
    koji:=2; rjesenje[1]:=1;
    for i:=2 to k do
        begin
            if a[i-1]>a[i] then
               for j:=n downto k+1 do
                 if a[j]<a[i] then break else
                   if not bio[j] then
                    if (a[j]>=a[i]) and (a[j]<=a[i-1]) then
                        begin
                            dec(ostalo);
                            bio[j]:=true;
                            rjesenje[koji]:=gdje[j];
                            inc(koji);
                        end;

            if a[i-1]<a[i] then
               for j:=k+1 to n do
                 if a[j]>a[i] then break else
                   if not bio[j] then
                    if (a[j]<=a[i]) and (a[j]>=a[i-1]) then
                        begin
                            dec(ostalo);
                            bio[j]:=true;
                            rjesenje[koji]:=gdje[j];
                            inc(koji);
                        end;

            rjesenje[koji]:=i;
            inc(koji);
        end;

    if ostalo>0 then
        begin
            for i:=n downto k+1 do
                if bio[i] or (a[i]<a[max]) then break;
            odakle_max:=i+1;
            if odakle_max>n then gdje_max:=0 else
            gdje_max:=najmanji(abs(a[n]-a[1]),2*abs(a[max]-a[n]),abs(a[n]-a[rjesenje[koji-1]]));



            case gdje_max of
                1: begin
                    visina:=visina+abs(a[n]-a[1]);
                    a[1]:=a[n];
                end;
                2: visina:=visina+2*abs(a[max]-a[n]);
                3: begin
                    visina:=visina+abs(a[n]-a[k]);
                    a[k]:=a[n];
                end;
            end;


            for i:=k+1 to n do
                if bio[i] or (a[i]>a[min]) then break;
            odakle_min:=i-1;
            if odakle_min<k+1 then gdje_min:=0 else
            gdje_min:=najmanji(abs(a[k+1]-a[1]),2*abs(a[min]-a[k+1]),abs(a[k+1]-a[k]));

            case gdje_min of
                1: visina:=visina+abs(a[k+1]-a[1]);
                2: visina:=visina+2*abs(a[min]-a[k+1]);
                3: visina:=visina+abs(a[k+1]-a[k]);
            end;

        end;
end;

procedure writesol;
var
    f:text;
    i,j:integer;
begin
    assign(f,'WEDDING.out');
    rewrite(f);
    writeln(f,visina);

    if gdje_max=1 then
        for i:=n downto odakle_max do writeln(f,gdje[i]);
    if gdje_min= 1 then
        for i:=k+1 to odakle_min do writeln(f,gdje[i]);

    for i:=1 to koji-1 do
        begin
           if gdje_max=2 then
            if rjesenje[i]=max then
                for j:=n downto odakle_max do writeln(f,gdje[j]);
            writeln(f,rjesenje[i]);
           if gdje_min=2 then
            if rjesenje[i]=min then
                for j:=odakle_min downto k+1 do writeln(f,gdje[j]);
        end;

    if gdje_max=3 then
        for i:=odakle_max to n do writeln(f,gdje[i]);
    if gdje_min=3 then
        for i:=odakle_min downto k+1 do writeln(f,gdje[i]);

    close(f);
end;


begin
    readinp;
    qsort;
    solve;
    writesol;
end.
