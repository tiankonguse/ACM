#include"iostream"
using namespace std;
int s[50];
int main(){
    int T,N,a;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        int l=0,p=0;
        for(int j=0;j<N;j++){
            scanf("%d",&a);
            while(a>l){
              s[p++]=-1;
              l++;
            } 
            s[p++]=1;
            int q=p-1,sum=1;
            while(sum!=0){
                sum+=s[--q];
            }
            if(j==N-1)printf("%d\n",(p-q)/2);
            else printf("%d ",(p-q)/2);
        }
        
    }
    return 0;
}
