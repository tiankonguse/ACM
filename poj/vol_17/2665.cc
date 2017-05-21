#include"iostream"
using namespace std;
int main(){
    int res,L,M,S,E;
    while(scanf("%d%d",&L,&M)){
        if(L==0 && M==0)break;
        res=L+1;
        for(int i=0;i<M;i++){
            scanf("%d%d",&S,&E);
            res-=(E-S+1);
        }
        printf("%d\n",res);
    }
    return 0;
}
