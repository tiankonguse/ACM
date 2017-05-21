#include"cmath"
#include"cstdlib"
#include"queue"
#include"iostream"
using namespace std;
const int max = 10001;
bool isprime[::max];
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
struct node{
    int num,t;
    node(int num,int t):num(num),t(t){}
};
queue<node>q;
bool hash[10000];
int bfs(int a,int b){
    node tmp(0,0);
    int d1,d2,d3,d4,d,cnt=0;
    if(a==b)return 0;
    memset(hash,false,sizeof(hash));
    while(!q.empty())q.pop();
    hash[a]=true;
    q.push(node(a,0));
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        d1=tmp.num;d2=tmp.num%1000;d3=tmp.num%100;d4=tmp.num%10;
        for(int i=0;i<10;i++){
            if(i!=0){
                d=d2+i*1000;
                if(isprime[d] && !hash[d]){
                   if(d==b)return tmp.t+1;
                   hash[d]=true;
                   q.push(node(d,tmp.t+1));
                }
            }
            d=d1-d2+d3+i*100;
            if(isprime[d] && !hash[d]){
                 if(d==b)return tmp.t+1;
                 hash[d]=true;
                 q.push(node(d,tmp.t+1));
            }
            d=d1-d3+d4+i*10;
            if(isprime[d] && !hash[d]){
                if(d==b)return tmp.t+1;
                hash[d]=true;
                q.push(node(d,tmp.t+1));
            }
            d=d1-d4+i;
            if(isprime[d] && !hash[d]){
                if(d==b)return tmp.t+1;
                hash[d]=true;
                q.push(node(d,tmp.t+1));
            }
        }
    }
    return -1;
}
int main(){
    setp();
    int T,a,b,d;
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&a,&b);
         d=bfs(a,b);
         if(d==-1)printf("Impossible\n");
         else printf("%d\n",d);
    }
    return 0;
}
