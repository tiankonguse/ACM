#include"cmath"
#include"cstdlib"
#include"iostream"
const int max = 1000005;
bool isprime[::max];
int pri_cnt;
void setp(){
  int i,j;
	memset(isprime,true,sizeof(isprime));
        int end=(int)sqrt(::max*1.0);	
	for(i = 3 ; i <= end ; i += 2 ){		
		for(j = 3 ; j <= ::max / i ; j += 2){		
			if(isprime[i]){			
				isprime[i * j] = false;	
			}	
		}	
	}	
	for(i = 4 ; i <= ::max ; i += 2 ){		
		isprime[i] = false;	
	}
	isprime[1] = isprime[0] = false;
}
int main(){
    setp();
    int a,d,n,p;
    while(scanf("%d%d%d",&a,&d,&n)){
       if(a==0 && d==0 && n==0)break;
       p=a-d;
       while(n>=1){
          p+=d;
          while(!isprime[p])p+=d;
          n--;
       }
       printf("%d\n",p);
    }
    return 0;
}
