
{
  Izborne pripreme 2001 - Prvi izborni ispit
  Zadatak STRUJA
  Autor rjesenja Mladen Kolar
  Nesluzbeno rjesenje
}

var
    udalj,trosi:array[1..1000] of longint;
    n,gdje:integer;
    lijevo,desno,potrosnja:array[1..1000,1..1000] of longint;

procedure readinp;
var
    f:text;
    i:integer;
begin
    assign(f,'POWER.in');
    reset(f);
    readln(f,n);
    readln(f,gdje);
    for i:=1 to n do readln(f,udalj[i],trosi[i]);
    close(f);
end;

procedure solve;
var
    i,j:integer;
    x:longint;

    function min(a,b:longint):longint;
    begin
        if a>b then min:=b else min:=a;
    end;



begin

    x:=0;
    for i:=1 to n do x:=x+trosi[i];
    for i:=1 to n do
        begin
            potrosnja[i,i]:=x-trosi[i];
            for j:=1+i to n do potrosnja[i,j]:=potrosnja[i,j-1]-trosi[j];
        end;

    lijevo[1,n]:=maxlongint; desno[1,n]:=maxlongint;
    lijevo[gdje,gdje]:=0; desno[gdje,gdje]:=0;

    for i:=gdje+1 to n do
      begin
        desno[gdje,i]:=desno[gdje,i-1]+(udalj[i]-udalj[i-1])*potrosnja[gdje,i-1];
        lijevo[gdje,i]:=desno[gdje,i]+(udalj[i]-udalj[gdje])*potrosnja[gdje,i];
      end;

    for i:=gdje-1 downto 1 do
      begin
        lijevo[i,gdje]:=lijevo[i+1,gdje]+(udalj[i+1]-udalj[i])*potrosnja[i+1,gdje];
        desno[i,gdje]:=lijevo[i,gdje]+(udalj[gdje]-udalj[i])*potrosnja[i,gdje];
      end;

    for i:=gdje-1 downto 1 do
        for j:=gdje+1 to n do
            begin
                lijevo[i,j]:=min(lijevo[i+1,j]+(udalj[i+1]-udalj[i])*potrosnja[i+1,j],
                                desno[i+1,j]+(udalj[j]-udalj[i])*potrosnja[i+1,j]);
                desno[i,j]:=min(desno[i,j-1]+(udalj[j]-udalj[j-1])*potrosnja[i,j-1],
                                lijevo[i,j-1]+(udalj[j]-udalj[i])*potrosnja[i,j-1]);
            end;

end;

procedure writesol;
var
    f:text;
begin
    assign(f,'POWER.out');
    rewrite(f);
    if lijevo[1,n]<desno[1,n] then
        writeln(f,lijevo[1,n])
    else
        writeln(f,desno[1,n]);
    close(f);
end;

begin
    readinp;
    solve;
    writesol;
end.
