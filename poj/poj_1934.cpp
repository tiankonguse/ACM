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
bool yes[111][111];
char ans[1111][100];
int num;

char tmp[111];

void print() {
    strcpy(ans[num],tmp+1);
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


int compare(const void*elem1,const void *elem2) {
    return(strcmp((char*)elem1,(char*)elem2));
}

int main() {
    scanf("%s",str1+1);
    scanf("%s",str2+1);

    LCS();
    qsort(ans,num,100*sizeof(char),compare);

    printf("%s\n",ans[0]);

    for(int i=1;i<num;i++){
        if(strcmp(ans[i], ans[i-1])!=0) printf("%s\n",ans[i]);
//printf("%s\n",ans[i]);
    }

    return 0;
}
