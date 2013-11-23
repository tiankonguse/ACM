#include<stdio.h>
#include<string.h>
const int N=250001;
const int M=1000002;

int str[N];
int prim[N];
bool map[M];
	
int myprim(){

	int j,i,k,num,val;
	memset(map,true,sizeof(map));
	for(i=5,j=0;i<M;i+=4){
		if(map[i]){
			prim[j++]=i;
			if(i>1000)continue;
			num=i*4;
			for(k=i*i;k<M;k+=num)map[k]=false;
		}
	}	
	num=j;
	memset(map,false,sizeof(map));

	for(j=0;j<num;j++)
	for(i=0;i<num;i++)
	{
		val=prim[i]*prim[j];
		
		if(val>M)break;
		map[val]=true;		
	}
	for(i=25,j=0;i<M;i+=4)if(map[i]){str[j++]=i;}

	return j;
}
int main(){
	myprim();
	int n,i;
	while(scanf("%d",&n),n){
		for(i=0;str[i]<=n;i++);
		printf("%d %d\n",n,i);
	}
	return 0;
}
