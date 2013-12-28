#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
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

char str[1000];
char ans[1000];

char tmp[1000];
int tmpLen;
char first[256][100];
char map[256];


void read(int& i) {
    char find_char = str[i++]; // { ( [
    int len = 0;
    if(str[i] >= 'A' && str[i] <= 'Z'){
		str[i] = str[i] - 'A' + 'a';
    }
    while(str[i] != map[find_char]) {
        first[find_char][len++] = str[i++];
        first[find_char][len] = '\0';
    }
    i++; //  ) } {
}

int main() {
    int i,j,k;
    map['('] = ')';
    map['['] = ']';
    map['{'] = '}';

    while(gets(str)) {
        ans[0] = '\0';
        i = 0;
        tmpLen = 0;
        tmp[tmpLen] = '\0';
        int num = 0;

        while(str[i]) {
            while(str[i] && str[i] != '(' && str[i] != '{'  && str[i] != '[' ) {
                tmp[tmpLen++] = str[i++];
                tmp[tmpLen] = '\0';
            }
            if(!str[i]) {
            	strcpy(ans, tmp);
                break;
            }
            tmp[tmpLen++] = '%';
            tmp[tmpLen++] = 's';
            tmp[tmpLen] = '\0';
            read(i);
            num++;
            if(num %3 == 0){
				sprintf(ans,tmp,first['{'],first['('],first['[']);
				strcpy(tmp, ans);
				tmpLen = strlen(tmp);
            }
        }
        if(ans[0] >= 'a' && ans[0] <= 'z'){
			ans[0] = ans[0] - 'a' + 'A';
        }
        printf("%s\n",ans);

//(We) [are] {blind}, if (we) [could not see] {creation of this clone army}
//{Truly wonderful} (the mind of a child) [is]
//


    }
    return 0;
}
