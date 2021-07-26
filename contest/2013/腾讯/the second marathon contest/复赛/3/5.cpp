/**************************************************************************
 **      File Name: 5.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 18:27:12
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const int maxn=100010;

struct T{
    int hert,money;
}str[maxn];

int kill[maxn];
bool have[maxn];
int n,m;
__int64 ans;
int minleft,maxright;

bool cmp0(const int&a, const int&b){
    return a<b;
}

bool cmp1(const T& a,const T&b){
    return a.hert < b.hert;
}
bool cmp2(const T& a,const T&b){
    if(a.money == b.money)return a.hert < b.hert;
    return a.money < b.money;
}

//判断是否有解
bool ok(){
    int i,j;

    if(n>m){
        return false;
    }

    sort(str,str+m,cmp1);
    sort(kill,kill+n,cmp0);

    for(j=0,i=0;i<n;i++){
        while(j<m && str[j].hert < kill[i])j++;
        if(j == m)return false;
        j++;
    }

    return true;
}

int find(int l,int r,int val){

    if(l > r)return -1;

    if(l == r ){
        if(kill[l] <= val)return l;
        return -1;
    }

    if(l +1 == r){
        if(kill[r] <= val)return r;
        if(kill[l] <= val)return l;
        return -1;
    }

    int mid = (l+r)>>1;

    if(kill[mid] <= val)return find(mid,r,val);
    return find(l,mid-1,val);
}

bool minfind(){

    int num=0,i,j,pos;
    minleft = 0;
    maxright = n-1;
    ans = 0;

    sort(str,str+m,cmp2);
//
//    for(i=0;i<m;i++){
//        printf("%d--%d %d\n",i,str[i].hert,str[i].money);
//    }

    for(i=0;i<m;i++){
        pos = find(minleft,maxright,str[i].hert);
       // printf("pos=%d  minleft=%d\n",pos,minleft);
        if(pos == -1)continue;
        while(pos >= minleft && have[pos])pos--;

        if(pos < minleft)continue;

        have[pos]=true;
        //printf("find %d\n",pos);
        num++;

        ans += str[i].money;

        if(num == n)return true;

        while(have[minleft] && minleft <= maxright)minleft++;
        while(have[maxright] && minleft <= maxright)maxright--;
        if(minleft > maxright)return false;

        //printf("minleft=%d maxright=%d\n",minleft,maxright);
    }
    return false;
}


int main(){

    int i;

    while(scanf("%d%d",&n,&m)!=EOF){

        for(i=0;i<n;i++){
            scanf("%d",&kill[i]);
            have[i]=false;
        }

        for(i=0;i<m;i++){
            scanf("%d",&str[i].hert);
        }

        for(i=0;i<m;i++){
            scanf("%d",&str[i].money);
        }

        if(!ok()){
            printf("No\n");
        }else{

            if(minfind()){
                printf("%I64d\n",ans);
            }else{
                printf("No\n");
            }
        }

    }

    return 0;
}
