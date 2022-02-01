#include"iostream"
#define MAXN 1030
using namespace std;
int num[MAXN][MAXN];
int lowbit(int x){
    return x&(-x);
}
void update1(int x,int y,int a){
    while(y<MAXN){
        num[x][y]+=a;
        y+=lowbit(y);
    }
}
void update(int x,int y,int a){
    while(x<MAXN){
        update1(x,y,a);
        x+=lowbit(x);
    }
}
int sum1(int x,int y){
    int s=0;
    while(y>0){
        s+=num[x][y];
        y-=lowbit(y);
    }
    return s;
}
int sum(int x,int y){
    int s=0;
    while(x>0){
        s+=sum1(x,y);
        x-=lowbit(x);
    }
    return s;
}

int main(){
    int p,s,x,y,a,l,b,r,t;
    while(scanf("%d",&p)){
        if(p==0){
             scanf("%d",&s);
             memset(num,0,sizeof(num));
        }
        else if(p==1){
             scanf("%d%d%d",&x,&y,&a);
             x++;y++;
             update(x,y,a);
        }
        else if(p==2){
             scanf("%d%d%d%d",&l,&b,&r,&t);
             l++;b++;r++;t++;
             printf("%d\n",sum(r,t)-sum(r,b-1)-sum(l-1,t)+sum(l-1,b-1));
        }
        else break;
    }
    return 0;
}
