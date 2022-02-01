#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXL 50
#define MAXN 50005
using namespace std;
struct bigInt{
    int len;
    int num[MAXL];
     bigInt operator +(const bigInt&);
    void init(){
        memset(num,0,sizeof(num));
    }
}t;
void print(bigInt a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.num[i]);
    }
    printf("\n");
}
bigInt bigInt:: operator +(const bigInt &b){
     t.num[t.len=max(len,b.len)]=0;
     for (int i=0;i<t.len;i++) t.num[i]=(i<len?num[i]:0)+(i<b.len?b.num[i]:0);
     for (int i=0;i<t.len;i++)
        if (t.num[i]>=10) {t.num[i]-=10;t.num[i+1]++;}
      if (t.num[t.len]) t.len++;
      return t;
}

char str[MAXL];
bigInt scan(){
    scanf("%s",str);
    t.len=strlen(str);
    for(int i=0;i<t.len;i++){
        t.num[i]=str[t.len-i-1]-'0';
    }
    return t;
}
bigInt make(int n){
    t.len=0;
    if(n==0){
        t.len=1;
        t.num[0]=0;
    }
    else{
        while(n){
            t.num[t.len++]=n%10;
            n/=10;
        }
    }
    return t;
}
int N,M;
bigInt a[4][MAXN];
int lowbit(int x){return x&-x;}
bigInt sum(int p,int k){
    bigInt res;
    res.len=0;
    while(p>0){
        res=res+a[k][p];
        p-=lowbit(p);
    }
    return res;
}
void update(int p,int k,bigInt c){
    while(p<=M){
        a[k][p]=a[k][p]+c;
        p+=lowbit(p);
    }
}
struct node{
    int n,idx;
    friend bool operator<(node a,node b){
        return a.n<b.n;
    }
}num[MAXN],numt[MAXN];
int mp[MAXN];
int main(){
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;i++){
          //  num[i].n=i;
            scanf("%d",&num[i].n);
            num[i].idx=i;
        }
        memcpy(numt,num,sizeof(num));
        sort(numt+1,numt+1+N);
        mp[numt[1].idx]=1;
        M=1;
        for(int i=2;i<=N;i++){
            if(numt[i].n>numt[i-1].n)mp[numt[i].idx]=++M;
            else mp[numt[i].idx]=M;
        }
        bigInt zero=make(0);
        for(int i=0;i<=3;i++){
            for(int j=1;j<=N;j++){
                a[i][j].len=0;
            }
        }
        bigInt one=make(1);
        bigInt res=make(0);

        for(int j=1;j<=N;j++){
           // printf("mp[num[%d]]=%d:",j,mp[num[j]]);print(sum(mp[num[j]]-1,0));
            update(mp[num[j].idx],1,sum(mp[num[j].idx]-1,0));
            //for(int i=1;i<=N;i++)print(a[1][i]);
            update(mp[num[j].idx],0,one);
            //for(int i=1;i<=N;i++)printf("%d ",cnt[i]);printf("\n");
            for(int k=2;k<=3;k++){
                update(mp[num[j].idx],k,sum(mp[num[j].idx]-1,k-1));
                if(k==3)res=res+sum(mp[num[j].idx]-1,3);
            }

        }

        print(res);

    }
    return 0;
}
