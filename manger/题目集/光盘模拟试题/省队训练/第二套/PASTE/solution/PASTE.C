
// HIO 2001
// Zadatak PASTA
// Autor rjesenja Milan Mesic
// Nesluzbeno rjesenje

#include <stdio.h>

#define ULAZ "PASTE.in"
#define IZLAZ "PASTE.out"

#define MAXK 1000

struct cutovi
{
	long a,b,c;
} cut[MAXK];

long n,k;

int main()
{
	long dije[11];
	long i,j,linija,kud,odkud,k;
	FILE *f;

	f=fopen(ULAZ,"r");
	fscanf(f,"%ld%ld",&n,&k);
	for (i=0;i<k;i++) fscanf(f,"%ld%ld%ld",&cut[i].a,&cut[i].b,&cut[i].c);
	fclose(f);
	for (i=1;i<11;i++) dije[i]=i;
	for (i=k-1;i>=0;i--)
	{
		odkud=cut[i].a;
		kud=cut[i].c+1;
		linija=cut[i].b-cut[i].a+1;
		for (j=1;j<11;j++)
		{
			if (dije[j]>=kud&&dije[j]<kud+linija) dije[j]=odkud+dije[j]-kud;
			else if (dije[j]>=kud+linija&&dije[j]<odkud+linija) dije[j]=dije[j]-linija;
			else if (dije[j]<kud&&dije[j]>=odkud) dije[j]=dije[j]+linija;
		}
	}
	f=fopen(IZLAZ,"w");
	for (j=1;j<11;j++)	fprintf(f,"%ld\n",dije[j]);
	fclose(f);
	return 0;
}
