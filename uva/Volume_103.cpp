/*************************************************************************
    > File Name: Volume_1_103.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/12 18:36:18
 ************************************************************************/

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
int dem;
struct T{
    int point[11];
    int pos;
}str[33];

int ans[33],len[33],next[33];



bool cmp(const T a, const T b){
    for(int i=0;i<dem;i++){
        if(a.point[i] < b.point[i])return true;
        if(a.point[i] > b.point[i])return false;
    }
    return true;
}
bool Tless(const T a, const T b){
    for(int i=0;i<dem;i++){
        if(a.point[i] >= b.point[i])return false;
    }
    return true;
}



int main() {
    int n, k, i, j, lll,tmp,ansLen,ansPos;

    while(~scanf("%d%d", &n, &dem)){
        for(i=0;i<n;i++){
            str[i].pos = i+1;
            for(j=0;j<dem;j++){
                scanf("%d",&str[i].point[j]);
            }
            sort(str[i].point,str[i].point+dem);
        }
        sort(str,str+n,cmp);

        memset(len,1,sizeof(len));
        memset(next,-1,sizeof(next));

        ansPos = 0;
        ansLen = 1;

        for(i=0;i<n;i++){
            len[i]=1;
            for(j=0;j<i;j++){
                if(Tless(str[j],str[i]) && len[i] < len[j]+1){
                    len[i] = len[j] + 1;
                    next[i] = j;
                }
            }
            if(len[i] > ansLen){
                ansPos = i;
                ansLen = len[i];
            }
        }

        lll = len[ansPos];
        for(i=lll;i;i--){
            ans[i] = str[ansPos].pos;
            ansPos = next[ansPos];
        }
        printf("%d\n%d",lll,ans[1]);
        for(i=2;i<=lll;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");

    }

    return 0;
}
