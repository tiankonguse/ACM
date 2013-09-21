#include <cstdio>


struct node
{
	long y;
	long z;
	node* next;
};
node* g[3002][3002];


long n;long m;long k;
long que[1100000];
long que2[1100000];
long fa[3002];
bool map[3002][3002];


void insert(long x,long z,long y)
{
	node* tmp = new node;
	tmp -> z = z;
	tmp -> y = y;
	tmp -> next = g[x][y];
	g[x][y] = tmp;
}


void output(long p)
{
	if (fa[p]==0)
	{
		printf("%ld ",que[p]);
		return;
	}
	output(fa[p]);
	printf("%ld ",que[p]);
}


bool check(long a,long b)
{
	node* ths = g[fa[a]][b];

	while (ths)
	{
		if (ths->z==a) return false;
		ths = ths->next;
	}
	return true;
}


void bfs()
{
	long l= 0;long r= 0;
	r++;
	que[r] = 1;
	while (l<r)
	{
		long now = que[++l];
		for (long i=1;i<n+1;i++)
		{
			if (now == i)continue;
			if (map[now][i]&&check(l,i))
			{
				map[now][i] = false;
				r++;
				fa[r] = l;
				que[r] = i;
				que2[r] = que2[l]+1;
				if (i==n)
				{
					printf("%ld\n",que2[r]);
					output(r);
					return;
				}
			}
		}
	}
}


int main()
{
//	freopen("path.in","r",stdin);
//	freopen("path.out","w",stdout);
	scanf("%ld%ld%ld",&n,&m,&k);
	for (long i=1;i<m+1;i++)
	{
		long a;long b;
		scanf("%ld%ld",&a,&b);
		map[a][b] = true;
		map[b][a] = true;
	}
	for (long i=1;i<k+1;i++)
	{
		long a;long b;long c;
		scanf("%ld%ld%ld",&a,&b,&c);
		insert(a,b,c);
	}
	bfs();
	return 0;
}
