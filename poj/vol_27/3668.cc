#include"iostream"
#include"set"
using namespace std;
struct points{
   double x,y;
}p[201];
set<double>hash;
int main(){
    int N,cnt=0;
    double k;
    bool flag=false;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            k=p[i].x-p[j].x;
            if(k==0){
                 if(!flag){
                     cnt++;
                     flag=true;
                 }
            }
            else{
                k=(p[i].y-p[j].y)/k;
                if(hash.find(k)==hash.end()){
                    cnt++;
                    hash.insert(k);
                }
            }
        }
    }
    printf("%d\n",cnt);
   // system("pause");
    return 0;
}
