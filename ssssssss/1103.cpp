#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
const int N=1000000;
const int M=300000;
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
	int a,b,i;
//	cout<<prm[0]<<" "<<prm[1]<<endl;
		a=6;
		int k=0;
	while(a<=100){
		for(i=1;;i++){
			b=a-prm[i];
			if(is[b])break;
		}
		if(k++)printf(",");
		printf("%d=%d+%d",a,prm[i],b);
		if(k==5){k=0;puts("");}
		a+=2;
	}
	cin>>a;
	return 0;
}
