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
#define maxn 52
#define size 52
#define wordlen 12
using namespace std;

char chr[128];
int sz;
map<char, int> mp;
int root, idx;
struct trie_node{
    int next[size];
    int fail;
    bool flag;
    void init(){
        fail = -1, flag = false;
        memset(next, 0, sizeof(next));
    }
}trie[maxn * wordlen];
int q[maxn * wordlen];
void trie_init(){
    root = idx = 0;
    trie[root].init();
}
void insert(char *s){
    int i, j, p = root;
    for(i=0;s[i];i++){
        j = mp[ s[i] ];
        if(!trie[p].next[j]){
            trie[++idx].init();
            trie[p].next[j] = idx;
        }
        p = trie[p].next[j];
    }
    trie[p].flag = true;
}
void build(){
    int j, tmp;
    q[0] = root;
    for(int l=0,h=1;l<h;){
        tmp = q[l++];
        for(j=0;j<sz;j++){
            if(trie[tmp].next[j]){
                q[h++] = trie[tmp].next[j];
                if(trie[tmp].fail == -1) trie[trie[tmp].next[j]].fail = root;
                else{
                    trie[trie[tmp].next[j]].fail = trie[trie[tmp].fail].next[j];
                    trie[trie[tmp].next[j]].flag |= trie[trie[trie[tmp].fail].next[j]].flag;
                }
            }
            else{
                if(trie[tmp].fail != -1) trie[tmp].next[j] = trie[trie[tmp].fail].next[j];
            }
        }
    }
}
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
        bool zero(){
            return (leng == 1 && num[0] == 0);
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
char word[wordlen];
BigInt dp[maxn][maxn * wordlen], res;

int main(){
    int n, m, p;
    while(~scanf("%d%d%d", &n, &m, &p)){
        sz = n;
        getchar();
        gets(chr);
        mp.clear();
        for(int i=0;i<n;i++){
            mp[chr[i]] = i;
        }
        trie_init();
        for(int i=0;i<p;i++){
            gets(word);
            insert(word);
        }
        build();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=idx;j++){
                dp[i][j] = BigInt();
            }
        }
        dp[0][0] = BigInt(1);
        for(int i=0;i<m;i++){
            for(int j=0;j<=idx;j++){
                if(trie[j].flag || dp[i][j].zero()) continue;
                for(int k=0;k<n;k++){
                    if(trie[trie[j].next[k]].flag) continue;
                    dp[i+1][trie[j].next[k]] = dp[i+1][trie[j].next[k]] + dp[i][j];
                }
            }
        }
        res = BigInt();
        for(int i=0;i<=idx;i++){
            if(!trie[i].flag) res = res + dp[m][i];
        }
        res.writeln();
    }
    return 0;
}
