#include"iostream"
using namespace std;
int main(){
    int T,s;
    int day,D[16];
    int a[20][20],b[20][20];
    char c;
    scanf("%d",&day);
            for(int j=0;j<16;j++){
                    scanf("%d",&D[j]);
            }
            for(int j=0;j<20;j++){
                    for(int k=0;k<20;k++){
                            scanf("%d",&a[j][k]);
                    }
            }
            for(int j=0;j<day;j++){
                    for(int k=0;k<20;k++){
                            for(int l=0;l<20;l++){
                                    s=a[k][l];
                                    if(k>0)s+=a[k-1][l];
                                    if(k<19)s+=a[k+1][l];
                                    if(l>0)s+=a[k][l-1];
                                    if(l<19)s+=a[k][l+1];
                                    b[k][l]=D[s];
                            }
                    }
                    for(int k=0;k<20;k++){
                            for(int l=0;l<20;l++){
                                    a[k][l]+=b[k][l];
                                    if(a[k][l]>3)a[k][l]=3;
                                    if(a[k][l]<0)a[k][l]=0;
                            }
                    }
                    
            }
             for(int k=0;k<20;k++){
                            for(int l=0;l<20;l++){
                             switch(a[k][l]){
                                case 0:c='.';break;
                                case 1:c='!';break;
                                case 2:c='X';break;
                                case 3:c='#';break;
                                default:break;
                             }
                             printf("%c",c);
                            }
                            printf("\n");
             }
    
   return 0;
}
