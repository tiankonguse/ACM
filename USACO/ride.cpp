/*
ID: shen1002
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
using namespace std;
const int MOD=47;
int main() {
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    char str1[111],str2[111];
    int sum1,sum2,i;
    while(~scanf("%s%s",str1,str2)){
		sum1=sum2=1;
		for(i=0;str1[i];i++)sum1=(sum1*(str1[i]-'A'+1))%MOD;
		for(i=0;str2[i];i++)sum2=(sum2*(str2[i]-'A'+1))%MOD;
		printf("%s\n",sum1==sum2?"GO":"STAY");
	}
    return 0;
}
