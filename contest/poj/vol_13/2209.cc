#include"iostream"
using namespace std;
int main(){
    int N,e,a,s=0;
    scanf("%d%d",&N,&e);
    for(int i=0;i<N;i++){
       scanf("%d",&a);
       if(e==1 && a>0)s+=a;
       else if(e==2)s+=a*a;
       else if(e==3 && a>0)s+=a*a*a;
    }
    printf("%d\n",s);
    //system("pause");
    return 0;
}
