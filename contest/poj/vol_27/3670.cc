#include"iostream"
#define inf 0x3f3f3f3f
using namespace std;
int a[30001],dpm[4],dpn[4];
int main(){
    int N,max,min;
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",a+i);
    for(int i=0;i<N;i++){
        max=0;
        for(int j=1;j<=a[i];j++){
           if(dpm[j]>max)max=dpm[j];
        }
        dpm[a[i]]=max+1;
        max=0;
        for(int j=3;j>=a[i];j--){
           if(dpn[j]>max)max=dpn[j];
        }
        dpn[a[i]]=max+1;
    }
    max=0;
    for(int i=1;i<=3;i++){
        if(dpm[i]>max)max=dpm[i];
        if(dpn[i]>max)max=dpn[i];
    }
    printf("%d\n",N-max);
   // system("pause");
    return 0;
}
