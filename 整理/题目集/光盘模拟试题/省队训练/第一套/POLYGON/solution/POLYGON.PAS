
{
  HIO 2001
  Zadatak POLYGON
  Autor rjesenja Ante Djerek
  Nesluzbeno rjesenje
}

PROGRAM poligon;
CONST
    maxn=100;
    no  =-1;
VAR
    x, y:ARRAY[1..maxn+1] OF integer;
    max :ARRAY[1..maxn+1,1..maxn+1] OF integer;
    n   :integer;

FUNCTION ccw (x1, y1, x2, y2, x3, y3:integer):integer;
VAR area:integer;
BEGIN
    area:=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    IF area<0 THEN ccw:=-1;
    IF area>0 THEN ccw:=1;
    IF area=0 THEN ccw:=0;
END;

PROCEDURE citaj_ulaz;
VAR fin:text;
    i  :integer;
BEGIN
    assign(fin, 'POLYGON.in');
    reset(fin);
    readln(fin, n);
    FOR i:=2 TO n+1 DO
        readln(fin, x[i], y[i]);
    x[1]:=0;
    y[1]:=0;
    n:=n+1;
    close(fin);
END;

PROCEDURE rijesi;
VAR i, j, k, jj:integer;
    tmp :integer;
BEGIN
    { Sortiram tocke }
    FOR i:=2 TO n-1 DO
        FOR j:=i+1 TO n DO
            IF y[i]*x[j]>y[j]*x[i] THEN
            BEGIN
                tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
                tmp:=y[i]; y[i]:=y[j]; y[j]:=tmp;
            END;
    { Pocetni uvjeti }
    FOR i:=2 TO n DO
        max[1, i]:=1;
    { Dinamika }
    FOR i:=2 TO n DO
        FOR jj:=i+1 TO n+1 DO
        BEGIN
            IF jj=n+1 THEN j:=1 ELSE j:=jj;
            max[i, j]:=no;
            FOR k:=1 TO i-1 DO
                IF ccw(x[k], y[k], x[i], y[i], x[j], y[j])=1 THEN
                    IF (max[i, j]=no) OR (max[k, i]+1>max[i, j]) THEN
                        max[i, j]:=max[k, i]+1;
        END;

END;

PROCEDURE ispisi_rjesenje;
VAR fout:text;
    i, sol :integer;
BEGIN
    assign(fout, 'POLYGON.out');
    rewrite(fout);
    sol:=2;
    FOR i:=2 TO n DO
        IF max[i, 1]>sol THEN
            sol:=max[i, 1];
    writeln(fout, sol);
    close(fout);
END;

{ Glavni program }
BEGIN
    citaj_ulaz;
    rijesi;
    ispisi_rjesenje;
END.
