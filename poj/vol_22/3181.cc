#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1010
using namespace std;

const int maxleng=50;

class BigInt//高精度类
{
public:
        int leng;//长度
        int num[maxleng];//数字
public:
        BigInt()
        {
                leng=1;
                memset(num,0,sizeof(num));
        }
        BigInt(int x)
        {
                leng=0;
                memset(num,0,sizeof(num));
                while(x)
                {
                        num[leng++]=x%10000;
                        x/=10000;
                }
                if(leng==0)leng=1;
        }
        operator int()
        {
                int x=0,l=leng-1;
                while(l>=0)
                {
                        x=x*10000+num[l];
                        l--;
                }
                return x;
        }
        operator int*()
        {
                return num;
        }
        int length()
        {
                return leng;
        }
        void read()
        {
                char s[maxleng+1];
                scanf("%s",s);
                int l=strlen(s);
                leng=0;
                for(int i=l-1;i>=0;)
                {
                        if(i>=0)num[leng]+=(s[i--]-'0');
                        if(i>=0)num[leng]+=(s[i--]-'0')*10;
                        if(i>=0)num[leng]+=(s[i--]-'0')*100;
                        if(i>=0)num[leng]+=(s[i--]-'0')*1000;
                        leng++;
                }
                if(leng==0)leng=1;
        }
        void write()
        {
                int i=leng-1;
                printf("%d",num[i]);i--;
                while(i>=0)printf("%04d",num[i--]);
        }
        void writeln()
        {
                write();
                printf("\n");
        }
        void getlength()
        {
                leng=maxleng-1;
                while(num[leng]==0&&leng>0)leng--;
                leng++;
        }
        friend BigInt operator+(BigInt a,BigInt b);
        friend BigInt operator+(BigInt a,int b);
        friend BigInt operator-(BigInt a,BigInt b);
        friend BigInt operator*(BigInt a,BigInt b);
        friend BigInt operator*(BigInt a,int b);
        friend BigInt operator/(BigInt a,BigInt b);
        friend bool operator<(BigInt a,BigInt b);
};

BigInt operator+(BigInt a,BigInt b)
{
        int l=a.leng>b.leng?a.leng:b.leng,t=0;
        BigInt ans;
        for(int i=0;i<l;i++)
        {
                ans[i]=(a[i]+b[i]+t)%10000;
                t=(a[i]+b[i]+t)/10000;
        }
        while(t)
        {
                ans[l++]=t%10000;
                t/=10000;
        }
        ans.leng=l;
        return ans;
}
BigInt dp[maxn];
int main(){
    int n, k;
    while(~scanf("%d%d", &n, &k)){

        dp[0] = 1;
        for(int i=1;i<=k;i++){
            for(int j=i;j<=n;j++){
                dp[j] = dp[j] + dp[j - i];
            }
        }
        dp[n].writeln();
    }
    return 0;
}
