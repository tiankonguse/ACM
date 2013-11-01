#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int N=2100;
bool map[N];
//tmp1 <
//tmp2 >
//ntmp1 number of tmp1
int str1[N],str2[N],tmp1[N],tmp2[N],tmp[N];
char str0[N];
int ntrue,n;

int find(){
	if(tmp1[0]==0 && tmp2[0]==1)return tmp2[1];
	if(tmp1[0]==1 && tmp2[0]==0)return tmp1[1];
	if(ntrue+1==n){
		for(int i=1;;i++)if(map[i])return i;
	}
	return 0;
}

bool find(int a,int *p){
	int num=p[0];
	for(int i=1;i<=num;i++){
		if(p[i]==a)return true;
	}
	return false;
}

void fixtmp(int* p){
	int num=p[0],i=1,j=1;
	for(;j<=num;){
		if(!map[p[j]])j++;
		else p[i++]=p[j++];
	}
	p[0]=i-1;
}

void add(int*p1,int*p2,int num){
	for(int i=0;i<num;i++){	
		if(!map[p1[i]])continue;
		if(find(p1[i],tmp1))continue;
		if(find(p1[i],tmp2))map[p1[i]]=false,ntrue++;
		else {
			tmp1[0]++;
			tmp1[tmp1[0]]=p1[i];	
		}
	}
	fixtmp(tmp2);
	for(int i=0;i<num;i++){	
		if(!map[p2[i]])continue;
		if(find(p2[i],tmp2))continue;
		if(find(p2[i],tmp1))map[p2[i]]=false,ntrue++;
		else {
			tmp2[0]++;
			tmp2[tmp2[0]]=p2[i];	
		}
	}
	fixtmp(tmp1);
}

int fun(int num){
	char c=str0[0];
	if(c=='='){
		for(int i=0;i<num;i++){
			if(map[str1[i]])map[str1[i]]=false,ntrue++;
			if(map[str2[i]])map[str2[i]]=false,ntrue++;
		}
		if(ntrue+1==n)return find();
		else {
			fixtmp(tmp1);
			fixtmp(tmp2);
		}
	}
	if(c=='>')
		add(str2,str1,num);
	else
		add(str1,str2,num);
	
	return find();
}


int main()
{
	int m,num;
	while(~scanf("%d%d",&n,&m)){
		int ans=0;
		tmp1[0]=tmp2[0]=ntrue=0;
		memset(map,true,(n+1)*sizeof(bool));
		while(m--){
			scanf("%d",&num);
			for(int i=0;i<num;i++){
				scanf("%d",&str1[i]);
			}
			for(int i=0;i<num;i++){
				scanf("%d",&str2[i]);
			}
			scanf("%s",str0);
			if(ans){
				while(m--){
					gets(str0);
					gets(str0);
				}
				break;
			}
			ans=fun(num);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
