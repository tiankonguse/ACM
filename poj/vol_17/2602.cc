#include"iostream"
#include"cstdio"
using namespace std;
char a[1000001],b[1000001],c[1000001];
int main(){
    int N;
    scanf("%d",&N);
    getchar();
    for(int i=1;i<=N;i++){
        a[i]=getchar();getchar();
        b[i]=getchar();getchar();
    }
    char p=0;
    for(int i=N;i>=1;i--){
        c[i]=a[i]-48+b[i]+p;
        if(c[i]-48>9){
           c[i]-=10;
           p=1;
        }
        else p=0;
    }
    for(int i=1;i<=N;i++)putchar(c[i]);
    printf("\n");
 //   system("pause");
    return 0;
}
