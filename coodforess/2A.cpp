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
typedef long long LL;

map<string,int>m;
int str[1111],str2[1111];
int size;
char name[1111][50];
int score[1111];

int main() {

    int n,i;

    int pos;
    int maxScore;
    while(~scanf("%d",&n)) {
        m.clear();
        size = 0;

        for(i=0; i<n; i++) {
            scanf("%s%d",name[i], & score[i]);
            pos = m[name[i]];
            if(pos == 0) {
                str[++size] = 0;
                pos = m[name[i]] = size;
            }
            str[pos] += score[i];
        }

        maxScore = str[1];
        for(i=1; i<=size; i++) {
//        	printf("%d %d\n",i,str[i]);
            maxScore = max(maxScore, str[i]);
        }

        m.clear();
        size = 0;
//        printf("%d\n",maxScore);
        for(i=0; i<n; i++) {
            pos = m[name[i]];
            if(pos == 0) {
                str2[++size] = 0;
                pos = m[name[i]] = size;
            }
            str2[pos]  += score[i];
//            printf("%32s str[%d] = %d str2[%d] = %d\n",name[i],pos, str[pos],pos, str2[pos]);
            if(str[pos]  == maxScore && str2[pos] >= maxScore) {
                break;
            }
        }

        printf("%s\n",name[i]);
    }
    return 0;
}
