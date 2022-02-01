#include"iostream"
#include"cstdlib"
#include"algorithm"
#include"string"
#include"queue"
#include"stack"
#include"set"
#include"map"
using namespace std;
int num[9];
int mark[362880];
stack<char>st;
queue<int>q;
int factor[8] = {1, 2, 6, 24, 120, 720, 5040, 40320};   
bool hash[362880];   
int gethash(int n)   
{   
    int i, j;   
    int ret=0,cnt; 
    for(i=8;i>=0;i--){
       num[i]=n%10;
       n/=10;
    }  
    for(i=1; i < 9; ++i)   
    {   
        cnt = 0;   
        for(j = 0; j < i; ++j)   
            if(num[j] > num[i])   
                cnt++;   
        ret += cnt*factor[i-1];   
    }   
    return ret;   
}   
int change(int n,int d){
    int t,sum=0;
    for(int i=8;i>=0;i--){
       num[i]=n%10;
       n/=10;
       if(num[i]==0)t=i;
    }
    if(d==0){ //up
       if(t<3)return -1;
       num[t]=num[t-3];
       num[t-3]=0;
    }
    else if(d==1){ //down
       if(t>5)return -1;
       num[t]=num[t+3];
       num[t+3]=0;
    }
    else if(d==2){ //left
       if(t%3==0)return -1;
       num[t]=num[t-1];
       num[t-1]=0;
    }
    else if(d==3){ //right
       if(t%3==2)return -1;
       num[t]=num[t+1];
       num[t+1]=0;
    }
    for(int i=0;i<=8;i++){
          sum=sum*10+num[i];
    }
    return sum;
}
char dir(int n){
   switch(n){
      case 0:return 'u';
      case 1:return 'd';
      case 2:return 'l';
      case 3:return 'r';
   }
}
int cc(int n){
   switch(n){
      case 0:return 1;
      case 1:return 0;
      case 2:return 3;
      case 3:return 2;
   }
}
void bfs(int n){
    int t,ts,gt,dd;
    q.push(n);
    mark[gethash(n)]=5;
    while(!q.empty()){
       t=q.front();
       q.pop();
       for(int i=0;i<4;i++){
          ts=change(t,i);       
          gt=gethash(ts);
          if(ts==-1)continue;
          if(ts==123456780){
             st.push(dir(i));
             int rr=change(ts,cc(i));
             while(1){
                dd=mark[gethash(rr)];
                st.push(dir(dd));
                rr=change(rr,cc(dd));
                if(rr==n)break;
             }
             while(!st.empty()){
                printf("%c",st.top());
                st.pop();
             }
             printf("\n");
             return;
          }
          if(mark[gt]==-1){
             mark[gt]=i;
             q.push(ts);
          }
       }
    }
    printf("unsolvable\n");
}
int main(){
    char ch;
    int n=0;
    memset(mark,-1,sizeof(mark));
    scanf(" %c",&ch);
        n=0;
        if(ch!='x')n+=ch-'0';
        for(int i=0;i<8;i++){
           n*=10;
           scanf(" %c",&ch);
           if(ch!='x')n+=ch-'0';
        }
        bfs(n);
        //system("pause");    
    return 0;
}
