#include"cmath"
#include"cstdlib"
#include"iostream"
using namespace std;
const int max = 20005;
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
bool num[20001];
int dat[5001];
int main(){
    int N,a,p;
    bool flag=false;
    setp();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%d",&dat[i]);
       num[dat[i]]=true;
    }
    for(int i=pri_cnt-1;i>=0;i--){
        for(int j=1;j*pri[i]<=20000;j++){
            if(num[j*pri[i]]){
                p=pri[i];
                flag=true;
                break;
            }
        }
        if(flag)break;
    }
    for(int i=0;i<N;i++){
        if(dat[i]%p==0){
            printf("%d\n",dat[i]);
            break;
        }
    }
   // system("pause");
    return 0;
}
