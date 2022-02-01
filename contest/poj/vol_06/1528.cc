#include"iostream"
using namespace std;
int check(int a){
    int sum=1;
    for(int i=2;i*i<=a;i++){
            if(a%i==0){
               sum+=i;
               if(i!=a/i)
               sum+=a/i;
            }
    }
    if(sum==a)return 1;
    if(sum<a)return 2;
    if(sum>a)return 3;
}
int main(){
    int a;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>a){
        if(a==0){
                 cout<<"END OF OUTPUT"<<endl;
                 break;
        }
        if(a==1){
             printf("%5d  DEFICIENT\n",a);
        }
        else if(check(a)==1){
             printf("%5d  PERFECT\n",a);
        }
        else if(check(a)==2){
             printf("%5d  DEFICIENT\n",a);
        }
        else{
             printf("%5d  ABUNDANT\n",a);
        }
    }
    return 0;
}
