#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int M,N,t;
    int k1,k2,lp,rp,l1,l2,p1,p2,r1,r2,r;
    while(cin>>M>>N){
       if(M>N){
               t=M;
               M=N;
               N=t;
       }
 
       k1=(int)sqrt((double)M-1);
       k2=(int)sqrt((double)N-1);
       p1=M-(k1*k1);
       p2=N-(k2*k2);
       //cout<<k1<<endl<<k2<<endl;
       //cout<<p1<<endl<<p2<<endl;
       l1=k1*2+1;
       l2=k2*2+1;
       lp=(p1+1)/2*2;
       rp=(l2-(l1-p1))/2*2;
     //  cout<<lp<<endl<<rp<<endl;
       if(l1==l2){
             r=abs(p1-p2);
       }
       else if(p2>=lp&& p2<=rp){
               //    cout<<"yes"<<endl;
            if(p1%2==0) r=2;
            else r=1;
            if(p2%2==1) r++;
            r+=2*(k2-k1-1);
       }
       else{
           r1=abs(p2-lp);
           r2=abs(p2-rp);
           r=r1<r2?r1:r2;
           if(p1%2==0){
           r+=2*(k2-k1);
           }
           else{
                r+=2*(k2-k1)-1;
           }
       }
       cout<<r<<endl;
       
    }
    return 0;
}
