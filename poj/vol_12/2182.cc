#include"iostream"
#include"cstdlib"
using namespace std;
int a[8001];
bool num[8001];
int main(){
    int N,p,cnt,j;
    scanf("%d",&N);
    for(int i=N-2;i>=0;i--)scanf("%d",&a[i]);
    for(int i=0;i<N-1;i++){
        cnt=0;
        for(j=1;j<=N;j++){
           if(cnt==a[i])break;
           if(!num[j])cnt++;
        }
        while(num[j])j++;
        a[i]=j;
        num[j]=true;
    }
    j=1;
    while(num[j])j++;
    printf("%d\n",j);
    for(int i=N-2;i>=0;i--)printf("%d\n",a[i]);
 //   system("pause");
    return 0;
}
