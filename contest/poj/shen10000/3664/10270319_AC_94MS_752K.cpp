#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=50100;
struct T{
	int x,y,num;
}str0[N];
bool cmp(const T&A,const T&B){
     if(A.x>B.x||A.x==B.x&&A.y>B.y)return true;
     return false;
}

int main()
{
int n,t;
while(~scanf("%d%d",&n,&t)){
	for(int i=0;i<n;i++){
		scanf("%d%d",&(str0[i].x),&(str0[i].y));
		str0[i].num=i+1;
	}
	sort(str0,str0+n,cmp);
	int max=0;
	for(int i=0;i<t;i++){
		if(str0[i].y>str0[max].y)max=i;
	}
	printf("%d\n",str0[max].num);
}
return 0;
}
