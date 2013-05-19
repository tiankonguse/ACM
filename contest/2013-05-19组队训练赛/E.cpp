
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1100;
bool str[N];
bool have[12];
int xi[12];
int sum;
int t,k;
int _left,_right;

bool dfs(int lev,int pos,int s){
    if(lev == k){
        if(pos > _right)return true;
        else return false;
    }
    if(sum - s >= _right - pos + 1){
        return true;
    }
    while(str[pos])pos++;
    for(int i=0;i<k;i++){
        if(have[i])continue;
        have[i]=true;
        if(dfs(lev+1,pos+xi[i],s+xi[i])){
            have[i]=false;
            return true;
        }
        have[i]=false;
    }

    return false;

}

int main(){
    int n,i,j,pos;
    while(~scanf("%d%d%d",&t,&k,&n)){
            sum = 0;
        for(i=0;i<k;i++){
            scanf("%d",&xi[i]);
            sum  += xi[i];
        }
        memset(str,true,sizeof(str));
        memset(have,false,sizeof(have));
        _left = t;
        _right = 1;
        while(n--){
            scanf("%d",&pos);
            str[pos] = false;
            _left = min(_left,pos);
            _right = max(_right,pos);
        }
        printf("%s\n",dfs(0,_left,0)?"Yes":"No");
    }
}
/*
10 1 5
4
3 4 6 8 9
*/
