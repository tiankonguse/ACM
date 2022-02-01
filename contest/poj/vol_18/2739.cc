#include"cmath"
#include"cstdlib"
#include"iostream"
using namespace std;
const int max = 10005;
bool isprime[::max];
int pri[::max];
int pri_cnt;
void setp()
{
    int i,j;
    memset(isprime,true,sizeof(isprime));
    int end=(int)sqrt(::max*1.0);
    for(i = 3 ; i <= end ; i += 2 )
    {
        for(j = 3 ; j <= ::max / i ; j += 2)
        {
            if(isprime[i])
            {
                isprime[i * j] = false;
            }
        }
    }
    for(i = 4 ; i <= ::max ; i += 2 )
    {
        isprime[i] = false;
    }
    isprime[1] = isprime[0] = false;
}
void GetPri(int n)
{
    int i;
    pri_cnt=0;
    for(i=2; i<n; i++)
    {
        if(isprime[i])
            pri[++pri_cnt]=i;
    }
    pri[0]=pri_cnt;
}
int main()
{
    setp();
    GetPri(10005);
    int n;
    while(scanf("%d",&n)&&n)
    {
        int cnt=0;
        for(int i=1; pri[i]<=n; i++)
        {
            int sum=0;
            for(int j=i;; j++)
            {
                sum+=pri[j];
                if(sum==n)cnt++;
                if(sum>n)break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
