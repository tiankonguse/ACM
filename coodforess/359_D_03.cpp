#include<cstdio>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int val = 3;
const int center = 0;
const int left = 1;
const int right = 2;

const int maxn = 401000;
int ans[maxn];
int maxrl,ansNum;

int str[maxn][4];


int main() {

    int n,i;
    int now_center,tmp;
    while(~scanf("%d",&n)) {

        for(i=1; i<=n; i++) {
            scanf("%d",&str[i][val]);
            str[i][left] = str[i][right] = i;
            str[i][center] = 0;
        }

        now_center = 1;
        str[now_center][center] = 1;
        for(i=2; i<=n; i++) {
            if(str[i][val] % str[now_center][val] == 0) {
                str[now_center][right] = i;
                str[i][left] = now_center;
            } else if(str[now_center][val] % str[i][val] == 0) {
                str[now_center][center] = 0;
                str[i][left] = now_center;
                str[now_center = i][center] = 1;
            } else {
                str[now_center = i][center] = 1;
            }
        }

        now_center = -1;
        for(i = n; i>=1; i--) {
            if(now_center == -1) {
                now_center = str[i][left];
                i = str[now_center][left];
            } else {
                if(str[i][val] % str[now_center][val] == 0) {
                    str[now_center][left] = i;
                } else if(str[i][center] == 1){
                    now_center = i;
                    i = str[now_center][left];
                }else{
                    now_center = str[i][left];
                    i = str[now_center][left];
                }
            }
        }

        maxrl = -1;
        ansNum = 0;
        for(i=1; i<=n; i++) {
            if(str[i][center] == 1) {
                tmp = str[i][right] - str[i][left];
                if(tmp > maxrl) {
                    maxrl = tmp;
                    ansNum = 0;
                    ans[ansNum++] = str[i][left];
                } else if(tmp == maxrl) {
                    if(ans[ansNum - 1] != str[i][left]) {
                        ans[ansNum++] = str[i][left];
                    }
                }
            }
        }

        printf("%d %d\n",ansNum, maxrl);

        for(i=0; i<ansNum-1; i++) {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[ansNum-1]);



    }



    return 0;
}
