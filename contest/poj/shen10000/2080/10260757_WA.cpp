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
int isrui(int n){
	if(n%4)return 0;
	if(n%100==0 && n%400 )return 0;
	return 1;	
}
int str[14]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int str1[15]={0,31,60,90+1,120+1,151+1,181+1,212+1,243+1,273+1,304+1,334+1,365+1};
char str0[8][10]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};
int main()
{
int n;
int year=2000,month=1,day=1,date=6,nowyear=365,tmp;

while(scanf("%d",&n),n+1){
	year=2000,month=1,day=1,date=6,nowyear=365;
	date=(6+n)%7;
	for(;;){
		nowyear =365+isrui(year);
		if(n>=nowyear){
			n-=nowyear;
			year++;
			continue;
		}
		else{
			if(n==0){
				
			}else if(nowyear==365){
				for(tmp=0;n>=str[tmp];tmp++);
				month+=tmp;
				day+=n-str[tmp];
			}else{
				for(tmp=0;n>=str1[tmp];tmp++);
				tmp--;

				month+=tmp;

				day+=n-str1[tmp];
			}
			break;
		}
	}
	printf("%d-%0.2d-%0.2d %s\n",year,month,day,str0[date]);
}
return 0;
}
