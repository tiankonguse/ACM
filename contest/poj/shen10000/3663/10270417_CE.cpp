#include<string>
#include<iostream>
using namespace std;
int str[20010];
int n,len,now;
bool cmp(const int&A,const int&B){
	return A<B?true:false;
}

int find(int l,int r){
	if(l==r)return l;
	if(l+1==r)return str[r]+str[now]<=len?r:l;
	int mid=(l+r)>>1;
	if(str[mid]+str[now]<=len)return find(mid,r);
	else return find(l,mid-1);
}

int main()
{

while(~scanf("%d%d",&n,&len)){
	for(int i=0;i<n;){
		scanf("%d",&str[i]);
		if(str[i]>=len)n--;
		else i++;
	}
	sort(str,str+n,cmp);

	int sum=0;
	for(now=0;now<n-1;now++){
		if(str[now]+str[now+1]>len)break;
		sum+=find(now+1,n-1)-now;
	}
	printf("%d\n",sum);
}
return 0;
}
