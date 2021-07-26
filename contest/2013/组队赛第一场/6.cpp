/*************************************************************************
    > File Name: 6.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/1 18:45:55
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
const int N=55;
int str[N];

const int INF = 2010000;
bool myfind[INF];
int num[INF];


int main() {
    int k,n,i,j,now;

    while(~scanf("%d%d",&k,&n)){
        for(i=1;i<=n;i++){
            scanf("%d",&str[i]);
        }
//        sort(str+1,str+n+1);
        memset(myfind,false,sizeof(myfind));
        memset(num,0,sizeof(num));

        for(i=1;i<=n;i++){
            myfind[str[i]] = true;
            num[str[i]] = 1;
            //printf("%d->%d\n",i,str[i]);
        }

        for(i=1;;++i){
            if(!myfind[i])break;
            for(j=1;j<=n;j++){
                if(num[i] +1 > k)continue;
                now = i + str[j];
//                cout<<"->"<<now<<endl;
                if(now >= INF)continue;

                if(myfind[now]){
                    if(num[i] +1 < num[now]){
                        num[now] = num[i] +1;
                    }
                }else{

                    myfind[now] = true;
                    num[now] = num[i] +1;
                }
            }
        }
        printf("%d\n",i-1);
    }

    return 0;
}
