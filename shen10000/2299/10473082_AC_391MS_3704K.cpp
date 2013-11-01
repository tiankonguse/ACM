#include<iostream>
#include<queue>
#include<string>
using namespace std;
long long cnt=0;
const int N=5000009;
int a[N],c[N];
void MergeSort(int l, int r){
	int mid, i, j, tmp;
	if( r > l+1 ){
		mid = (l+r)/2;
		MergeSort(l, mid);
		MergeSort(mid, r);
		tmp = l;
		for( i=l, j=mid; i < mid && j < r; ){
			if( a[i] > a[j] ){
				c[tmp++] = a[j++];
				cnt += mid-i; 
		}
		else c[tmp++] = a[i++];
		
		}
		if( j < r ) for( ; j < r; ++j ) c[tmp++] = a[j];
		else for( ; i < mid; ++i ) c[tmp++] = a[i];
		
		for ( i=l; i < r; ++i ) a[i] = c[i];
	}
}
int main()
{
int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		cnt=0;
		MergeSort(0,n);
		printf("%lld\n",cnt);
	}
return 0;
}