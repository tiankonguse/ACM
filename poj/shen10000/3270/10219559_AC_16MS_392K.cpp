#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=100010;
int str0[N];
int str1[N];
int str2[N];
bool map[N];
int MIN;
int cmp(void const* a,void const* b){
	return  *((int const *)a) - *((int const *)b);
}

int find(int k,int*p,int head,int end){
	int mid=(head+end)/2;
	if(p[mid]==k)return mid;
	if(p[mid]<k)return find(k,p,mid+1,end);
	return find(k,p,head,mid-1);
}

void fun(int i,int min,int l){
	
}

int _find(int beg){
	int l=0;
	int now=beg;
	int min=now;
	int sum=str0[now];

	map[now]=false;
	now=str2[now];
	l++;

	for(;now^beg;){
		if(str0[min]>str0[now])min=now;
		sum+=str0[now];
		map[now]=false;
		now=str2[now];
		l++;
	}
	
	if(l==1)return 0;
	if(l==2)return sum;
		
	sum-=str0[min];
	int sum1=sum+(l-1)*str0[min];
	sum+=(l+1)*MIN+2*str0[min];
	return sum<sum1?sum:sum1;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&str0[i]);
			str1[i]=str0[i];
		}
		qsort(str1,n,sizeof(int),cmp);
		MIN=str1[0];
		for(int i=0;i<n;i++){
			str2[i]=find(str0[i],str1,0,n);
		}
		memset(map,true,sizeof(map));
		int ans=0;
		for(int i=0;i<n;i++){
			if(map[i]){
				ans+=_find(i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
