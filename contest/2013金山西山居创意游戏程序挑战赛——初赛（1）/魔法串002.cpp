/*************************************************************************
    > File Name: 魔法串002.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 20:37:24
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 1111;
char first[N];
char second[N];
bool map[30][30];
int a[N][N];
bool LCS(const char *s1, const char *s2){
	int m = strlen(s1), n = strlen(s2);
	int i, j;
	a[0][0] = 0;
	for( i=1; i <= m; ++i ) a[i][0] = 0;
	for( i=1; i <= n; ++i ) a[0][i] = 0;

	for( i=1; i <= m; ++i )
	for( j=1; j <= n; ++j ){
		if(map[s1[i-1]-'a'][s2[j-1]-'a']){
//		    printf("----%d  %d\n",i-1,j-1);
             a[i][j] = a[i-1][j-1]+1;
		}
		else if(a[i-1][j]>a[i][j-1])a[i][j]= a[i-1][j];
		else a[i][j] = a[i][j-1];
	}
//	printf("--%d  %d\n",a[m][n],n);
	return a[m][n] == n;
}
int main() {
    int cas,n,i,ca=1;
    char op1[3],op2[3];
    scanf("%d",&cas);
    while(cas--){
        memset(map,false,sizeof(map));
        for(i=0;i<26;i++){
            map[i][i] = true;
        }

        scanf("%s%s",first,second);
        scanf("%d",&n);
        while(n--){
            scanf("%s%s",op1,op2);
            map[op1[0]-'a'][op2[0]-'a'] = true;
        }

        printf("Case #%d: %s\n",ca++,LCS(second,first)?"happy":"unhappy");

    }
    return 0;
}
