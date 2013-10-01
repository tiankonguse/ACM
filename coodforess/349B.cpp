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

struct Digit{
    int pos;
    int val;
    void init(int pos, int val){
        this->pos = pos;
        this->val = val;
    }
    bool operator< (const Digit& digit) const{
        if(this->val != digit.val){
            return this->val < digit.val;
        }else{
            return  this->pos > digit.pos;
        }

    }
}digit[10];
char ans[1000010];

int main() {
    int n,i,tmp,len,left,min,j,use;
    while(~scanf("%d",&n)){
        for(i=0;i<9;i++){
            scanf("%d",&tmp);
            digit[i].init(i+1,tmp);
        }
        sort(digit, digit+9);

        len = n / digit[0].val;
        if(len == 0){
            printf("-1\n");
            continue;
        }

        left = n - len * digit[0].val;

        ans[len] = '\0';

        for(i=0;i<len;i++){
            min = digit[0].pos;
            use = digit[0].val;
            ans[i] = '0' + min;

            if(left > 0){
                for(j=0;j<9;j++){
                    if(digit[j].pos > min && digit[j].val <= left + use){
                        left = left + use - digit[j].val;
                        min = digit[j].pos;
                        use = digit[j].val;
                        ans[i] = '0' + min;

                    }
                }
            }
        }
        printf("%s\n",ans);

    }
    return 0;
}
