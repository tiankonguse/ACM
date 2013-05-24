
// HIO 2001
// Zadatak POTRAGA
// Autor rjesenja Bojan Antolovic
// Nesluzbeno rjesenje

#include <stdio.h>

#define INPUTFILE "SEARCH.in"
#define OUTPUTFILE "SEARCH.out"

#define MAXR 50
#define MAXS 50
#define PRAZNO '.'
#define ZID 'X'
#define POCETNO '*'
#define ZAVRSNO '*'

#define MAXPOTEZA 1000
#define GORE 'N'
#define DOLJE 'S'
#define LIJEVO 'W'
#define DESNO 'E'


int r, s;
char ploca[MAXR][MAXS+1];
int pocr, pocs;
int n;
typedef struct { int r, s; } rs;
rs potezi[MAXPOTEZA];

int broj_tren, broj_sljed;
rs trenutni[MAXR*MAXS];
rs sljedeci[MAXR*MAXS];

void citaj_input(void)
{
	int i, j;
	char str[20];
	FILE *f = fopen(INPUTFILE, "rt");

	fscanf(f, "%d%d", &r, &s);
	for (i=0; i<r; i++)
	{
		fscanf(f, "%s", ploca[i]);
		for (j=0; j<s; j++)
			if (ploca[i][j]==POCETNO)
			{
				pocr = i;
				pocs = j;
			}
	}
	fscanf(f, "%d", &n);
	for (i=0; i<n; i++)
	{
		fscanf(f, "%s", str);
		if (str[0]==GORE) { potezi[i].r = -1; potezi[i].s = 0; }
		if (str[0]==DOLJE) { potezi[i].r = 1; potezi[i].s = 0; }
		if (str[0]==LIJEVO) { potezi[i].r = 0; potezi[i].s = -1; }
		if (str[0]==DESNO) { potezi[i].r = 0; potezi[i].s = 1; }
	}
	fclose(f);
}

void rijesi(void)
{
	int p, i;
	int tr, ts;

	broj_tren = 1;
	trenutni[0].r = pocr;
	trenutni[0].s = pocs;

	for (p=0; p<n; p++)
	{
		// Brisi stare oznake pozicije:

		for (i=0; i<broj_tren; i++)
			ploca[trenutni[i].r][trenutni[i].s] = PRAZNO;

		// Nadi sve moguce nove pozicije:

		broj_sljed = 0;
		for (i=0; i<broj_tren; i++)
		{
			// Za svaku poziciju u kojoj bi trenutno mogao biti...

			tr = trenutni[i].r;
			ts = trenutni[i].s;
			while (1)
			{
				// ...idi u zadanom smjeru dokle moze i oznaci nove pozicije

				tr += potezi[p].r;
				ts += potezi[p].s;
				if (tr<0 || tr>=r || ts<0 || ts>=s) break;
				if (ploca[tr][ts]!=PRAZNO) break;

				sljedeci[broj_sljed].r = tr;
				sljedeci[broj_sljed].s = ts;
				broj_sljed++;
				ploca[tr][ts] = ZAVRSNO;
			};
		}

		// sljedece -> trenutne

		for (i=0; i<broj_sljed; i++)
			trenutni[i] = sljedeci[i];
		broj_tren = broj_sljed;
	}
}

void pisi_output(void)
{
	int i;
	FILE *f = fopen(OUTPUTFILE, "wt");

	for (i=0; i<r; i++)
		fprintf(f, "%s\n", ploca[i]);
	fclose(f);
}

int main()
{
	citaj_input();
	rijesi();
	pisi_output();
	return 0;
}
