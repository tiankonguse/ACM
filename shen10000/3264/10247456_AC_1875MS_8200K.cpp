#include "stdio.h"
#include "string.h"
#include "math.h"

#define L 50005
int N,Q;
int A[L];
int M[L][20];
int S[L][20];
#define max( x, y ) ( (x) > (y) ? (x) : (y) )
#define min( x, y ) ( (x) < (y) ? (x) : (y) )

void RMQ()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		M[i][0]=A[i];
		S[i][0]=A[i];
	}
	for(j=1;(1<<j)<=N;j++)
	{
		for(i=1;i+(1<<j)-1<=N;i++)
		{
			M[i][j]=max(M[i][j-1],M[i+(1<<(j-1))][j-1]);
			S[i][j]=min(S[i][j-1],S[i+(1<<(j-1))][j-1]);
		}
	}
}

int main()
{
	int i,k;
	int a,b;
	memset(M,0,sizeof(M));
	memset(S,0,sizeof(S));
	scanf("%d %d",&N,&Q);
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);
	RMQ();
	while(Q--)
	{
		scanf("%d %d",&a,&b);
		k=(int)(log((double)(b-a+1))/log(2.0));
		printf("%d\n",max(M[a][k],M[b-(1<<k)+1][k])-min(S[a][k],S[b-(1<<k)+1][k]));
	}
	return 0;
}