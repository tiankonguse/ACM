/**************************************************************************
 **      File Name: Volume_1_111.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/10 13:57:44
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


int ans[25][25];

int LCS(int n,int* first, int* second){
    memset(ans,0,sizeof(ans));
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(first[i] == second[j]){
                ans[i][j] = ans[i-1][j-1] + 1;
            }else{
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
    }
    return ans[n][n];

}

int main(){
    int i,j;
    int n;
    int str1[25]={-1};
    int str2[25]={-1};
    while(~scanf("%d",&n)){

        for(i=1;i<=n;i++){
            scanf("%d",&str1[i]);
        }

        for(i=1;i<n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&str2[j]);
            }
            printf("%d\n",LCS(n,str1,str2));
        }

    }

    return 0;
}
