#include<string>
#include<iostream>
using namespace std;
int n,a,b,c;
bool ok(){
	if(a<=b && b<=c)return true;
	if(a>=b && b>=c)return true;
	return false;
}
int main()
{

scanf("%d",&n);
printf("Gnomes:\n");
while(n--){
	scanf("%d%d%d",&a,&b,&c);
	if(ok()){printf("Ordered\n");}
	else{printf("Unordered\n");}
}
return 0;
}
