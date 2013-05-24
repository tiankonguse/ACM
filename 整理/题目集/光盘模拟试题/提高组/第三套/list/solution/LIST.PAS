
{ DMIH 2001 - Drugi dan natjecanja        }
{ Srednjoskolska skupina - II. podskupina }
{ Zadatak LISTA                           }
{ Autor rjesenja Zvonimir Bujanovic       }
{ Nesluzbeno rjesenje                     }

const MAXN     = 100;
      MAXLEN   = 100;
      INFILE   = 'LIST.in';
      OUTFILE  = 'LIST.out';
      ISTO     = 'SAME';
      GORE     = 'UP';
      DOLJE    = 'DOWN';

var n : integer;
    kuda, link : array[0..MAXN] of integer;
    s : array[0..MAXN] of string[MAXLEN];

procedure load_data;
var i : integer;
    tmp : string[10];
    f : text;
begin
 assign (f, INFILE); reset (f);

 readln (f, n);
 for i:=0 to n-1 do
     begin
     readln (f, s[i]);
     readln (f, tmp);
     if (tmp=GORE) then kuda[i]:=1;
     if (tmp=DOLJE) then kuda[i]:=-1;
     end;
end;

procedure solve;
var i, j : integer;
begin
  for i:=0 to n-1 do link[i]:=i;
  i:=0; j:=0;

  while (j<n) do
    begin
    while ((i<n) and (kuda[i]=0)) do inc(i);
    while ((j<n) and (kuda[j]<>-1)) do inc (j);

    if (j<n) then link[i]:=j;
    inc(i); inc(j);
    end;

  j:=n-1; i:=n-1;
  while (j>=0) do
    begin
    while ((i>=0) and (kuda[i]=0)) do dec(i);
    while ((j>=0) and (kuda[j]<>1)) do dec(j);

    if (j>=0) then link[i]:=j;
    dec(i); dec(j);
    end;
end;

procedure write_output;
var f : text;
    i : integer;
begin
  assign (f, OUTFILE); rewrite (f);

  for i:=0 to n-1 do writeln (f, s[link[i]]);
  close (f);
end;

begin
  load_data;
  solve;
  write_output;
end.
