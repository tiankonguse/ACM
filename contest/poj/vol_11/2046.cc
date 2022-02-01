#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;
struct sta{
    char state[4][8];
    friend bool operator<(sta a,sta b){
        for(int i=0;i<4;i++){
            for(int j=0;j<8;j++){
                if(a.state[i][j]!=b.state[i][j])
                return a.state[i][j]<b.state[i][j];
            }
        }
        return false;
    }
};

set<sta>hs;
struct node{
    int t;
    char x[4],y[4];
    sta stat;
    node(int tt,char xt[4],char yt[4],char st[4][8]){
        t=tt;
        for(int i=0;i<4;i++){
            x[i]=xt[i];
            y[i]=yt[i];
            for(int j=0;j<8;j++){
                stat.state[i][j]=st[i][j];
            }
        }
    }
    node(){}
}q[200005],t;

void print(char state[4][8]){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            printf("%d ",state[i][j]);
        }
        printf("\n");
    }
}
bool judge(sta s){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=7;j++){
            if(s.state[i-1][j-1]!=i*10+j)return false;
        }
    }
    return true;
}
int bfs(node s){
   /* for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            printf("%d ",s.state[i][j]);
        }
        printf("\n");
    }*/
    if(judge(s.stat))return 0;
    hs.clear();

    hs.insert(s.stat);
    int l=0,h=1,num,tx,ty,px,py;
    q[0]=s;
    while(l<h){
        t=q[l++];
        for(int i=0;i<4;i++){
            node tt=t;
            tx=tt.x[i];
            ty=tt.y[i];
            num=tt.stat.state[tx][ty-1]+1;
            if(num%10==8)continue;
            px=py=-1;
            for(int j=0;j<4;j++){
                for(int k=1;k<8;k++){
                    if(tt.stat.state[j][k]==num){
                        px=j;
                        py=k;
                        break;
                    }
                }
                if(px!=-1)break;
            }
            if(px!=-1){
                tt.stat.state[tx][ty]=num;
                tt.stat.state[px][py]=0;
                tt.x[i]=px;
                tt.y[i]=py;
                tt.t++;
                if(judge(tt.stat))return tt.t;
                if(hs.find(tt.stat)==hs.end()){
                //   print(tt.state);system("pause");

                    hs.insert(tt.stat);
                    q[h++]=tt;
                }
            }
        }
    }
    return -1;
}

char map[4][8];
int main(){
    int T;
    char x[4],y[4];
    scanf("%d",&T);
    while(T--){

        int ct=0;
        for(int i=0;i<4;i++){
            for(int j=1;j<=7;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]%10==1){
                    x[ct]=i;
                    y[ct]=j;
                    ct++;
                    map[i][j]=0;
                }
            }
        }
        map[0][0]=11;
        map[1][0]=21;
        map[2][0]=31;
        map[3][0]=41;
        node s(0,x,y,map);
        printf("%d\n",bfs(s));
    }
    return 0;
}
