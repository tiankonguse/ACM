#include"iostream"
#include"string.h"
#include"cstdlib"
#include"cstdio"
using namespace std;
int a[301];
bool used[1000000];
int main(){
    int T,N,d;
    bool flag;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%d",&a[i]);
        for(int k=N;;k++){
            flag=true;
            memset(used,false,k*sizeof(used[0]));
            for(int l=0;l<N;l++){
                d=a[l]%k;
                if(used[d]){
                    flag=false;
                    break;
                }
                else used[d]=true;
            }
            if(flag){
                printf("%d\n",k);
                break;
            }
        }
    }
   // system("pause");
    return 0;
}
