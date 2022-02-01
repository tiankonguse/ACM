#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
bool myexp(double x){
	return x<0.000001 && x>-0.000001;
}
const double str[3][3]={{4.5,150,200},{6.0,300,500},{5.0,200,300}};
const char str1[4][20]={"Wide Receiver","Lineman","Quarterback","No positions"};
int main()
{
double v,w,s;
while(scanf("%lf%lf%lf",&v,&w,&s)){
	if(myexp(v) && myexp(w)&& myexp(s))break;
	bool yes=false;
	for(int i=0;i<3;i++){
		if(str[i][0]>=v && str[i][1]<=w && str[i][2]<=s){
			if(yes)printf(" ");
			printf("%s",str1[i]);
			yes=true;
		}
	}
	if(!yes)printf("%s",str1[3]);
	printf("\n");
}
return 0;
}
