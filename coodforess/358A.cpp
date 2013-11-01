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
static int _ = 100000000;
#define P64(a) {if(a <= _){printf("%d",a);}else{printf("%d%08d",a/_,a%_);}}
struct T{
    int left,right;
    bool operator<(const T a)const{
        if(this->left == a.left){
            return this->right > a.right;
        }else{
            return this->left < a.left;
        }
    }
}str[1111];
stack<int>sta;

int main(int argc, char* argv[]) {
    int n,now,pre,i;
    while(~scanf("%d",&n)){
        scanf("%d",&pre);
        n--;
        for(i=0;i<n;i++){
            scanf("%d",&now);
            str[i].left = pre;
            str[i].right = now;
            pre = now;
            if(str[i].left > str[i].right){
                swap(str[i].left, str[i].right);
            }
        }
        sort(str,str+n);
        while(!sta.empty()){
            sta.pop();
        }
        for(i=0;i<n;i++){
            while(!sta.empty() && str[i].left >= sta.top())sta.pop();
            if(sta.empty() || str[i].right <= sta.top()){
                sta.push(str[i].right);
            }else{
                break;
            }
        }
        printf("%s\n",i<n?"yes":"no");

    }
    return 0;
}






