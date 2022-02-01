#include"cmath"
#include"cstdlib"
#include"iostream"
const int max = 50005;
bool isprime[::max];
int pri[::max];
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
	pri_cnt=0;
    for(i=2;i< ::max;i++)
   {
    if(isprime[i])
    pri[pri_cnt++]=i;
   }
}
int main(){
    int N,cnt,e;
    setp();
    while(scanf("%d",&N)&&N){
       cnt=0;
       e=N/2;
       for(int i=0;pri[i]<=e;i++){
           if(isprime[N-pri[i]])cnt++;
       }
       printf("%d\n",cnt);
    }
    return 0;
}
