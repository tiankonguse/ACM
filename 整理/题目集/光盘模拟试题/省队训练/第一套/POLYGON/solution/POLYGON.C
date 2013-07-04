
// HIO 2001
// Zadatak POLYGON
// Autor rjesenja Ante Djerek
// Nesluzbeno rjesenje

/*
    Poligon - Djerek

    Zadan je niz tocaka sa pozitivnim koordinatama, trazi se najveci
    moguci konveksni poligon kojem je jedan vrh ishodiste, a ostali
    vrhovi u nekima od zadanih tocaka.

    Dinamicko rjesenje:
        -sortiramo tocke po kutu sa x osi (tj. po y/x)
        -neka Max[b][a] oznacava velicinu najveceg poligona kojemu
         su zadnje dvije tocke (prije povratka u ishodiste) b i a
         (a je zadnja, b je predzadnja)
        -vrijedi relacija:

                 Max[b][a] = Najveci (Max[c][b]+1)
                 gdje je 0<=c<b i ccw(c, b, a)==1

        -vremenska slozenost: O(n^3)
        -prostorna slozenost: O(n^2)
*/

#include <stdio.h>

#define MAXTOCAKA   100
#define MAXRANGE    100
#define INFILE      "POLYGON.in"
#define OUTFILE     "POLYGON.out"
#define NO -1

int n;
int x[MAXTOCAKA+1];
int y[MAXTOCAKA+1];
int max[MAXTOCAKA+1][MAXTOCAKA+1];
int how[MAXTOCAKA+1][MAXTOCAKA+1];

int ccw (int x1, int y1, int x2, int y2, int x3, int y3)
{
    long area;

    area=(long) x1*(y2-y3) + (long) x2*(y3-y1) + (long) x3*(y1-y2);
    if (area<0) return -1;
    if (area>0) return 1;
    return 0;
}

void read_input (FILE *input)
{
    int i;

    fscanf(input, "%d", &n);
    x[0]=0;
    y[0]=0;
    for (i=1; i<=n; i++)
        fscanf(input, "%d %d", &x[i], &y[i]);
    n++;
}

void sort (void)
{
    int i, j;
    int tmp;

    for (i=1; i<n-1; i++)
    for (j=i+1; j<n; j++)
        if ((long) y[i]*x[j] > (long) y[j]*x[i])
        {
            tmp=x[i]; x[i]=x[j]; x[j]=tmp;
            tmp=y[i]; y[i]=y[j]; y[j]=tmp;
        }
}

void write_output (FILE *output)
{
    int i;
    int zadnji, predzadnji;
    int sol;
    int tmp;

    zadnji=1;
    for (i=2; i<n; i++)
        if (max[i][0]>max[zadnji][0]) zadnji=i;
    sol=max[zadnji][0];

    fprintf(output, "%d\n", sol);

/*
    predzadnji=zadnji;
    zadnji=0;
    for (i=0; i<sol; i++)
    {
        fprintf(output, "%d %d\n", x[predzadnji], y[predzadnji]);
        tmp=how[predzadnji][zadnji];
        zadnji=predzadnji;
        predzadnji=tmp;
    }
*/
}

void solve (void)
{
    int i, j, k;

    for (i=1; i<n; i++)
        max[0][i]=1;

    for (i=1; i<n; i++)
        for (j=i+1; j<=n; j++)
        {
            max[i][j%n]=NO;
            for (k=0; k<i; k++)
                if (ccw(x[k], y[k], x[i], y[i], x[j%n], y[j%n])==1)
                   if (max[i][j%n]==NO || max[k][i]+1>max[i][j%n])
                   {
                        max[i][j%n]=max[k][i]+1;
                        how[i][j%n]=k;
                   }
        }
}

int main (void)
{
    FILE *input, *output;

    input=fopen(INFILE, "r");
    output=fopen(OUTFILE, "w");

    read_input(input);
    sort();
    solve();
    write_output(output);

    fclose(input);
    fclose(output);
    return 0;
}
