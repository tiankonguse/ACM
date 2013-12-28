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

const int N = 33330;
int ans[N];
int num[N];
int after[N];
int after100[N];
int have[N];

int main() {
    int n,k,op,i,j,end,out;
    while(~scanf("%d%d",&n,&k)) {

        memset(after,0,sizeof(after));
        memset(after100,0,sizeof(after100));
        memset(ans,0,sizeof(ans));
        memset(num,0,sizeof(num));
        memset(have,0,sizeof(have));

        for(i=0; i<n; i++) {
            scanf("%d",&have[i]);
        }


        for(i=n; i>=0; i--) {
            if(after[i+1] || have[i+1]) {
                after[i] = 1;
            }
            if(after100[i+1] || have[i+1] == 100) {
                after100[i] = 1;
            }
        }

        num[0] = k;
        ans[0] = 1;
        out = 0;

        for(i=0; i<n; i++) {
            //现在集合是 i i+1 i+2 ... n
            if(num[i]) { //可以杀人
                if(have[i] == 0 || after100[i]) {
                    //i需要马上死
                    if(have[i]) {
                        //死定了,死前带走一个
                        ans[i+2] = 1;// 得到i+2 ... n 的集合
                        num[i+2] = max(num[i+2], num[i]-1); //更新得到这个集合时剩余的步数

                        if(have[i] != 100){
							//死前瞑目，绕他一命
							ans[i+1] = 1;// 得到i+1 i+2 ... n 的集合
							num[i+1] = max(num[i+1], num[i]-1); //更新得到这个集合时剩余的步数
                        }

                    } else {
                        if(after[i]){
							//乖乖的死去
							ans[i+1] = 1;// 得到i+1 i+2 ... n 的集合
							num[i+1] = max(num[i+1], num[i]-1); //更新得到这个集合时剩余的步数
                        }
                    }

                } else {
                    //i 可以打死人，而且没有人可以确定能杀死他
                    for(j=1; j<=num[i] && i+j < n; j++) {
                        //第j步可以打死 i+j
                        ans[i]++;//得到 i i+j+1 i+j+2 ... n 的集合

                        if(after[i+j-1]) {
                            //第j步才打死 i

                            //i 打死了 i+j
                            ans[i+j+1] =1;// 得到i+j+1 i+j+2 ... n 的集合
                            num[i+j+1] = max(num[i+j+1], num[i]-j); //更新得到这个集合时剩余的步数


                            if(have[i] != 100) {
                            	//i没能够打死 i+j
                                ans[i+j] =1;// 得到i+j+1 i+j+2 ... n 的集合
                                num[i+j] = max(num[i+j], num[i]-j); //更新得到这个集合时剩余的步数
                            }

                        }
                    }
                }
            }

            out += ans[i];
//            printf("ans[%d] = %d  nun[%d] = %d\n",i,ans[i],i,num[i]);
        }
        out += ans[n];

        printf("%d\n",out);
    }

    return 0;
}
