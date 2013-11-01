/*************************************************************************
    > File Name: 10881.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const int N = 10010;

struct T{
    int pos;
    int id;
    char op[3];
    bool operator<(const T o)const{
        return this->pos < o.pos;
    }
}first[N];

int idx[N];

int main() {
    int cas,l,t,n;
    scanf("%d",&cas);

    for(int ca=1;ca<=cas;ca++){
        scanf("%d%d%d",&l,&t,&n);
        first[n+1].pos = l+10;
        for(int i=1;i<=n;i++){
            scanf("%d %s",&first[i].pos,first[i].op);
            first[i].id = i;
        }

        sort(first+1, first+n+1);

        for(int i=1;i<=n;i++){
            idx[first[i].id] = i;
            if(first[i].op[0] == 'R'){
                first[i].pos += t;
            }else{
                first[i].pos -= t;
            }
        }

        sort(first+1, first+n+1);

        printf("Case #%d:\n",ca);
        for(int i=1;i<=n;i++){
            int id = idx[i];
            if(first[id].pos < 0 || first[id].pos > l){
                printf("Fell off\n");
            }else if(first[id].pos == first[id-1].pos || first[id].pos == first[id+1].pos){
                printf("%d Turning\n",first[id].pos);
            }else{
                printf("%d %s\n",first[id].pos,first[id].op);
            }
        }
        puts("");
    }

    return 0;
}
