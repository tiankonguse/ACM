#include"iostream"
#include"algorithm"
using namespace std;
int num[11],tmp[11];
int cal(int N){
    memcpy(tmp,num,sizeof(num));
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            tmp[j]=tmp[j]+tmp[j+1];
        }
    }
    return tmp[0];
}
int main(){
    int N,S;
    scanf("%d%d",&N,&S);
    for(int i=1;i<=N;i++)num[i-1]=i;
    while(cal(N)!=S){
         next_permutation(num,num+N);
    }
    for(int i=0;i<N;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
  //  system("pause");
    return 0;
}
