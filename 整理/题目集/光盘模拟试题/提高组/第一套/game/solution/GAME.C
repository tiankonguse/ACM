#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "game.in"
#define OUTPUT "game.out"

#define PSIZE 16384	/* Velikost pole na dosazene pozice */
#define WPSIZE 32768U	/* Velikost pole na pozice zmeny */
#define WDSIZE 8192	/* Velikost pole na smer zmeny */

/* Rozmery hry */
#define LINES 4
#define COLS 4

#define P_NO 0		/* O pozici nic nevime */
#define P_SPREAD 1	/* Z teto pozice se mame sirit */
#define P_N_SPREAD 3	/* Z teto pozice se mame sirit v pristim pruchodu */
#define P_DONE 2	/* Tato pozice je kompletne vyrizene */

/* Hodnoty smeru */
#define D_VERT 0
#define D_HORIZ 1

#define IMASK 0x55	/* Maska na testovani, zda jsou pozice zajimave */

#define SETPOS(P, Val) do {\
                         Pos[(P) >> 2] &= ~(3 << (((P) & 3) << 1));\
                         Pos[(P) >> 2] |= (Val) << (((P) & 3) << 1);\
                       } while (0)	/* Nastaveni pozice */
#define GETPOS(P) ((Pos[(P) >> 2] >> (((P) & 3) << 1)) & 3)		/* Vraceni hodnoty pozice */

#define SETWDIR(P, Val) ChDir[(P) >> 3] |= (Val) << ((P) & 7)	/* Nastavi smer zmeny */
#define GETWDIR(P) ((ChDir[(P) >> 3] & (1 << ((P) & 7))) != 0)	/* Vrati hodnotu smeru zmeny */

#define SETWPOS(P, Val) ChPos[(P) >> 1] |= (Val) << (((P) & 1) << 2)	/* Nastavi pozici zmeny */
#define GETWPOS(P) ((ChPos[(P) >> 1] >> (((P) & 1) << 2)) & 15)		/* Vrati pozici zmeny */

#define MAXMOVES 32	/* Maximalni pocet tahu */

typedef unsigned int id_t;
typedef unsigned int uint;
typedef unsigned char uchar;

uchar Pos[PSIZE];	/* Pole se zmenami */
uchar ChPos[WPSIZE];	/* Pole s pozicemi zmen */
uchar ChDir[WDSIZE];	/* Pole se smerem zmen */
id_t StartPos, FinPos;	/* Ohodnoceni pocatecni a cilove pozice */
int Move;		/* Cislo provadeneho tahu */

/* Nacte ze souboru pozici hry a vrati jeji ohodnoceni */
id_t ReadPos(FILE *File)
{
  id_t Val = 0;	/* Ohodnoceni pozice */
  int i, j;
  char Line[COLS+2];		/* Buffer na radek */

  for (i = 0; i < LINES; i++)
  {
    fgets(Line, sizeof(Line), File);
    for (j = 0; j < COLS; j++)
      Val |= (Line[j] == '1') << (i * COLS + j);
  }

  return Val;
}

/* Nacte pozice a spocite jejich ohodnoceni */
void ReadInp(void)
{
  FILE *In;
  char Tmp[8];

  if (!(In = fopen(INPUT, "r")))
  {
    puts("Can't open input file.");
    exit(1);
  }
  StartPos = ReadPos(In);
  fgets(Tmp, 8, In);	/* Nacteme prazdny radek */
  FinPos = ReadPos(In);
  fclose(In);
}

/* Vypise cestu do cilove pozice a skonci */
void PrintWay(void)
{
  FILE *Out;
  char MP[MAXMOVES];	/* Pozice zmen */
  char MD[MAXMOVES];	/* Smery zmen */
  id_t APos = FinPos;  	/* Aktualni pozice */
  int i;

  /* Ulozime si pozice do pole */
  for (i = Move; i >= 0; i--)
  {
    MP[i] = GETWPOS(APos);
    MD[i] = GETWDIR(APos);
    if (MD[i])
      APos ^= 3 << MP[i];
    else
      APos ^= (1 | (1 << COLS)) << MP[i];
  }

  if (!(Out = fopen(OUTPUT, "w")))
  {
    puts("Can't open output file.");
    exit(1);
  }
  fprintf(Out, "%d\n", Move+1);
  for (i = 0; i <= Move; i++)
    fprintf(Out, "%d %d %d %d\n", MP[i] / 4 + 1, MP[i] % 4 + 1, MP[i]/4 + 1 + !MD[i], MP[i] % 4 + 1 + MD[i]);
  fclose(Out);
  exit(0);
}

/* Prida novou pozici, pokud je to treba */
void AddPos(id_t P, id_t NP, uint CPos, uint CDir)
{
  if (GETPOS(NP) == P_NO)	/* Jeste jsme v teto pozici nebyli? */
  {
    /* Nastavime hodnoty zameny */
    SETWDIR(NP, CDir);
    SETWPOS(NP, CPos);

    if (NP == FinPos)	/* Mame cilovou pozici? */
      PrintWay();	/* Vytiskne cestu k cilove pozici a skonci */

    /* Nastavime spravnou hodnotu policku */
    if (NP < P)
      SETPOS(NP, P_SPREAD);
    else
      SETPOS(NP, P_N_SPREAD);
  }
}

/* Rozsiri se z dane pozice */
void Spread(id_t P)
{
  int i, j, FP;	/* ;; Cislo policka */
  id_t NP;	/* Nove ohodnoceni pozice */

  /* Nejdrive vsechny horizontalni zameny */
  for (i = 0, FP = 0; i < 4; i++, FP++)
    for (j = 0; j < 3; j++, FP++)
      if (!(P & (1 << FP)) != !(P & (1 << (FP + 1))))	/* Jsou policka ruzna? */
      {
        NP = P ^ (3 << FP);	/* Spocteme pozici po zamene */
        AddPos(P, NP, FP, D_HORIZ);
      }
  /* A ted vsechny vertikalni zameny */
  for (i = 0, FP = 0; i < 3; i++)
    for (j = 0; j < 4; j++, FP++)
      if (!(P & (1 << FP)) != !(P & (1 << (FP + COLS))))	/* Jsou policka ruzna? */
      {
        NP = P ^ ((1 | (1 << COLS)) << FP);	/* Spocteme pozici po zamene */
	AddPos(P, NP, FP, D_VERT);
      }
  SETPOS(P, P_DONE);
}

/* Nalezne nejkratsi posloupnost tahu */
void Go(void)
{
  id_t i, j;

  while (1)
  {
    for (i = 0; i < PSIZE; i++)
      if (Pos[i] & IMASK)	/* Je ve 4 pozicich nejaka k vyrizovani? */
      {
        for (j = 0; j < 4; j++)
          switch (GETPOS((i << 2) + j))
          {
            case P_N_SPREAD:
              SETPOS((i << 2) + j, P_SPREAD);
              break;
            case P_SPREAD:
              Spread((i << 2) + j);
              break;
          }
      }
    Move++;
  }
}

int main(void)
{
  memset(Pos, 0, PSIZE);
  memset(ChDir, 0, WDSIZE);
  memset(ChPos, 0, WPSIZE);

  ReadInp();		/* Nacte pozice a spocita jejich ohodnoceni */
  if (StartPos == FinPos)	/* Neni co delat? */
  {
    FILE *Out = fopen(OUTPUT, "w");	/* Jen vytvorime vystupni soubor */
    if (Out)
    {
      fputs("0\n", Out);
      fclose(Out);
    }
    return 0;
  }
  SETPOS(StartPos, P_SPREAD);
  Go();

  return 0;
}

