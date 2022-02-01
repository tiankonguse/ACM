#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const int MAXP=1005;
int pri[MAXP],cnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    cnt=2;pri[0]=1;pri[1]=2;mark[4]=1;
    for(i=3;i<MAXP;i+=2){
        if(!mark[i])pri[cnt++]=i;
        for(j=1;j<cnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}
int search(int x){
    int l=0,h=cnt-1,mid;
    while(l<=h){
        mid=(l+h)>>1;
        if(pri[mid]>x)h=mid-1;
        else l=mid+1;
    }
    return h;
}
int main(){
    setp();
    int N,C,tal,l,r,mid;
    while(~scanf("%d%d",&N,&C)){
        printf("%d %d:",N,C);
        tal=search(N)+1;
        if(tal%2==1){
            mid=tal/2;
            l=max(0,mid-C+1);
            r=min(tal-1,mid+C-1);
            for(int i=l;i<=r;i++){
                printf(" %d",pri[i]);
            }
            printf("\n");
        }
        else{
            mid=(tal-1)/2;
            l=max(0,mid-C+1);
            r=min(tal-1,mid+C);
            for(int i=l;i<=r;i++){
                printf(" %d",pri[i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
