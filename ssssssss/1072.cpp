#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	double n1,n2,sum1,sum2;
	while(scanf("%lf%lf",&n1,&n2)!=EOF){
		sum1=(n1+1)*n1/2;
		sum2=(n2+1)*n2/2;
		printf("%.0f\n",sum2-sum1+n1);
	}
	return 0;
}
