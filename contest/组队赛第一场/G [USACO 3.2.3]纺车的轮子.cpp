#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define mem(a,b)  memset(a,b,sizeof(a)

struct array
{
    int v,num;
    int x[6],y[6];
}s[6];
int main()
{
    int i,j;
    for(i=1;i<=5;i++)
    {
        //scanf("%d%d",&s[i].v,&s[i].num);
        cin>>s[i].v>>s[i].num;
        for(j=1;j<=s[i].num;j++)
        {
            cin>>s[i].x[j]>>s[i].y[j];
            //scanf("%d%d",&s[i].x[j],&s[i].y[j]),(s[i].y[j]+=s[i].x[j])%=360;
            (s[i].y[j]+=s[i].x[j])%=360;
        }
          //
    }
    int ans=0;
    for(i=0;i<=359&&ans==0;i++)
    {
        for(j=0;j<=359;j++)
        {
            int flag=0;
            for(int k=1;k<=5;k++)
            {
                int v1 = s[k].v*i;
                for(int t=1;t<=s[k].num;t++)
                {
                    int a = (v1+s[k].x[t])%360;
                    int b = (v1+s[k].y[t])%360;
                    if(b<a)
                    {
                        if((j>=a&&j<=359)||(j>=0&&j<=b))flag++;
                    }
                    else if(j>=a&&j<=b)flag++;
                }
            }
            if(flag==5){cout<<i<<endl;ans=1;break;}
        }

    }if(ans==0)cout<<"none"<<endl;
}
