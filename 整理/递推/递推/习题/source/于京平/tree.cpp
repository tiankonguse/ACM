/*
f[0]=1
for i=1 to n do begin
  for j:=0 to n-1 f[i]+=f[j]*f[i-1-j]
end;
*/



#include<stdio.h>
int f[10000];
int main()
{
	freopen("tree.in","r+",stdin);
	freopen("tree.out","w+",stdout);
	int n,i,j;
	scanf("%d",&n);
	f[0]=1;
	f[1]=0;
	for(i=1;i<=n;i++)
	for(j=0;j<n;j++)
	f[i]+=f[j]*f[i-j-1];
	printf("%d",f[n]);
	return 0;
}
