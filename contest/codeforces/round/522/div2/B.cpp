#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;


int main() {


#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

	char str[222];
	char ans[7][33];
	while(~scanf("%s", str)){
		int len = strlen(str);
		int minRow = (len + 19)/20;
		int minColumn = (len + minRow - 1)/minRow;
		int start = minRow * minColumn - len;
		int avgLeter = len/minRow;
		int lefLeter =  len%minRow;
		
		memset(ans,'*', sizeof(ans));
		int index = 0;
		printf("%d %d\n", minRow, minColumn);
		for(int i=0;i<minRow; i++){
			for(int j=0;j<minColumn; j++){
				if(j < avgLeter){
					ans[i][j] = str[index++];
				}else if(j == avgLeter && i < lefLeter){
					ans[i][j] = str[index++];
				}else{
					ans[i][j] = '*';
				}
			}
			ans[i][minColumn] = '\0';
			printf("%s\n",ans[i]);
		}
		
	}


    return 0;
}
