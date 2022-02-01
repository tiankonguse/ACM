#include"iostream"
using namespace std;
int main(){
    int c,m,n;
    double t;
    cin>>c;
    for(int i=0;i<c;i++){
            cin>>m>>n;
            if(m*n%2==0)t=m*n;
            else t=0.41+m*n;
            printf("Scenario #%d:\n%.2f\n\n",i+1,t);
    }
    return 0;
}
