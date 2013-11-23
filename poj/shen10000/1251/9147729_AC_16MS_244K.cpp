#include <iostream>
using namespace std;
#define INF 5000

int cps[300][300];

int minL[300];

int main(){
    int n,m,x,y,l;
    char c;
    while(cin>>n,n)
    {

        for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            cps[i][j]=cps[j][i]=INF;
        }

        for(int i=1;i<n;i++)
        {   
            cin>>c>>m;
            x=c-'A'+1;
            while(m--)
            {
				cin>>c>>l;
                y=c-'A'+1;
                if(cps[x][y]>l)
                    cps[x][y]=cps[y][x]=l;
            }            
        }
                

        for(int i=2;i<=n;i++)minL[i]=cps[1][i];

        int ans=0,ggg=0;;        
        minL[1]=-1;
        int lst=1;
        while(1)
        {
            int min=INF,mini;
            
            for(int i=1;i<=n;i++)
                if(min>minL[i]&&minL[i]!=-1)
                    min=minL[i],mini=i;
    
            if(min==INF)break;
            ans+=min;
            minL[mini]=-1;
            for(int i=1;i<=n;i++)
                if(minL[i]>cps[mini][i])
                    minL[i]=cps[mini][i];
        }
             printf("%d\n",ans);
    }
    return 0;
}
