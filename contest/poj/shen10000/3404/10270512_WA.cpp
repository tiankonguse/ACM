#include<string>
#include<iostream>
using namespace std;

int main()
{
int n,sum,min,tmp;
while(~scanf("%d",&n)){
	scanf("%d",&min);
	sum=min;
	for(int i=1;i<n;i++){
		scanf("%d",&tmp);
		sum+=tmp;
		if(min>tmp)min=tmp;
	}
	if(n>=2)sum+=(n-3)*min;
	printf("%d\n",sum);
	
}
return 0;
}
