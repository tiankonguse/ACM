//CODING BY ZXZ 2010.5.13
#include"iostream"
#include"cmath"
using namespace std;
bool ispri[1001];
int pri[1001];
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
    GetPri(1001);
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        if(ispri[N])printf("%d\n",2+N*4);
        else
        {
            int i,tmp=N,tmp2,min=3000,tx=0,ty=0,tz=0;
            bool flag=false;
            for(i=1; i<=N; i++)
            {
                tmp=N;
                if(tmp%i==0)
                {
                    tmp/=i;
                    //  if(ispri[i] && ispri[tmp]){flag=true;break;}
                    for(int j=1; j<=tmp; j++)
                    {
                        tmp2=tmp;
                        if(tmp2%j==0)
                        {
                            tmp2/=j;
                            if(i+j+tmp2<min)
                            {
                                min=i+j+tmp2;
                                tx=i;
                                ty=j;
                                tz=tmp2;
                            }
                        }
                    }
                }
            }
            //cout<<tx<<endl<<ty<<endl<<tz<<endl;
            //if(flag)printf("%d\n",2*pri[i]*tmp+2*(pri[i]+tmp));
            printf("%d\n",2*tx*ty+2*ty*tz+2*tx*tz);
        }
    }
    return 0;
}
