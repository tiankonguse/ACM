
// DMIH 2001 - Drugi dan natjecanja
// Srednjoskolska skupina - II. podskupina
// Zadatak LISTA
// Autor rjesenja Zvonimir Bujanovic
// Nesluzbeno rjesenje

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN     100
#define MAXLEN   100
#define INFILE   "LIST.in"
#define OUTFILE  "LIST.out"
#define ISTO     "SAME"
#define GORE     "UP"
#define DOLJE    "DOWN"

int n, kuda[MAXN], link[MAXN];
char *s[MAXN];

void load_data ( void )
{
 int i;
 char tmp[10];
 FILE *f=fopen (INFILE, "rt");

 fscanf (f, "%d\n", &n);
 for (i=0; i<n; i++)
     {
      s[i]=(char *) malloc ((MAXLEN+1)*sizeof(char));
      fscanf (f, "%[^\n]\n", s[i]);
      fscanf (f, "%[^\n]\n", tmp);

      if (!strcmp (tmp, GORE)) kuda[i]=1;
      if (!strcmp (tmp, DOLJE)) kuda[i]=-1;
     }
}

void solve ( void )
{
 int i, j;

 for (i=0; i<n; i++) link[i]=i;
 i=j=0;

 while (j<n)
   {
    while (i<n && kuda[i]==0) i++;
    while (j<n && kuda[j]!=-1) j++;

    if (j<n) link[i]=j;
    i++; j++;
   }

 j=n-1; i=n-1;
 while (j>=0)
   {
    while (i>=0 && kuda[i]==0) i--;
    while (j>=0 && kuda[j]!=1) j--;

    if (j>=0) link[i]=j;
    i--; j--;
   }
}

void write_output ( void )
{
 FILE *f=fopen (OUTFILE, "wt");
 int i;

 for (i=0; i<n; i++) fprintf (f, "%s\n", s[link[i]]);
 fclose (f);
}


int main ( void )
{
 load_data();
 solve();
 write_output();
 return 0;
}
