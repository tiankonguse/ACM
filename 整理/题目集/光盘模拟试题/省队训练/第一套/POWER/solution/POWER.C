
// Izborne pripreme 2001 - Prvi izborni ispit
// Zadatak STRUJA
// Autor rjesenja Ante Djerek i Zvonimir Bujanovic
// Nesluzbeno rjesenje

/*
        Struja - Djerek

        Rjesenje treba biti manje od 1000000000 (miljarda)

        Dinamicko rjesenje:
           LMin[a][b]  == Najmanja potrosnja da ugasim lampe a, ..., b
                          i da se na kraju nalazim kod lampe a
           RMin[a][b]  == Najmanja potrosnja da ugasim lampe a, ..., b
                          i da se na kraju nalazim kod lampe b
           Trosi[a][b] == Ukupna snaga kada su zarulje a, ..., b ugasene
           Dist[a]     == Udaljenost zarulje a od pocetka sela

        Vrijede relacije:
           LMin[a][b]=Min( LMin[a+1][b]+Trosi[a+1][b]*(Dist[a+1]-Dist[a]),
                           RMin[a+1][b]+Trosi[a+1][b]*(Dist[b]-Dist[a]) )
           RMin[a][b]=Min( Rmin[a][b-1]+Trosi[a][b-1]*(Dist[b]-Dist[b-1]),
                           Lmin[a][b-1]+Trosi[a][b-1]*(Dist[b]-Dist[a]) )

*/

#include <stdio.h>
#include <assert.h>

#define INFILE    "POWER.in"
#define OUTFILE   "POWER.out"
#define MAXLAMPI  1000
#define MAXSOL    1000000000
#define NO        -1
#define MIN(A, B) ((A)<(B)?(A):(B))

int n;
int dist[MAXLAMPI];
int snaga[MAXLAMPI];
int poc;

int lmin[MAXLAMPI][MAXLAMPI];
int rmin[MAXLAMPI][MAXLAMPI];
int trosi[MAXLAMPI][MAXLAMPI];
int lbps[MAXLAMPI][MAXLAMPI], rbps[MAXLAMPI][MAXLAMPI];

void citaj_ulaz (void)
{
    int i;
    FILE *input;

    input=fopen(INFILE, "r");
    fscanf(input, "%d", &n);
    fscanf(input, "%d", &poc);
    for (i=0; i<n; i++)
        fscanf(input, "%d %d", &dist[i], &snaga[i]);
    poc--;
    fclose(input);
}

void init_trosi (void)
{
    int ukupno;
    int i, j;

    ukupno=0;
    for (i=0; i<n; i++)
        ukupno+=snaga[i];

    for (i=0; i<n; i++)
    {
        trosi[i][i]=ukupno-snaga[i];
        for (j=i+1; j<n; j++)
            trosi[i][j]=trosi[i][j-1]-snaga[j];
    }
}

void rijesi (void)
{
    int a, b, i;

    init_trosi();

    lmin[poc][poc]=0;
    rmin[poc][poc]=0;

    for (b=poc+1; b<n; b++)
        {
         for (i=poc; i<b; i++)
             lmin[poc][b]+=trosi[poc][i]*(dist[i+1]-dist[i]);
         lmin[poc][b]+=trosi[poc][b]*(dist[b]-dist[poc]);
         lbps[poc][b]=1;
        }

    for (a=poc-1; a>=0; a--)
        {
         for (i=poc; i>a; i--)
             rmin[a][poc]+=trosi[i][poc]*(dist[i]-dist[i-1]);
         rmin[a][poc]+=trosi[a][poc]*(dist[poc]-dist[a]);
         rbps[a][poc]=1;
        }


    for (a=poc; a>=0; a--)
        for (b=poc; b<n; b++)
        {
            if (a==b) continue;
            if (a<poc)
               if (lmin[a+1][b]+trosi[a+1][b]*(dist[a+1]-dist[a]) <=
                               rmin[a+1][b]+trosi[a+1][b]*(dist[b]-dist[a]))
               {
                lmin[a][b]=lmin[a+1][b]+trosi[a+1][b]*(dist[a+1]-dist[a]);
                lbps[a][b]=lbps[a+1][b];
               }
               else
               {
                lmin[a][b]=rmin[a+1][b]+trosi[a+1][b]*(dist[b]-dist[a]);
                lbps[a][b]=rbps[a+1][b]+1;
               }

            if (b>poc)
               if (rmin[a][b-1]+trosi[a][b-1]*(dist[b]-dist[b-1]) <=
                               lmin[a][b-1]+trosi[a][b-1]*(dist[b]-dist[a]))
               {
                rmin[a][b]=rmin[a][b-1]+trosi[a][b-1]*(dist[b]-dist[b-1]);
                rbps[a][b]=rbps[a][b-1];
               }
               else
               {
                rmin[a][b]=lmin[a][b-1]+trosi[a][b-1]*(dist[b]-dist[a]);
                rbps[a][b]=lbps[a][b-1]+1;
               }



            assert(lmin[a][b]<MAXSOL);
            assert(rmin[a][b]<MAXSOL);
        }
}

void ispisi_rjesenje (void)
{
    FILE *output;

    output=fopen(OUTFILE, "w");
    fprintf(output, "%d\n", MIN(lmin[0][n-1], rmin[0][n-1]));

//    if (lmin[0][n-1] < rmin[0][n-1]) fprintf (output, "\n\nBroj skretanja = %d\n", lbps[0][n-1]);
//                                else fprintf (output, "\n\nBroj skretanja = %d\n", rbps[0][n-1]);

    fclose (output);
}

int main (void)
{
    citaj_ulaz();
    rijesi();
    ispisi_rjesenje();

    return 0;
}
