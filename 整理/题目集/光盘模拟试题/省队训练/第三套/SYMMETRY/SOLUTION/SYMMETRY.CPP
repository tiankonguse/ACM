#include <fstream.h>
#include <stdlib.h>
const int max = 30000;
struct place
{
	int x,y;
}guard[max];
int cmp(const void * a, const void * b)
{
	place * p = (place*)a, * q = (place*)b;
	if ((p->x < q->x) || (p->x == q->x && p->y < q->y)) return -1;
	else return 1;
}
void main()
{
	int n, i;
	place center;
	ifstream cin("symmetry.in");
	ofstream cout("symmetry.out");
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(1);
	cin>>n;
	while (n)
	{
		for (i = 0; i < n; i++)
			cin>>guard[i].x>>guard[i].y;
		qsort(guard, n, sizeof(place), cmp);
		center.x = (guard[0].x + guard[n-1].x);
		center.y = (guard[0].y + guard[n-1].y);
		for (i=0; i * 2 < n; i++)
		{
			if (guard[i].x + guard[n-1-i].x != center.x  ||  guard[i].y + guard[n-1-i].y != center.y)
			{
				break;
			}
		}
		if (i * 2 < n) cout<<"This is a dangerous situation!"<<endl;
		else cout<<"V.I.P. should stay at ("<<(double)center.x / 2<<','<<(double)center.y / 2<<")."<<endl;
		cin>>n;
	}
}