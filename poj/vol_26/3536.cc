#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXP=1000005;
int pri[MAXP],cnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    cnt=1;pri[0]=2;mark[4]=1;
    for(i=3;i<MAXP;i++){
        if(!mark[i])pri[cnt++]=i;
        for(j=0;j<cnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}
int main(){
    setp();
    int v,u,s,k;
    int x,y,z;
    while(~scanf("%d",&v)){
        if(!mark[v])printf("%d 1 1\n",v);
        else{
            s=0x7f7f7f7f;
            for(int i=1;i<=1000;i++){
                if(v%i==0){
                    u=v/i;
                    int up=(int)sqrt(1.0*u);
                    for(int j=i;j<=up;j++){
                        if(u%j==0){
                            k=u/j;
                            if(i*j+i*k+j*k<s){
                                s=i*j+i*k+j*k;
                                x=i;
                                y=j;
                                z=k;
                            }
                        }
                    }
                }
            }
            printf("%d %d %d\n",x,y,z);
        }
    }
    return 0;
}
