#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff
#define maxn 100010
using namespace std;


long long a[30];
long long b[15];
char s[100005];
int main()
{
    cin>>s;
    int i;
    int len = strlen(s);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            a[s[i]-'a']++;
        }
        else b[s[i]-'0']++;
    }
    long long sum=0;
    for(i=0;i<26;i++)
    {
        sum += a[i]*a[i];
    }
    for(i=0;i<10;i++)
         sum += b[i]*b[i];
    cout<<sum<<endl;
    return 0;
}
