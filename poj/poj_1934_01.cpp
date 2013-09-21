/*************************************************************************
    > File Name: poj_1934.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/11 22:13:57
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

char str1[100];
char str2[100];
int str[100][100];

int num;
vector<string> ary;
char tmp[111];

void print() {
    ary.push_back(tmp+1);
    num++;
}

void getans(int i,int j,int k) {

    if(k==0)print();

    if(i == 0 || j == 0)return ;

    if(str1[i] == str2[j]) {
        tmp[k] = str1[i];
        getans(i-1, j-1, k-1);
    }

    if(str[i-1][j] == k) {
        getans(i-1, j, k);
    }

    if(str[i][j-1] == k) {
        getans(i, j-1, k);
    }

}


void LCS() {
    memset(str,0,sizeof(str));
    int n = strlen(str1+1);
    int m = strlen(str2+1);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(str1[i] == str2[j]) {
                str[i][j] = str[i-1][j-1] + 1;
            } else {
                str[i][j] = max(str[i-1][j] ,str[i][j-1]);
            }
        }
    }
    num = 0;
    tmp[str[n][m]+1] = '\0';
    getans(n,m,str[n][m]);
}



int main() {
    scanf("%s",str1+1);
    scanf("%s",str2+1);

    LCS();
    sort(ary.begin(),ary.end());
    //cout<<ary[0]<<endl;
    printf("%s\n",ary[0].c_str());
    for(int i=1;i<num;i++){
        if(ary[i] == ary[i-1])continue;
        printf("%s\n",ary[i].c_str());
        //cout<<ary[i]<<endl;
    }

    return 0;
}
