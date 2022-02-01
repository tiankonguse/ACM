#include"iostream"
#include"algorithm"
using namespace std;
int main(){
    int flag=true;
    int a,b,n,num,max=1;
    while(cin>>a>>b){
       flag=false;
       if(a>b){swap(a,b);flag=true;}
        max=0;
        for(int i=a;i<=b;i++){
            n=i;
            num=1;
            while(n!=1){
              if(n%2==1)n=3*n+1;
              else n/=2;
              num++;
            }
            if(num>max)max=num;
        }
        if(flag)swap(a,b);
        cout<<a<<" "<<b<<" "<<max<<endl;
    }
    return 0;
}
