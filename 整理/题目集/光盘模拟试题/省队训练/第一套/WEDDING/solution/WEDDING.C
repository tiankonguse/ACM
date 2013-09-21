
// Izborne pripreme 2001 - Prvi izborni ispit
// Zadatak SVADBA
// Autor rjesenja Zvonimir Bujanovic
// Nesluzbeno rjesenje

#include<stdio.h>
#include<stdlib.h>

#define INFILE     "WEDDING.in"
#define OUTFILE    "WEDDING.out"
#define MAXN       10000L
#define MAXK       1000L
#define MAX_HGH    2200L
#define MIN_HGH    0L

typedef struct hgh { long ind; struct hgh *next; } hgh;

long n, k, visina[MAXN], diff=0, stavi_max, stavi_min;
long min_mirko=MAX_HGH, max_mirko=MIN_HGH;
long min_slavko=MAX_HGH, max_slavko=MIN_HGH;
hgh *index[MAX_HGH-MIN_HGH+1];

long pop (long kud)
{
 long i;
 hgh *tmp;

 if (index[kud]==NULL) return 0;

 tmp=index[kud]->next;
 i=index[kud]->ind;
 free (index[kud]);
 index[kud]=tmp;

 return i;
}

void push (long kud, long sto)
{
 hgh *tmp;

 if (index[kud]==NULL)
    {
     index[kud]=(hgh *) malloc (sizeof(hgh));
     index[kud]->ind=sto; index[kud]->next=NULL;
    }
    else
    {
     tmp=(hgh *) malloc(sizeof(hgh));
     tmp->ind=sto;
     tmp->next=index[kud];
     index[kud]=tmp;
    }
}

long sredi_najvece (long kmin, long kmax, long min, long max, long m, long M )
{
 long bst=1000000000L;

 if (M<max) M=max;
 if (m>min) m=min;

 if (bst>2*(min-m)+2*(M-max))
    { bst=2*(min-m)+2*(M-max); stavi_min=kmin; stavi_max=kmax; }

 if (bst>(visina[0]-m)+2*(M-max))
    { bst=(visina[0]-m)+2*(M-max); stavi_min=-1; stavi_max=kmax; }

 if (bst>(visina[k-1]-m)+2*(M-max))
    { bst=(visina[k-1]-m)+2*(M-max); stavi_min=k; stavi_max=kmax; }

 if (bst>2*(min-m)+(M-visina[0]))
    { bst=2*(min-m)+(M-visina[0]); stavi_min=kmin; stavi_max=-1; }

 if (bst>2*(min-m)+(M-visina[k-1]))
    { bst=2*(min-m)+(M-visina[k-1]); stavi_min=kmin; stavi_max=k; }

 if (bst>(M-m)+(M-visina[0]))
    { bst=(M-m)+(M-visina[0]); stavi_min=-2; stavi_max=-1; }

 if (bst>(M-m)+(visina[0]-m))
    { bst=(M-m)+(visina[0]-m); stavi_min=-1; stavi_max=-2; }

 if (bst>(M-visina[k-1])+(M-m))
    { bst=(M-visina[k-1])+(M-m); stavi_min=k+1; stavi_max=k; }

 if (bst>(visina[k-1]-m)+(M-m))
    { bst=(visina[k-1]-m)+(M-m); stavi_min=k; stavi_max=k+1; }

 if (bst>(M-visina[0])+(visina[k-1]-m))
    { bst=(M-visina[0])+(visina[k-1]-m); stavi_min=k; stavi_max=-1; }

 if (bst>(visina[0]-m)+(M-visina[k-1]))
    { bst=(visina[0]-m)+(M-visina[k-1]); stavi_min=-1; stavi_max=k; }

 return bst;
}

void load_data_and_find_diff ( void )
{
 long i, mini, maxi;

 FILE *f=fopen (INFILE, "rt");

 fscanf (f, "%ld %ld", &n, &k);
 for (i=0; i<n; i++)
     {
      fscanf (f, "%ld", visina+i);
      if (i<k)
         {
          if (visina[i]<min_slavko) { min_slavko=visina[i]; mini=i; }
          if (visina[i]>max_slavko) { max_slavko=visina[i]; maxi=i; }
          if (i) diff+=abs(visina[i]-visina[i-1]);
         }
         else
         {
          if (visina[i]<min_mirko) min_mirko=visina[i];
          if (visina[i]>max_mirko) max_mirko=visina[i];
          push (visina[i]-MIN_HGH, i+1);
         }
     }

 diff+=sredi_najvece(mini, maxi, min_slavko, max_slavko, min_mirko, max_mirko);
}

void solve ( void )
{
 long i, j, l;
 FILE *f=fopen (OUTFILE, "wt");

 fprintf (f, "%ld\n", diff);

 if (stavi_min==-1)
    {
     if (stavi_max==-2)
         for (i=max_mirko; i>=min_mirko; i--)
              while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);

     for (i=min_mirko; i<=visina[0]; i++)
         while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);
    }

 if (stavi_max==-1)
    {
     if (stavi_min==-2)
        for (i=min_mirko; i<=max_mirko; i++)
            while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);

     for (i=max_mirko; i>=visina[0]; i--)
         while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);
    }

 fprintf (f, "1\n");

 for (i=1; i<k; i++)
     {
      for (j=visina[i-1]; j>=visina[i]; j--)
           while (l=pop (j-MIN_HGH)) fprintf (f, "%ld\n", l);

      for (j=visina[i-1]; j<=visina[i]; j++)
           while (l=pop (j-MIN_HGH)) fprintf (f, "%ld\n", l);

      if (stavi_min==i)
         for (j=min_mirko; j<=visina[i]; j++)
             while (l=pop (j-MIN_HGH)) fprintf (f, "%ld\n", l);

      fprintf (f, "%ld\n", i+1);

      if (stavi_max==i)
         for (j=max_mirko; j>=visina[i]; j--)
             while (l=pop (j-MIN_HGH)) fprintf (f, "%ld\n", l);
     }

  if (stavi_min==k)
     {
      for (i=visina[k-1]; i>=min_mirko; i--)
          while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);

      if (stavi_max==k+1)
          for (i=min_mirko; i<=max_mirko; i++)
               while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);
     }

  if (stavi_max==k)
     {
      for (i=visina[k-1]; i<=max_mirko; i++)
          while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);

      if (stavi_min==k+1)
          for (i=max_mirko; i<=min_mirko; i--)
               while (j=pop (i-MIN_HGH)) fprintf (f, "%ld\n", j);
     }

 fclose (f);
}

int main ( void )
{
 load_data_and_find_diff();
 solve();

 return 0;
}
