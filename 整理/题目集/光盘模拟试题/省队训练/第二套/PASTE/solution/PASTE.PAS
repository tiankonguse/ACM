
{
  HIO 2001
  Zadatak PASTA
  Autor rjesenja Ante Djerek
  Nesluzbeno rjesenje
}

PROGRAM pasta;
CONST maxcut=1000;
VAR poc, kraj, gdje:ARRAY[1..maxcut] OF longint;
    n, k:longint;

PROCEDURE citaj_ulaz;
VAR fin:text;
    i:longint;
BEGIN
    assign(fin, 'PASTE.in');
    reset(fin);
    readln(fin, n, k);
    FOR i:=1 TO k DO
        readln(fin, poc[i], kraj[i], gdje[i]);
    close(fin);
END;

FUNCTION unazad(novo, poc, kraj, gdje:longint):longint;
BEGIN
    { gdje sad oznacava prvu paste-anu poziciju }
    gdje:=gdje+1;
    { Ako je pozicija bila cut-ana i paste-ana }
    IF (novo>=gdje) AND (novo<=gdje+kraj-poc) THEN
    BEGIN
        unazad:=poc+novo-gdje;
        exit;
    END;
    { Odredjujem polozaj prije paste-anja }
    IF novo>gdje+kraj-poc THEN novo:=novo-(kraj-poc+1);
    { Odredjujem polozaj prije cut-anja }
    IF poc<=novo THEN novo:=novo+(kraj-poc+1);
    unazad:=novo;
END;

PROCEDURE rijesi;
VAR fout:text;
    i, j, poz:longint;
BEGIN
    assign(fout, 'PASTE.out');
    rewrite(fout);
    FOR i:=1 TO 10 DO
    BEGIN
        poz:=i;
        FOR j:=k DOWNTO 1 DO
            poz:=unazad(poz, poc[j], kraj[j], gdje[j]);
        writeln(fout, poz);
    END;
    close(fout);
END;

{ Glavni program }
BEGIN
    citaj_ulaz;
    rijesi;
END.
