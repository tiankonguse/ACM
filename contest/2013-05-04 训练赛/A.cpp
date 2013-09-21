#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff
#define maxn 100010
using namespace std;

char str[130];


int get(char c){
    if(c=='A')return 4;
    if(c=='K')return 3;
    if(c=='Q')return 2;
    if(c=='J')return 1;
    return 0;
}

int main(){
    int n=13;
    int ans;
    while(~scanf("%s",str)){
            ans = 0;
            ans += get(str[1]);
            for(int i=1;i< 13;i++){
                    scanf("%s",str);
               ans += get(str[1]);
            }
            printf("%d\n",ans);
    }

    return 0;
}
