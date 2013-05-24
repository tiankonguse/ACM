
{
  Izborne pripreme 2001 - Drugi izborni ispit
  Zadatak MARICA
  Autor rjesenja Matija Kazalicki
  Nesluzbeno rjesenje
}

{
  rjesenje slozenosti dijkstra * broj vrhova u najkracem putu
  dijkstra pretpostavlja da se uvijek moze spojiti
}

const maxvrh = 1000;
      INFILE = 'marica.in';
      OUTFILE = 'marica.out';
      MAXLONG = 1000000;
type edge = record
     x, y: longint;
    end;

var  koliko : array[ 0..maxvrh ] of longint;
     vrh: array[ 0..maxvrh, 0..maxvrh ] of longint;
     tezina: array[ 0..maxvrh, 0..maxvrh ] of longint;
     pocetak, kraj : longint;
     v, e :longint;


     pamtilo:array[0..maxvrh] of edge;
     stanje :array[0..maxvrh] of longint;
     ukupno, jos :longint ;


     udaljenost:array[0..maxvrh] of longint;
     bio:array[0..maxvrh] of longint;

     rezultat: longint;

     b: edge;

     i,j :longint;

     jpg:boolean;

     mark: array[ 0..maxvrh, 0..maxvrh ] of longint;


procedure unos;
var f:text;
    i:longint;
    a,b,c:longint;
 begin
     fillchar(koliko,sizeof(koliko), 0 );
     fillchar(tezina,sizeof(tezina), 0 );
     rezultat:= 0;

     assign( f, INFILE ); reset( f );
     readln(f, v, e);
     for i:=1 to e do
       begin
        readln(f, a, b, c);
        inc( koliko[ a ]); vrh[ a, koliko[ a ] ] := b;
        inc( koliko[ b ]); vrh[ b, koliko[ b ] ] := a;
        tezina[ a, b ]:=c;
        tezina[ b, a ]:=c;

       end;

     pocetak:=1;
     kraj:=v;

     close( f );

 end;

procedure dijkstra( brid: edge );
var i, j, min, odabran :longint;
  begin
    jpg:=true;
    for i:=1 to v do
      begin
        udaljenost[i]:= maxlong;
        bio[i]:=0;
      end;

  udaljenost[pocetak]:=0;bio[pocetak]:=1;


  while (bio[kraj] >= 0) and (jpg) do
    begin

      min:=maxlong;

      for i:= 1 to v do if ( udaljenost[i] < min ) and ( bio[i] > 0 ) then
         begin
           min:= udaljenost[i];
           odabran:= i;
         end;

   {dodano}  if min =maxlong then
     begin
        jpg:=false;
        break;
      end;

     bio[odabran]:= -bio[odabran];

     for i:=1 to koliko[odabran] do
       begin

         if (( vrh[odabran,i] <> brid.y ) or ( odabran <> brid.x )) and (( vrh[odabran,i] <> brid.x ) or ( odabran <> brid.y )) then
           if udaljenost[vrh[odabran,i]]  > ( udaljenost[odabran] + tezina[odabran,vrh[odabran,i]]) then
              begin

                bio[vrh[odabran,i]]:=odabran;
                udaljenost[vrh[odabran,i]] :=  udaljenost[odabran] + tezina[odabran,vrh[odabran,i]] ;

              end;



       end;

    end;
  bio[pocetak]:=0;
  if udaljenost[kraj] > rezultat  then rezultat:= udaljenost[kraj] ;

  end;


procedure gen;
var i:longint;
 begin

   fillchar( stanje , sizeof( stanje ), 0 );
   fillchar( mark, sizeof( mark ), 0 );

   i:=kraj;
   while bio[i] <> 0 do
     begin

       b.x := -bio[i];
       b.y := i;
       inc( ukupno );
       pamtilo[ukupno]:=b;
       i:= - bio[i];
       mark[ b.x, b.y ] := ukupno;
     end;
     jos:=ukupno;



 end;

procedure oznaci;
var j:longint;

    temptab:array[ 0.. maxvrh] of longint;
begin

  fillchar( temptab, sizeof( temptab ), 0 );

  j:= kraj;

  while bio[j] <>0 do
    begin

     temptab[mark[-bio[j],j]]:=1;
     j:= - bio[j];

    end;

  for j:=1 to ukupno do

    if ( temptab[j]=0 ) and ( stanje[j]=0 ) then
       begin
         stanje[j]:=1;
         dec( jos );
       end;


end;

procedure ispis;
var f:text;
 begin
  assign( f, OUTFILE ); rewrite ( f );
  if jpg then writeln( f, rezultat ) else writeln(f,'NEMA RJESENJA' );
  close( f );

 end;

begin
 unos;
 jpg:=true;
 b.x:=0; b.y:=0;
 dijkstra( b );
 gen;
 i:=1;

 while (jos <>0) and jpg do
   begin

     while stanje[i]<>0 do inc( i );

     stanje[i]:= 1; dec( jos );
     b.x:=pamtilo[i].x; b.y:=pamtilo[i].y;
     dijkstra( b );
     if not jpg then break;
     oznaci;


   end;

 ispis;

end.
