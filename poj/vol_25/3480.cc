#include"iostream"
using namespace std;
int main(){
    int T,N,a,t,c;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        t=0,c=0;
        for(int j=0;j<N;j++){
                scanf("%d",&a);
                if(a>1)c++;
                t^=a;        
        }
        if(t){
              if(c==0)
              printf("Brother\n");
              else
              printf("John\n");
        }
        else{
              if(c>=2)
              printf("Brother\n");
              else
              printf("John\n");
        }
    }
    return 0;
}
