#include<stdio.h>
#include<string.h>
const int maxn=100000;
bool is[maxn];
int prm[maxn];
int num;

int myprm[maxn][2];
int mynum;

int mybase[maxn];

int m;
int  sum;

void getprm(){
	memset(is,true,sizeof(is));
	is[1]=false;
	num=0;
	for(int i=2;i<maxn;i++){
		if(is[i]){
			prm[num++]=i;
			for(int j=i+i;j<maxn;j+=i){
				is[j]=false;
			}
		}
	}
}

void getmyprm(int n){
	mynum=0;
	for(int i=0;i<num;i++){
		if(n%prm[i]==0){
			myprm[mynum][0]=prm[i];
			myprm[mynum][1]=0;
			while(n%prm[i]==0)n/=prm[i],myprm[mynum][1]++;
			mynum++;
		}
		if(n==1)break;
	}

	if(n!=1){
		myprm[mynum][0]=n;
		myprm[mynum][1]=1;
		mynum++;
	}

}

void addsum(int s){
	while(s>0)sum+=(s%m)*(s%m),s/=m;
}


void dfs(int k,int n){
	if(k==mynum){
		addsum(n);
		return ;
	}
	int tmp=1;
	for(int i=0;i<=myprm[k][1];i++){
		dfs(k+1,n*tmp);
		tmp*=myprm[k][0];
	}
}

void myprint(__int64 s){

	int len=0;
	for(;s!=0;mybase[len]=s%m,s/=m,len++);
	while(len--){printf("%c",mybase[len]<10?mybase[len]+'0':mybase[len]-10+'A');}
	puts("");
}

int main(){
	getprm();
	int n;
	while(~scanf("%d%d",&n,&m)){
		getmyprm(n);
		sum=0;
		dfs(0,1);
		myprint(sum);
	}

	return 0;
}
