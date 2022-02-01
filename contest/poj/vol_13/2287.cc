#include"iostream"
#include"cstdlib"
#include"algorithm"
using namespace std;
int a[1001],b[1001];
bool aa[1001],bb[1001];
int main(){
    int T;
    while(scanf("%d",&T)&&T){
        memset(aa,false,sizeof(aa));
        memset(bb,false,sizeof(bb));
        for(int i=0;i<T;i++)scanf("%d",&a[i]);
        for(int i=0;i<T;i++)scanf("%d",&b[i]);
        sort(a,a+T);
        sort(b,b+T);
        int cnt=0,cnt1=0;
        for(int i=0;i<T;i++){
            for(int j=T-1;j>=0;j--){
                if(!aa[i] && !bb[j] && a[i]>b[j]){
                    cnt++;
                    aa[i]=true;
                    bb[j]=true;
                } 
            }
        }
        for(int i=0;i<T;i++){
            for(int j=0;j<T;j++){
                if(!aa[i] && !bb[j] && a[i]==b[j]){
                    cnt1++;
                    aa[i]=true;
                    bb[j]=true;
                } 
            }
        }
        printf("%d\n",(cnt-(T-cnt-cnt1))*200);
    }
    return 0;
}
