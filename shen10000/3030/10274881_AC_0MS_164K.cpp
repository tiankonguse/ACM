#include<string>
#include<iostream>
using namespace std;
int a,b,c;
const char s[4][30]={"advertise","does not matter","do not advertise"};
int main()
{
int n,k;
scanf("%d",&n);
while(n--){
	scanf("%d%d%d",&a,&b,&c);
	a+=c;
	if(a<b)k=0;
	else if(a==b)k=1;
	else k=2;
	printf("%s\n",s[k]);
}
return 0;
}
