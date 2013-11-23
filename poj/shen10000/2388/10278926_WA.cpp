#include<string>
#include<iostream>
using namespace std;
void swap(int&a ,int&b){
	int t=a;
	a=b;
	b=t;
}
void ksort(int l, int h, int a[]){
	if (h < l + 2) return;
	int e = h, p = l;
	while (l < h) {
		while (++l < e && a[l] <= a[p]);
		while (--h > p && a[h] >= a[p]);
		if (l < h) swap(a[l], a[h]);
	}
	swap(a[h], a[p]);
	ksort(p, h, a); 
	ksort(l, e, a);
}
int main()
{
int n,s[10010];
while(scanf("%d",&n)!=EOF){
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	ksort(0,n-1,s);
	printf("%d\n",s[n>>1]); 
}
return 0;
}
