#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
const int MAXP=32768;
inline int _pow(int a,int b){int r=1;for(int i=0;i<b;i++)r*=a;return r;}
int pri[MAXP],cnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    cnt=1;pri[0]=2;mark[4]=1;
    for(i=3;i<MAXP;i+=2){
        if(!mark[i])pri[cnt++]=i;
        for(j=0;j<cnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}
int res[MAXP][2];
int solve(int x){
    int r=0;
    for(int i=0;i<cnt;i++){
        if(x%pri[i]==0){
            res[r][0]=pri[i];
            res[r][1]=0;
            while(x%pri[i]==0){
                x/=pri[i];
                res[r][1]++;
            }
            r++;
        }
        if(x==1)return r;
    }
    return r;
}
int main(){
    setp();
    int p,e,x;
    string str;
    while(getline(cin,str)){
        if(str[0]=='0')break;
        istringstream ss(str);
        x=1; while(ss>>p>>e)x*=_pow(p,e); x--;
        int k=solve(x);
        for(int i=k-1;i>=0;i--){
            if(i==0)cout<<res[i][0]<<" "<<res[i][1]<<endl;
            else cout<<res[i][0]<<" "<<res[i][1]<<" ";
        }

    }
    return 0;
}
