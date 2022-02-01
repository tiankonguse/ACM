#include<string>
#include<iostream>
using namespace std;
const int N=50100;
struct T{
	__int64 x,y,num;
}str0[N],tmp;


int main()
{
int n,t;
while(~scanf("%d%d",&n,&t)){
	for(int i=0;i<n;i++){
		scanf("%I64d%I64d",&(str0[i].x),&(str0[i].y));
		str0[i].num=i+1;
	}
	for(int i=0;i<t;i++){
		for(int j=n-1;j>i;j--){
			if(str0[j].x>str0[j-1].x){
				tmp=str0[j];
				str0[j]=str0[j-1];
				str0[j-1]=tmp;
			}
		}
	}
	int max=0;
	for(int i=0;i<t;i++){
		if(str0[i].num>str0[max].num)max=i;
	}
	printf("%I64d\n",str0[max].num);
}
return 0;
}
