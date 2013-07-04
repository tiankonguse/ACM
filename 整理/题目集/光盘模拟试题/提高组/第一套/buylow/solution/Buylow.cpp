#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<assert.h>

FILE *inp,*outp;
struct ttp{int Len;__int64 Num;};
char vis[32800];
long n,i,j,k,a[5001];
ttp g[5001];
main(){
	inp=fopen("Buylow.in","r");assert(inp);
    outp=fopen("Buylow.out","w");assert(outp);
	fscanf(inp,"%ld",&n);
	for (i=1;i<=n;i++) fscanf(inp,"%ld",&a[i]);
	a[0]=32800;
	for (i=n;i>=0;i--){
	  k=i;g[i].Len=1;g[i].Num=1;
	  for (j=i+1;j<=n;j++)
        if (a[j]<a[i]&&g[j].Len>=g[k].Len) k=j;
	  if (k==i) continue;
	  memset(vis,0,sizeof(vis));
      g[i].Len=g[k].Len+1;g[i].Num=0; 
	  for (j=i+1;j<=n;j++)
		if (a[j]<a[i]&&g[j].Len==g[k].Len&&vis[a[j]]==0){
			g[i].Num+=g[j].Num;vis[a[j]]=1;
		}
	}
	fprintf(outp,"%d %0.0lf\n",g[0].Len-1,double(g[0].Num));
	fclose(outp);
}
