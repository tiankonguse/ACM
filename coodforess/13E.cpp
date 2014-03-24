/*************************************************************************
> File Name: 13E.cpp
> Author: tiankonguse
> Mail: i@tiankonguse.com 
> Created Time: Wed 12 Mar 2014 09:01:58 PM CST
************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

const int maxn = 100005;

int block[maxn], cnt[maxn],end[maxn],next[maxn];
int BLOCK;
int save[maxn];
int n;
void make(int x){
    int y=x+save[x];
    if(y>n){
        end[x]=x;
        next[x]=n+1;
        cnt[x]=1;
    }else if(block[x]==block[y]) {
        next[x]=next[y];
        end[x]=end[y];
        cnt[x]=cnt[y]+1;
    }else{
        next[x]=y;
        cnt[x]=1;
        end[x]=end[y];
    }

}

void myprint(){
    for(int i=1;i<=n;i++){
        printf("%d ",save[i]);
    }
    puts("");
}

void query(int x){
    int ans=cnt[x],e=end[x];
    while(1){
        x=next[x];
        if(x>n){
            break;
        }
        ans += cnt[x];
        e=end[x];
    }
    printf("%d %d\n",e,ans);
}


int main(){
    int m,a,b,op;
    scanf("%d%d", &n, &m);
    BLOCK = (int)ceil(sqrt(1.0 * n));
    for(int i=1;i<=n;i++){
        scanf("%d", &save[i]);
        block[i] = i/BLOCK;
    }

    //预处理
    for(int i=n;i;i--)make(i);

    //开始处理数据
    while(m--){
        scanf("%d", &op);
        if(op){
            scanf("%d", &a);
            query(a);
        }else{
            scanf("%d%d",&a,&b);
            save[a] = b;
            for(int i=a; i&&block[i]==block[a]; i--){
                make(i);
            }
        }
    }

    return 0;
}


