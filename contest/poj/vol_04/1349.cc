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
#define maxn 222
using namespace std;
char str[maxn];
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

BigInt operator+(BigInt a,int b)
{
        int t=0;
        BigInt ans;
        memcpy(ans.num,a.num,sizeof(a.num));
        ans[t]+=b;
        while(a[t]>=10000)
        {
                ans[t+1]+=ans[t]/10000;
                ans[t]%=10000;
        }
        ans.getlength();
        return ans;
}

//a必须大于等于b
BigInt operator-(BigInt a,BigInt b)
{
        int l=a.leng;
        BigInt ans;
        memcpy(ans.num,a.num,sizeof(a.num));
        for(int i=0;i<l;i++)
        {
                ans[i]-=b[i];
                if(ans[i]<0)
                {
                        ans[i]+=10000;
                        ans[i+1]--;
                }
        }
        ans.getlength();
        return ans;
}

//一种看起来快点的乘法
BigInt operator*(BigInt a,BigInt b)
{
        int la=a.leng,lb=b.leng,t,p;
        BigInt ans;
        for(int i=0;i<la;i++)
        {
                t=0;
                for(int j=0;j<lb;j++)
                {
                        p=(ans[i+j]+a[i]*b[j]+t)/10000;
                        ans[i+j]=(ans[i+j]+a[i]*b[j]+t)%10000;
                        t=p;
                }
                p=i+lb;
                if(t)
                {
                        ans[p]+=t;
                        while(ans[p]>=10000)
                        {
                                ans[p+1]+=ans[p]/10000;
                                ans[p]%=10000;
                                p++;
                        }
                }
        }
        ans.getlength();
        return ans;
}


BigInt operator*(BigInt a,int b)
{
        int t=0,p=a.leng;
        BigInt ans;
        for(int i=0;i<p;i++)
        {
                ans[i]=(a[i]*b+t)%10000;
                t=(a[i]*b+t)/10000;
        }
        while(t)
        {
                ans[p++]=t%10000;
                t/=10000;
        }
        ans.getlength();
        return ans;
}
BigInt frac[55], res;
bool used[maxn];
int arr[maxn];
int main(){
    frac[0] = BigInt(1);
    for(int i=1;i<=50;i++){
        frac[i] = frac[i - 1] * i;
    }
    int len, n, cnt, ant, bra;
    bool first = true;
    while(~scanf(" %s", str)){
        if(str[0] == '-'){
            puts("");
            break;
        }
        len = strlen(str);
        n = cnt = bra = 0;
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<len;i++){
            if(str[i] == '(') bra++;
            if(isdigit(str[i]) && bra == 1){
                    n = n * 10 + str[i] - '0';
            }
            else if(bra == 2){
                if(isdigit(str[i])){
                    arr[cnt] = arr[cnt] * 10 + str[i] - '0';
                }
                else if(str[i] == ','){
                    cnt++;
                }
            }
        }

        res = BigInt(1);
        memset(used, false, sizeof(used));
        for(int i=0;i<n;i++){
            used[ arr[i] ] = true;
            ant = 0;
            for(int j=arr[i]-1;j>=1;j--){
                ant += !used[j];
            }
            res = res + (frac[n - i - 1] * ant);
        }
        if(!first) printf(",");  first = false;
        res.write();
    }
    return 0;
}
