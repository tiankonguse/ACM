#include"iostream"
#include"cstdlib"
#define MAXP 1300010
using namespace std;
int pri[100500];
int pri_cnt;
bool isprime[MAXP];

void SetPri()
{
    memset(isprime,true,sizeof(isprime));
    int i,j;
    for(i = 3 ; i <= 1141 ; i += 2 )
    {
        for(j = 3 ; j <= MAXP / i ; j += 2)
        {
            if(isprime[i])
            {
                isprime[i * j] = false;
            }
        }
    }
    for(i = 4 ; i <= MAXP ; i += 2 )
    {
        isprime[i] = false;
    }
    isprime[1] = isprime[0] = false;
}
void GetPri()
{
    int i;
    pri_cnt=0;
    for(i=2; i<=1299709; i++)
    {
        if(isprime[i])
            pri[pri_cnt++]=i;
    }
}
int search(int n)
{
    int l=0,h=pri_cnt-1,mid;
    while(l<=h)
    {
        mid=(l+h)>>1;
        if(n>pri[mid])l=mid+1;
        else h=mid-1;
    }
    return l;
}
int main()
{
    int N,p;
    SetPri();
    GetPri();
    while(scanf("%d",&N) && N)
    {
        if(N==1 || isprime[N])printf("0\n");
        else
        {
            p=search(N);
            printf("%d\n",pri[p]-pri[p-1]);
        }
    }
    return 0;
}
