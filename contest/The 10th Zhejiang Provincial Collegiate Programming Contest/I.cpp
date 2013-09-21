#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>
const int N = 3010000;
#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;
char sum[N];
int str[N];

int _get(int a)
{
    int i=0;
    while(a)
    {
        str[i++] = a&1;
        a>>=1;
    }
    return i;
}


void fun(int len)
{
    int now=0;
    int s,a,b,i;
//    printf("--%d\n",len);
    if(len == 0){
        printf("00");
        return ;
    }
    int num = _get(len);
//    for(i=0; i<num; i++)
//    {
//        printf("%d",str[i]);
//    }
//    puts("");
    s=0;
    now=0;
    for(i=now; i<num;)
    {
        if(i+7>=num)
        {
            a = str[i] + str[i+1]*2 + str[i+2]*4 + str[i+3]*8;
            b = str[i+4] + str[i+1+4]*2 + str[i+2+4]*4 + 0;
            printf("%0X%0X",b,a);
            break;
        }
        else
        {
            a = str[i] + str[i+1]*2 + str[i+2]*4 + str[i+3]*8;
            b = str[i+4] + str[i+1+4]*2 + str[i+2+4]*4 + 8;
            printf("%0X%0X",b,a);
            i+=7;
        }




    }

}

int main()
{

    int n,m,k,from,to;
    int cas,ans,j,now,kk;
    char c;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
        gets(sum);
        int len = strlen(sum);
        memset(str,0,sizeof(str));
        fun(len);
//        puts("");
        for(int i=0; i<len; i++)
        {
            printf("%0X",sum[i]);
        }
        puts("");

    }

    return 0;
}
