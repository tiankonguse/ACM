#include"iostream"
#include"cmath"
using namespace std;
double pi=3.1415926535;
int main(){
    int M,flag;
    double l,w,el,ew,elt,ewt,t;
    cin>>M;
    for(int i=0;i<M;i++){
            cin>>l>>w>>el>>ew;
            flag=1;
            if(l<w){
                    t=l;
                    l=w;
                    w=t;
            }
            if(el<ew){
                    t=el;
                    el=ew;
                    ew=t;
            }
            if(el<l && ew<w){
                     cout<<"Escape is possible."<<endl;
                     continue;
            }
            else if(el*ew>=l*w){
                     cout<<"Box cannot be dropped."<<endl;
            }
            else{
                 for(double a=0;a<=45;a+=0.2){
                            t=a*pi/180;
                            elt=el*cos(t)+ew*sin(t);
                            ewt=el*sin(t)+ew*cos(t);
                        //    cout<<"a="<<a<<",t="<<t<<endl<<elt<<endl<<ewt<<endl<<endl;
                            if(elt<l && ewt<w){
                                flag=0;
                                cout<<"Escape is possible."<<endl;
                                break;
                            }
                 }
                 if(flag)  cout<<"Box cannot be dropped."<<endl;
            }
    }
    return 0;
}
