#include"iostream"
#include"cstdio"
#define MAXM 5
using namespace std;
int data[4][4]={{0,0,0,0},{0,1,2,3},{0,2,3,1},{0,3,1,2}};
int md[MAXM]={2,4,16,256,65536};
int nim_mul(int x,int y){
    if(x<y)return nim_mul(y,x);
    if(x<4)return data[x][y];
    int a,M,p,q,s,t,c1,c2,c3;
    for(a=0;a<MAXM;a++){
        if(md[a]>x)break;
    }
    a--;
    M=md[a];
    p=x/M;q=x%M;
    s=y/M;t=y%M;
    c1=nim_mul(p,s);
    c2=nim_mul(p,t)^nim_mul(q,s);
    c3=nim_mul(q,t);
    return M*(c1^c2)^c3^nim_mul(M/2,c1);
}
int main(){
    int N,x,y,z,r,s;
    while(~scanf("%d",&N)){
        r=0;
        for(int i=0;i<N;i++){
            scanf("%d%d%d",&x,&y,&z);
            s=1;
            s=nim_mul(s,nim_mul(x,y));
            s=nim_mul(s,nim_mul(x,z));
            s=nim_mul(s,nim_mul(y,z));
            r^=s;
        }
        if(r==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


