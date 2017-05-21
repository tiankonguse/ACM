#include"iostream"
#include"cmath"
using namespace std;
struct EQ{
       double a,b,c;
};
double R=20000.0/acos(-1.0);
int main(){
    EQ equ[100];
    int k,m;
    double x,y,z;
    while(cin>>k>>m){
        if(k==0 && m==0)break;
        int count=0;
        for(int i=0;i<k;i++){
                cin>>x>>y>>z;
                equ[i].a=x;
                equ[i].b=y;
                equ[i].c=z;
        }
        for(int i=0;i<m;i++){
                cin>>x>>y>>z;
                for(int j=0;j<k;j++){
                        if(equ[j].a*x+equ[j].b*y+equ[j].c*z-R*R>=0){
                           count++;
                           break;
                        }
                }
        }
        cout<<count<<endl;
    }
    return 0;
}
