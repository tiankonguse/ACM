#include"iostream"
bool used[5000000];
int rec[500001]={0};
using namespace std;
int fun(int m){
    if(rec[m-1]-m>0 && !used[rec[m-1]-m]){
       used[rec[m-1]-m]=true;
       return rec[m-1]-m;
    }
    else{
        used[rec[m-1]+m]=true;
         return rec[m-1]+m;
    }
}
int main(){
    int a;
    for(int i=1;i<=500000;i++)rec[i]=fun(i);
    while(scanf("%d",&a)){
       if(a==-1)break;
       else printf("%d\n",rec[a]);
    }
    return 0;
}
