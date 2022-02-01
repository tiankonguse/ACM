#include"iostream"
#include"string"
#define typec __int64
using namespace std;
int dir[10][2]={{0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};
typec cross(typec x1,typec y1,typec x2, typec y2){
    return x1*y2-x2*y1;
}
int main(){
    int T,len;
    typec sum,x1,y1,x2,y2;
    char str[1000001];
    scanf("%d",&T);
    getchar();
    while(T--){
        gets(str);
        len=strlen(str);
        sum=x1=y1=0;
        for(int i=0;i<len;i++){
            x2=x1+dir[str[i]-'0'][0];
            y2=y1+dir[str[i]-'0'][1];
            sum+=cross(x1,y1,x2,y2);
            x1=x2;
            y1=y2;
        }
        sum+=cross(0,0,x1,y1);
        sum=sum>0?sum:-sum;
        if(sum&1){
            printf("%I64d.5\n",sum>>1);
        }
        else printf("%I64d\n",sum>>1);
    }
   //system("pause");
    return 0;
}
