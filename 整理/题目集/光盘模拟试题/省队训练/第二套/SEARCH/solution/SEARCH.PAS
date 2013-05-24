
{
  HIO 2001
  Zadatak POTRAGA
  Autor rjesenja Ante Djerek
  Nesluzbeno rjesenje
}

PROGRAM potraga;
CONST
    max=50;
    maxsmjer=1000;
    prazno='.';
    zid='X';
    zivco='*';
    dirr:ARRAY[1..4] OF integer=(0, 1, 0, -1);
    dirs:ARRAY[1..4] OF integer=(1, 0, -1, 0);
    dirn:ARRAY[1..4] OF char=('E', 'S', 'W', 'N');

TYPE tocka=RECORD r, s:integer; END;
VAR
    m, n, k:integer;
    polje:ARRAY[1..max, 1..max] OF char;
    poc:tocka;
    nkand:integer;
    kand:ARRAY[1..max*max] OF tocka;
    smjer:ARRAY[1..maxsmjer] OF integer;

PROCEDURE citaj_ulaz;
VAR fin:text;
    i, j:integer;
    tmp:STRING;
BEGIN
    assign(fin, 'SEARCH.in');
    reset(fin);
    readln(fin, m, n);
    FOR i:=1 TO m DO
    BEGIN
        FOR j:=1 TO n DO
        BEGIN
            read(fin, polje[i, j]);
            IF polje[i, j]=zivco THEN
            BEGIN
                polje[i, j]:=prazno;
                poc.r:=i;
                poc.s:=j;
            END;
        END;
        readln(fin);
    END;
    readln(fin, k);
    FOR i:=1 TO k DO
    BEGIN
        readln(fin, tmp);
        FOR j:=1 TO 4 DO
            IF dirn[j]=tmp[1] THEN
                smjer[i]:=j;
    END;
    close(fin);
END;

FUNCTION valid (r, s:integer):boolean;
BEGIN
    valid:=TRUE;
    IF (r<1) OR (r>m) THEN valid:=FALSE
    ELSE IF (s<1) OR (s>n) THEN valid:=FALSE
    ELSE IF polje[r, s]=zid THEN valid:=FALSE;
END;

PROCEDURE rijesi;
VAR nnovih:integer;
    novi:ARRAY[1..max*max] OF tocka;
    r, s:integer;
    i, j:integer;
BEGIN
    nkand:=1;
    kand[1]:=poc;
    FOR i:=1 TO k DO
    BEGIN
        nnovih:=0;
        FOR j:=1 TO nkand DO
        BEGIN
            r:=kand[j].r+dirr[smjer[i]];
            s:=kand[j].s+dirs[smjer[i]];
            WHILE valid(r, s) DO
            BEGIN
                IF polje[r, s]=prazno THEN
                BEGIN
                    polje[r, s]:=zivco;
                    inc(nnovih);
                    novi[nnovih].r:=r;
                    novi[nnovih].s:=s;
                END;
                r:=r+dirr[smjer[i]];
                s:=s+dirs[smjer[i]];
            END;
        END;

        FOR j:=1 TO nnovih DO
        BEGIN
            kand[j]:=novi[j];
            polje[novi[j].r, novi[j].s]:=prazno;
        END;
        nkand:=nnovih;
    END;
END;

PROCEDURE ispisi_rjesenje;
VAR i, j:integer;
    fout:text;
BEGIN
    assign(fout, 'SEARCH.out');
    rewrite(fout);
    FOR i:=1 TO nkand DO
        polje[kand[i].r, kand[i].s]:=zivco;
    FOR i:=1 TO m DO
    BEGIN
        FOR j:=1 TO n DO
            write(fout, polje[i, j]);
        writeln(fout);
    END;
    close(fout);
END;

{ Glavni program }
BEGIN
    citaj_ulaz;
    rijesi;
    ispisi_rjesenje;
END.
