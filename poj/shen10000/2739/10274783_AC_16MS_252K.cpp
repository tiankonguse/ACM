#include<iostream>
#include<math.h>
using namespace std;
int a[1300];
bool isprime(int n){
	int i;double j;
	j=(double)n;
	for(i=2;i<=sqrt(j);i++){
		if(n%i==0) return false;
	}
	if(i>sqrt(j))return true;
}
int main(){
	int i,j,k,num;
	a[0]=2;
	for(i=1,j=3;j<10000;j++){
		if(isprime(j)){a[i]=j;i++;}
		
	}

	while(cin>>num&&num!=0){
		int t=num;int count=0;

		for(i=0;a[i]<=num;i++){
			j=i;
			while(num>=a[j]&&t>1){
				t=t-a[j];
				j++;
				if(t==0){count++;break;}
				
			}
			t=num;
			
		}
		cout<<count<<endl;
		count=0;
		
	}
	return 0;
	
}
