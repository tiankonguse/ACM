#include"iostream"
using namespace std;
int n1[101],n2[101];
int main(){
    int N,R,p,c;
    while(scanf("%d%d",&N,&R)&&N&&R){
        for(int i=N-1;i>=0;i--)n1[i]=N-i;
        for(int i=0;i<R;i++){
           scanf("%d%d",&p,&c);  
           p--;
           for(int j=0;j<c;j++)n2[j]=n1[p+j];
           for(int j=c+p-1;j>=c;j--)n1[j]=n1[j-c];
           for(int j=0;j<c;j++)n1[j]=n2[j];
        }
        printf("%d\n",n1[0]);
    }
    return 0;
}
