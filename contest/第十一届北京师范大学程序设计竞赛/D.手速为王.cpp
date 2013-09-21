/*************************************************************************
    > File Name: D.手速为王.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/2 18:39:22
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
typedef long long LL;
const int N=1020010;
char _str[N];
char* str[N];
int len[N];
int comLen[N];

LL ans;

struct node{
    int h,l,r;
    LL sum;
    node(){}
    node(int h,int l,int r,LL sum):h(h),l(l),r(r),sum(sum){}
};

stack<node>sta;

bool cmp(char const*a,char const*b){
    return strcmp(a,b)<=0;
}

int getStringLen(char *a){
    int i = 0;
    for(;*a++;i++);
    return i;
}

int getCommonStringLen(char *a,char *b){
    int i=0;
    for(i=0;*a&&*b&&*a++==*b++;i++);
    return i;
}

int main() {
    int n,i,j,left;
    char* p;
    scanf("%d",&n);
    while(~scanf("%d",&n)){
        p = _str;
        ans = 0;
        for(i=0,j=0;i<n;i++,j++,j++){
            str[j] = p;
            scanf("%s",str[j]);
            len[j] = getStringLen(str[j]);
            p += len[j] + 1;
            ans += len[j];

            str[j+1] = p;
            strcpy(str[j+1],str[j]);
            len[j+1] = len[j];
            p += len[j] + 1;
            ans += len[j];
            reverse(str[j+1],str[j+1]+len[j]);
        }
        n = j;

        ans *= (n-1);

        sort(str,str+n,cmp);
//         printf("%d %s\n",strlen(str[0]),str[0]);
        for(i=1;i<n;i++){
            comLen[i] = getCommonStringLen(str[i-1],str[i]);
//            printf("%d\n",getCommonLen(str[i-1],str[i]));
//            printf("%d %s\n",strlen(str[i]),str[i]);
        }

        while(!sta.empty())sta.pop();
        for(i=1;i<n;i++){
            left = i;
            while(!sta.empty() && sta.top().h >= comLen[i]){
                left = sta.top().l;
                sta.pop();
            }

            if(sta.empty()){
                if(comLen[i] != 0){
                    sta.push(node(comLen[i],left,i,(i-left+1)*comLen[i]));
                    ans -= sta.top().sum<<1;
                }
            }else{
                sta.push(node(comLen[i],left,i,sta.top().sum + (i-left+1)*comLen[i]));
                ans -= sta.top().sum<<1;
            }
        }

        printf("%lld\n",ans);
    }


    return 0;
}
