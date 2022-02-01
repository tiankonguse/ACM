#include"iostream"
#include"algorithm"
using namespace std;
int a[100001];
int main(){
    int N,l,cnt=0;
    scanf("%d%d",&N,&l);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }   
    sort(a,a+N);
    int low=0,high=N-1;
    while(low<=high){
       if(a[high]+a[low]<=l)low++;
       high--;
       cnt++;
    }
    printf("%d\n",cnt);
    //system("pause");
    return 0;
}
