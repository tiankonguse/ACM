#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#define MAXN 2005
using namespace std;
set<pair<int,int> >s;
pair<int,int> coor[MAXN];
int main(){
    int N,x1,x2,y1,y2,x3,x4,y3,y4;
    while(~scanf("%d",&N)){
        s.clear();
        for(int i=0;i<N;i++){
            scanf("%d%d",&coor[i].first,&coor[i].second);
            s.insert(coor[i]);
        }
        int res=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                x1=coor[i].first;
                y1=coor[i].second;
                x2=coor[j].first;
                y2=coor[j].second;
              //  printf("(%d,%d),(%d,%d):",x1,y1,x2,y2);
              //  printf("(%d,%d),(%d,%d)\n",(x1+x2+y2-y1)/2,(x1-x2+y2+y1)/2,(x1+x2+y1-y2)/2,(x2-x1+y1+y2)/2);
                if((x1+x2-y1+y2)%2!=0)continue;else x3=(x1+x2-y1+y2)/2;
                if((x1-x2+y1+y2)%2!=0)continue;else y3=(x1-x2+y1+y2)/2;
                if((x1+x2+y1-y2)%2!=0)continue;else x4=(x1+x2+y1-y2)/2;
                if((-x1+x2+y1+y2)%2!=0)continue;else y4=(-x1+x2+y1+y2)/2;
                if(s.find(make_pair(x3,y3))!=s.end() && s.find(make_pair(x4,y4))!=s.end()){
                    res++;
                }
            }
        }
        printf("%d\n",res/2);
    }
    return 0;
}
