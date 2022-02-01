#include"cmath"
#include"cstdlib"
#include"iostream"
using namespace std;
const int max = 1120;
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
int dp[1121][1121];
void init(){
    dp[0][0]=1;
    for(int i=0;i<pri_cnt;i++){
        for(int j=1120-pri[i];j>=0;j--){
             for(int k=1;k<=14;k++){
                    dp[pri[i]+j][k]+=dp[j][k-1];
             }
        }
    }
}
int main(){
    int n,k;
    setp();
    init();
    while(scanf("%d%d",&n,&k)&&n){
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
