#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

const int c[8]={1024,1024,960,2048,1136,1280,1080,1136};
const int d[8]{768,600,640,1536,640,800,1920,640};
const int price[8]={319,419,450,519,599,600,630,719};

double find(int H,int W,int HH,int WW){
    double head=0,tail=6000;
    for (int i=1; i<=100; ++i){
        double mid=(head+tail)/2;
        if (H*mid<=HH && W*mid<=WW) head=mid;
        else tail=mid;
    }
    return head;
}

int main(){
    int H,W;
    while(scanf("%d%d",&H,&W),H ||W){
        double ans=0;
        int pri=0;
        for (int I=0; I<8; ++I){
            double TT=find(H,W,c[I],d[I]);
            int C=floor(H*TT+(1e-8)),D=floor(W*TT+(1e-8));
            double cc=(double)C*D/(c[I]*d[I]);
            if (cc>ans){
                ans=cc;
                pri=price[I];
            }
            else if (abs(ans-cc)<1e-8) pri=min(pri,price[I]);
            TT=find(H,W,d[I],c[I]);
            C=floor(H*TT+(1e-8)),D=floor(W*TT+(1e-8));
            cc=(double)C*D/(c[I]*d[I]);
            if (cc>ans){
                ans=cc;
                pri=price[I];
            }
            else if (abs(ans-cc)<1e-8) pri=min(pri,price[I]);
        }
        printf("%d\n",pri);
    }
}
