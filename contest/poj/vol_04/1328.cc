#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 1005
using namespace std;
struct node{
    double s,t;
    friend bool operator<(node a,node b){
        return a.t<b.t;
    }
}nod[MAXN];
bool used[MAXN];
int main(){
    int N,ca=1;
    double r,x,y,d;
    while(scanf("%d %lf",&N,&r)&&N){
        bool flag=true;
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&x,&y);
            if(y>r){flag=false;continue;}
            d=sqrt(r*r-y*y);
            nod[i].s=x-d;
            nod[i].t=x+d;
        }
        if(!flag){
            printf("Case %d: -1\n",ca++);
            continue;
        }
        sort(nod,nod+N);
        memset(used,false,sizeof(used));
        double px;
        int cnt=0;
        for(int i=0,j;i<N;i++){
            if(!used[i]){
                cnt++;
                used[i]=true;
                px=nod[i].t;
                for(j=i+1;j<N;j++){
                    if(nod[j].s<=px)used[j]=true;
                    else break;
                }
                i=j-1;
            }
        }
        printf("Case %d: %d\n",ca++,cnt);
    }
    return 0;
}
