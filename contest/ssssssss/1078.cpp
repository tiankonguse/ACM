#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
bool ok(double a){
	return (a<0.000001 && a>-0.000001);
}
int main(){
	double a,b,c,d,x1,x2;
	while(cin>>a>>b>>c){
		if(ok(a)){
			if(ok(b)){
				if(ok(c)){
					printf("Any number.\n");continue;
				}else{
					printf("Error.\n");
				}
			}else{
				printf("Only root:x=%.2f\n",-c/b);
			}
		}else{
			if(a<0){a=-a;b=-b;c=-c;}
			d=b*b-4*a*c;
			a=a+a;
			if(d<0){
				d=sqrt(-d);
				if(ok(b)){
					printf("Two roots:x1=%.2fi,x2=%.2fi\n",d/a,-d/a);
				}else{
					printf("Two roots:x1=%.2f%+.2fi,x2=%.2f%+.2fi\n",-b/a,d/a,-b/a,-d/a);
				}
			}else{
				d=sqrt(d);
				x1=(-b+d)/a;if(ok(x1))x1=0;
				x2=-(b+d)/a;if(ok(x2))x2=0;
				printf("Two roots:x1=%.2f,x2=%.2f\n",x1,x2);
		
			}
		}
	}

	return 0;
}
