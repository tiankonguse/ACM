#include"iostream"
using namespace std;
int main(){
    int p,e,i,d,c=0;
    int res;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)){
       if(p==-1 && e==-1 && i==-1 && d==-1)break;
            c++;       
            res=(5544*p+14421*e+1288*i-d+21252)%21252;
            if(res==0)printf("Case %d: the next triple peak occurs in 21252 days.\n",c);
            else printf("Case %d: the next triple peak occurs in %d days.\n",c,res);
       
    }
    return 0;
}
