#include"iostream"
using namespace std;
int main(){
    int T,y,m,d;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
            scanf("%d%d%d",&y,&m,&d);
            if((m+d)%2==0 ||(d==30 &&(m==11 || m==9))){
                          printf("YES\n");
            }
            else printf("NO\n");
    }
    return 0;
}
