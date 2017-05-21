#include"iostream"
#include"cmath"
using namespace std;
const int max = 1000005;
bool isprime[::max];
int pri[::max];
int pri_cnt;
inline int Phi(int u)
{
    int phi=u;
    for (int i=1; i<=pri[0]&&pri[i]*pri[i]<=u; ++i)
        if (u%pri[i]==0)
        {
            phi=phi/pri[i]*(pri[i]-1);
            for (; u%pri[i]==0; u/=pri[i]);
        }
    if (u>1)    phi=phi/u*(u-1);
    return phi;
}
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
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    setp();
    GetPri(::max);
    int N,k,res,p;
    while(~scanf("%d%d",&N,&k))
    {
        k--;
        p=Phi(N);
        res=N*(k/p);
        k%=p;
        for(int i=1; i<=N; i++)
        {
            if(gcd(i,N)==1)
            {
                if(k==0)
                {
                    res+=i;
                    break;
                }
                else k--;
            }
        }
        printf("%d\n",res);
    }
    //  system("pause");
    return 0;
}
