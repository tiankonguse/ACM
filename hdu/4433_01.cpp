#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;
const int MAXN=1010;
const int INF=100000000;
char str1[MAXN],str2[MAXN];
int a[MAXN],b[MAXN];
int dp[MAXN][10][10];
//dp[i][x][y]表示处理到第i个，后面两位是xy时的最小操作数

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int x,y;
    int xx,yy;
    int i,j,k;
    while(scanf("%s%s",&str1,&str2)!=EOF) {
        n=strlen(str1);
        for(i=1; i<=n; i++) {
            a[i]=str1[i-1]-'0';
            b[i]=str2[i-1]-'0';
        }
        for(i=0; i<=n; i++)
            for(x=0; x<10; x++)
                for(y=0; y<10; y++)
                    dp[i][x][y]=INF;
        //初始化
        dp[0][0][0]=0;
        for(i = 1 ; i <= n ; i++)//1到n进行DP
            for(x = 0 ; x < 10 ; x++) { //这是第i-1个数
                if(i <= 1 && x > 0) break;
                for(y = 0 ; y < 10 ; y++) { //这是第i个数
                    //增加和减少变换
                    //把第i个数调整正确，需要的步数
                    int d1 = (b[i] - y + 10)%10;//这是正向转
                    int d2 = (y - b[i] + 10)%10;//这是逆向转

                    //下面的DP过程就是把i的状态表示成i-1的状态
                    if(i==1) {
                        xx=0;
                        yy=0;
                        dp[i][x][y]=min(dp[i][x][y],dp[i-1][xx][yy]+min(d1,d2));
                        continue;
                    }
                    if(i==2) {
                        xx=0;//i-1的倒数第2位一定是0

                        //下面是枚举i-1的倒数第一位
                        for(j=x; j<=x+d1; j++) {
                            yy=j%10;
                            dp[i][x][y]=min(dp[i][x][y],dp[i-1][xx][yy]+d1);
                        }
                        for(j=x; j>=x-d2; j--) {
                            yy=(j+10)%10;
                            dp[i][x][y]=min(dp[i][x][y],dp[i-1][xx][yy]+d2);
                        }
                        continue;
                    }
                    //枚举i-1的倒数第1位和倒数第2位
                    for(j=0; j<=d1; j++)
                        for(k=j; k<=d1; k++) {
                            xx=(a[i-2]+j)%10;
                            yy=(x+k)%10;
                            dp[i][x][y]=min(dp[i][x][y],dp[i-1][xx][yy]+d1);
                        }
                    for(j=0; j<=d2; j++)
                        for(k=j; k<=d2; k++) {
                            xx=(a[i-2]-j+10)%10;
                            yy=(x-k+10)%10;
                            dp[i][x][y]=min(dp[i][x][y],dp[i-1][xx][yy]+d2);
                        }
                }
            }
        if(n>=2)x=a[n-1];
        else x=0;
        if(n>=1)y=a[n];
        else y=0;
        printf("%d\n",dp[n][x][y]);
    }
    return 0;
}
