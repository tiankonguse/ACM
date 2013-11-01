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
            return this->right < a.right;
        }else{
            return this->left < a.left;
        }
    }
}str[1111];
stack<int>sta;

int main(int argc, char* argv[]) {
    int n,now,pre,i,j;
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
        bool ok = false;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(str[j].left > str[i].left && str[j].left < str[i].right && str[j].right > str[i].right){
                    ok = true;

                    break;
                }
            }
            if(ok){
                break;
            }
        }
        printf("%s\n",ok?"yes":"no");

    }
    return 0;
}






