#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef __int64 LL;
const int N=50010;
const int INF=99999999;
LL prm[N];
int numprm;
bool isprm[N*20];
LL str[N*20],n;
LL l,r;
LL minlen,maxlen,minl,minr,maxl,maxr;
int getprm() {
	int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
	memset(isprm, 1, sizeof(isprm));

	prm[k++] = 2;
	isprm[0] = isprm[1] = 0;
	for (i = 4; i < N; i += 2) isprm[i] = 0;

	for(i=3; i<e; i+=2) {
		if(isprm[i]) {
			prm[k++]=i;
			for(int s=i+i,j=i*i; j<N; j+=s)isprm[j]=0;
		}
	}
	for (; i < N; i += 2)
		if (isprm[i])prm[k++] = i;
	return k;
}

int make_prm() {
	LL ll=r-l+1;
	int i,tmp;
	LL j;
	memset(isprm,true,sizeof(bool)*(ll+1));
	int e=(int)(sqrt(0.0 + r) + 1);
	for(i=0; prm[i]<=e; i++) {

		j=(l+prm[i]-1)/prm[i]*prm[i];
		if(j==prm[i])j+=prm[i];

		for(; j<=r; j+=prm[i]) {
			tmp=j-l;
			isprm[tmp]=false;
		}
	}
	int k=0;
	for(i=0; i<ll; i++) {
		if(isprm[i]) {
			str[k++]=i+l;
		}
	}
	return k;
}

void solve() {
	n=make_prm();
	if(n<2) {
		printf("There are no adjacent primes.\n");
	} else {
		minlen=maxlen=str[1]-str[0];
		minl=maxl=0;
		maxr=minr=1;
		LL tmp;
		for(int i=2; i<n; i++) {
			tmp=str[i]-str[i-1];
			if(tmp<minlen) {
				minlen=tmp;
				minl=i-1;
				minr=i;
			}
			if(tmp>maxlen) {
				maxlen=tmp;
				maxl=i-1;
				maxr=i;
			}
		}
		printf("%I64d,%I64d are closest, %I64d,%I64d are most distant.\n",str[minl],str[minr],str[maxl],str[maxr]);
	}
}

int main() {
	numprm=getprm();
	while(~scanf("%I64d%I64d",&l,&r)) {
		if(l==1)l=2;
		solve();
	}

	return 0;
}
