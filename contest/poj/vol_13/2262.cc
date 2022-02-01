//CODING BY ZXZ 2010.5.13
#include"iostream"
#include"cmath"
#define MAXN 1000001
using namespace std;
bool ispri[MAXN];
int pri[MAXN];
int pri_cnt;
void SetPri(int n)
{
    memset(ispri,true,sizeof(ispri));
    int i,j;
    for(i=2; i<n; i++)
    {
        for(j=i<<1; j<n; j+=i)ispri[j]=false;
    }
}
void GetPri(int n)
{
    SetPri(n);
    int i;
    pri_cnt=0;
    for(i=2; i<n; i++)
    {
        if(ispri[i])pri[pri_cnt++]=i;
    }
}
int main()
{
    int N;
    GetPri(MAXN);
    bool flag=true;
    while(scanf("%d",&N)&&N)
    {
        for(int i=0; pri[i]<=N/2; i++)
        {
            if(ispri[N-pri[i]])
            {
                flag=false;
                printf("%d = %d + %d\n",N,pri[i],N-pri[i]);
                break;
            }
        }
        if(flag)printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
