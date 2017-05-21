#include"iostream"
using namespace std;
int ps[101][101];
char cs[101];
int main(){
    int N,K,m;
    bool flag,f2;
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++){
        scanf("%d",&m);
        m*=2;
        ps[i][0]=m;
        for(int j=1;j<=m;j++){
           scanf("%d",&ps[i][j]);
        }
        scanf(" %c",&cs[i]);
    }
    int i,high,low,num=0,dt=0;
    for(i=1;i<=N;i++){
        flag=false;
        high=K,low=K;
        for(int j=0;j<K;j++){
            f2=false;
            for(int l=1;l<=ps[j][0];l++){
                if(i==ps[j][l]){
                   f2=true;
                   if(cs[j]=='='){
                      flag=true;
                      break;
                   }
                   else if(cs[j]=='>'){
                      if(l<=ps[j][0]/2){
                         high--;
                         break;
                      }
                      else{low--;break;}
                   }
                   else{
                       if(l<=ps[j][0]/2){
                          low--;
                          break;
                       }
                       else{high--;break;}
                   }
                }
                
                
            }
            if(flag)break;
            if((!f2) && cs[j]=='='){high--;low--;}
        }
        if(high==0 || low==0){
             if(num==1){dt=0;break;}
             dt=i;
             num=1;
        }
    }
    printf("%d\n",dt);
    //system("pause");
    return 0;
}
