#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int N=600;
const int M=600;
bool is[N]; 
int prm[M];
int getprm(){
	int e = (int)(sqrt(0.0 + N) + 1),k=0;
	memset(is, 1, sizeof(is));
	prm[k++] = 2; is[0] = is[1] = 0;
	for (int i = 4; i < N; i += 2) is[i] = 0;
	
	for(int i=3;i<e;i+=2){
		if(is[i]){
			prm[k++]=i;
			for(int s=i+i,j=i*i;j<N;j+=s)is[j]=0;
		}
	}
	for ( int i=e; i < N; i += 2) if (is[i]) prm[k++] = i;
	return k; 
}
int main()
{
	getprm();
	int m,n,k;
	while(cin>>m>>n){
		k=0;
		for(int i=m;i<=n;i++){
			if(is[i]){
				if(k++)cout<<" ";
				cout<<i;
				if(k==7){k=0;cout<<endl;}
			}
		}
		if(k)cout<<endl;
	}
	return 0;
}
