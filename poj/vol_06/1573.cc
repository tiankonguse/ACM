#include"iostream"
using namespace std;
/*typedef struct TYPE{
       int x,y;
}alpha;*/
int main(){
  //  alpha alp[10];
    int alpx[100],alpy[100];
    char ch[10][10];
    int n,m,s;
    while(cin>>n>>m>>s){
                     if(n==0 && m==0 && s==0){
       
                          return 0;//  break;
                     }
                     else{
                         for(int i=0;i<n;i++){
                                 for(int j=0;j<m;j++){
                                         scanf(" %c",&ch[i][j]);
                                     //   cin>>ch[i][j];
                                 }
                         }
                         int q=0,ck=0,f=-1;
                         s--;
                         while(q!=-1 && q!=n && s!=-1 && s!=m){
                                     if(ck){
                                           f=-1;
                                             for(int i=0;i<ck;i++){
                                                if(s==alpx[i] && q==alpy[i]){
                                                               f=i;
                                                               break;
                                                } 
                                        }
                                        if(f!=-1) break;
                                     }
                                     alpx[ck]=s;
                                     alpy[ck]=q;
                                     ck++;
                                     switch(ch[q][s]){
                                        case 'W':s--;break;
                                        case 'E':s++;break;
                                        case 'S':q++;break;
                                        case 'N':q--;break; 
                                     }
                         }
                         if(f!=-1){
                               cout<<f<<" step(s) before a loop of "<<ck-f<<" step(s)"<<endl;
                         }
                         else
                         cout<<ck<<" step(s) to exit"<<endl;
                     }
    }
    return 0;
}
