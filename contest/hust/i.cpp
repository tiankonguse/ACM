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
using namespace std;
typedef long long LL;
const int N = 1000000;
char str[N];


int main(int argc, char* argv[]) {
    int n,num,ans;
    char *p;
    while(gets(str)){
        p = str;
        ans = 0;
        num = 0;
        while(*p){
            if(*p == '('){
                if(num){
                    ans++;
                }else{
                    num = 1;
                }
            }else if(*p == ')'){
                if(num){
                    num = 0;
                }else{
                    ans++;
                }
            }else if(*p == '-' || *p == ':' || *p == ',' || *p == ';'){
                ans += num;
                num = 0;
            }
            p++;
        }
        ans += num;
        printf("%d\n",ans);
    }
    return 0;
}






