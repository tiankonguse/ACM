#include"iostream"
#include"cstdlib"
using namespace std;
int main(){
    bool a[200];
    int t,p=0,cnt;
    memset(a,false,sizeof(a));
    while(scanf("%d",&t)){
       if(t==-1)break;
       if(t==0){
           cnt=0;
           for(int i=0;i<100;i++){
              if(a[i]==true && a[i*2]==true)cnt++;
           }
           printf("%d\n",cnt);
           memset(a,false,sizeof(a));
       }
       else{
          a[t]=true;
       }
    }
    return 0;
}
