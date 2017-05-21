#include"iostream"
#define type __int64
using namespace std;
type Extended_Euclid(type a,type b,type *x,type *y){
    if(b==0){
             *x=1;
             *y=0;
             return a;
    }
    type d=Extended_Euclid(b,a%b,x,y);
    type t=*x;
    *x=*y;
    *y=t-a/b*(*y);
    return d;                
}
type Modular_Linear_Equation_Solver(type a,type b,type n){
    type d,x,y;
    d=Extended_Euclid(a,n,&x,&y);
    type x0;
    if(b%d==0){
               x0=(x*b/d)%n;
    }
    else return -1;
    return x0>=0?x0:x0+n;
}
int main(){
    type X,Y,M,N,L,r;
    while(cin>>X>>Y>>M>>N>>L){
         r=Modular_Linear_Equation_Solver(M-N,Y-X,L);
         if(r==-1)cout<<"Impossible"<<endl;
         else cout<<r<<endl;
    }      
    return 0;
}
