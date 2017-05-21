#include"iostream"
using namespace std;
int yd[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int isleap(int a){
  if((a%4==0&&a%100!=0)|| a%400==0)return 1;
	else return 0;
}
int main(){
	int Y,M,D,sum=5;
	cin>>Y>>M>>D;
		sum=5;
	int r,dd;
	
	r=1+(Y-1)/4-(Y-1)/100+(Y-1)/400;
	dd=yd[M]+D;
	
	sum+=(Y+r)%7;

	if(isleap(Y)){
		if(M>=3)dd++;
	}
	sum+=dd;
	sum%=7;
	switch(sum){
		case 0:cout<<"sunday"<<endl;break;
		case 1:cout<<"monday"<<endl;break;
		case 2:cout<<"tuesday"<<endl;break;
		case 3:cout<<"wednesday"<<endl;break;
		case 4:cout<<"thursday"<<endl;break;
		case 5:cout<<"friday"<<endl;break;
		case 6:cout<<"saturday"<<endl;break;
	}
	
	
	return 0;
}
