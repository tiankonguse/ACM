#include"iostream"
#include"algorithm"
using namespace std;
int main(){
    int N,sum;
    int a[200];
    while(scanf("%d",&N)&&N){
        sum=0;
        for(int i=0;i<N;i++){
           scanf("%d",&a[i]);
           sum+=a[i];
        }
        printf("%d\n",(sum-*max_element(a,a+N)-*min_element(a,a+N))/(N-2));
    }
    return 0;
}
