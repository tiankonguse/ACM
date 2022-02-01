#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#define MAXN 1010
using namespace std;
double mp[MAXN][MAXN];
bool inTree[MAXN];
double min_length[MAXN];
double prim(int n)
{
    double sum_length=0;
    memset(inTree,false,sizeof(inTree));
    for(int i=1;i<n;i++)min_length[i]=1e11;
    min_length[0]=0;
    for(int i=0;i<n;i++){
        int min_index=-1;
        for(int j=0;j<n;j++){
          if(!inTree[j]&&(min_index==-1 || min_length[j]<min_length[min_index])){
             min_index=j;
          }
        }
        inTree[min_index]=true;
        sum_length += min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && mp[j][min_index]<min_length[j]){
                 min_length[j]=mp[j][min_index];
           }
        }
    }
    return sum_length;
}
map<string,int>_mp;
int main(){
    double k,t;
    int N,M,a,b;
    string s,s2;
    while(cin>>k){
        cin>>N;
        _mp.clear();
        for(int i=0;i<N;i++){
            cin>>s;
            _mp[s]=i;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                mp[i][j]=1e11;
            }
        }
        cin>>M;
        for(int i=0;i<M;i++){
            cin>>s>>s2>>t;
            a=_mp[s],b=_mp[s2];
            mp[a][b]=mp[b][a]=t;
        }
        double res=prim(N);
        if(res<=k){
            printf("Need %.1f miles of cable\n",res);
        }
        else{
            printf("Not enough cable\n");
        }
    }
    return 0;
}
