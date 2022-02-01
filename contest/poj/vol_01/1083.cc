#include"iostream"
using namespace std;
int rs[201];
int main(){
    //freopen("table.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,N,a,b,sum,max,t;
    scanf("%d",&T);
    while(T--){
        memset(rs,0,sizeof(rs));
        scanf("%d",&N);
        while(N--){
           scanf("%d%d",&a,&b);
           a=(a-1)/2;
           b=(b-1)/2;
           if(b<a){t=a;a=b;b=t;}
           for(int i=a;i<=b;i++)rs[i]++;
        }
        max=0;
        for(int i=0;i<200;i++){
           if(rs[i]>max)max=rs[i];
        }
        printf("%d\n",max*10);
    }
   // system("pause");
    return 0;
}
