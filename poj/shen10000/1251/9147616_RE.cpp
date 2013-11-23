#include <stdio.h>
#define INF 0x7fffffff

int cps[30][30];

int minL[30];

int main(){
    int n,m,x,y,l;
    while(scanf("%d",&n),n)
    {
        
        
            
        for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            cps[i][j]=cps[j][i]=INF;
        }

        for(int i=0;i<n-1;i++)
        {   
            getchar();
            char c=getchar();
            x=c-'A'+1;
            scanf("%d",&m);
            while(m--)
            {
                getchar();    
                scanf("%c%d",&c,&l);
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
