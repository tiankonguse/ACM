#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
int edges[18][2]={
    {1,2},{1,3},{2,3},{2,4},{2,5},{3,5},{3,6},{4,5},{5,6},
    {4,7},{4,8},{5,8},{5,9},{6,9},{6,10},{7,8},{8,9},{9,10}
};
bool edges_mark[11][11];
int tris[10][3]={
    {1,2,3},{2,4,5},{2,3,5},
    {3,5,6},{4,7,8},{4,5,8},
    {5,8,9},{5,6,9},{6,9,10}
};
int tris_mark[11][11][11];


bool dfs(int p,int d){
  //  cout<<d<<endl;//system("pause");
    if(d==18){
        int ca=0,cb=0;
        for(int j=0;j<9;j++){
            int st=tris_mark[tris[j][0]][tris[j][1]][tris[j][2]];
            if(st==0)ca++;
        }
        cb=9-ca;
        if((p==0 && ca>=5) || (p==1 && cb>=5))return true;
        else return false;
    }
    //bool flag=false;
    for(int i=0;i<18;i++){
        if(edges_mark[edges[i][0]][edges[i][1]])continue;
        edges_mark[edges[i][0]][edges[i][1]]=true;
        int t[2],cnt=0;
        for(int j=0;j<9;j++){
            if(edges_mark[tris[j][0]][tris[j][1]] &&
               edges_mark[tris[j][1]][tris[j][2]] &&
               edges_mark[tris[j][0]][tris[j][2]] &&
               tris_mark[tris[j][0]][tris[j][1]][tris[j][2]] == -1)
            {
               tris_mark[tris[j][0]][tris[j][1]][tris[j][2]]=p;
               t[cnt++]=j;
            }
        }

        //if(p==0)cout<<i<<endl;
        if(cnt!=0){
            //flag=true;
           // cout<<p<<" "<<d<<":"<<edges[i][0]<<","<<edges[i][1]<<endl;
            if(dfs(p,d+1)){
              //  printf("%d,%d:%d\n",p,d,i);
                tris_mark[tris[t[0]][0]][tris[t[0]][1]][tris[t[0]][2]]=-1;
                if(cnt==2) tris_mark[tris[t[1]][0]][tris[t[1]][1]][tris[t[1]][2]]=-1;
                edges_mark[edges[i][0]][edges[i][1]]=false;

                return true;
            }
            tris_mark[tris[t[0]][0]][tris[t[0]][1]][tris[t[0]][2]]=-1;
            if(cnt==2) tris_mark[tris[t[1]][0]][tris[t[1]][1]][tris[t[1]][2]]=-1;
        }
        else{
            if(!dfs(p^1,d+1)){
              //  printf("%d,%d:%d\n",p,d,i);
                edges_mark[edges[i][0]][edges[i][1]]=false;
                return true;
            }
        }
        edges_mark[edges[i][0]][edges[i][1]]=false;
    }
    return false;
}

int main(){
    int T,N,a,b;
    scanf("%d",&T);
    for(int game=1;game<=T;game++){
        scanf("%d",&N);
        memset(edges_mark,false,sizeof(edges_mark));
        memset(tris_mark,0xff,sizeof(tris_mark));
        int ca=0,cb=0,p=0;
        bool flag=false;
        for(int i=0;i<N;i++){
            scanf("%d%d",&a,&b);
            flag=false;
            edges_mark[a][b]=true;
            for(int j=0;j<9;j++){
                if(edges_mark[tris[j][0]][tris[j][1]] &&
                   edges_mark[tris[j][1]][tris[j][2]] &&
                   edges_mark[tris[j][0]][tris[j][2]] &&
                   tris_mark[tris[j][0]][tris[j][1]][tris[j][2]] == -1)
                   {
                        if(p==0){
                            tris_mark[tris[j][0]][tris[j][1]][tris[j][2]]=0;
                            ca++;
                        }
                        else{
                            tris_mark[tris[j][0]][tris[j][1]][tris[j][2]]=1;
                            cb++;
                        }
                        flag=true;
                   }
            }
            if(!flag)p^=1;
        }
        bool ans=dfs(p,N);
        if((ans && p==0) || (!ans && p==1)){
            printf("Game %d: A wins.\n",game);
        }
        else{
            printf("Game %d: B wins.\n",game);
        }
    }
    return 0;
}
