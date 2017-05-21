#include"iostream"
using namespace std;
int circle(int *a,int l,int *q){
    int t,p=1,c=0;
    while(p){
             c++;
             t=0;
            // for(int i=0;i<l;i++){cout<<a[i]<<endl;}
            for(int i=0;i<l;i++){
                   t=(a[i]-t)/2;
                   a[i]-=t;
                   if(i==l-1){
                      
                      a[0]+=t;
                    }
                   else{
                      a[i+1]+=t;
                    }
            }
            p=0;
            if(a[0]%2==1)a[0]++;
            for(int i=1;i<l;i++){
                    if(a[i]%2==1) a[i]++;
                    if(a[i]!=a[i-1])p=1;
            }
        //    cout<<"p="<<p<<endl;
        //cout<<"Q="<<a[0]<<endl;
    }
    *q=a[0];
    return c;
}
int main(){
    int N;
    while(cin>>N){
       if(N==0)break;
       int *a=new int[N];
       for(int i=0;i<N;i++){
               cin>>a[i];
       }           
       int p,q;
       p=circle(a,N,&q);
       cout<<p<<" "<<q<<endl;
    }
    return 0;
}
