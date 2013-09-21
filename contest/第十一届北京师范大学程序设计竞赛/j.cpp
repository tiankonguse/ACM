/*************************************************************************
    > File Name: j.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 13:54:45
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
deque<int>deq0;
const int N = 10010;
int c,n,ai[N];
inline int _max(int a,int b){
    return a>b?a:b;
}
int find(int left,int right,int cc){
    if(left >= right)return cc;
    int ans = cc,pos,i;
    while(!deq0.empty())deq0.pop_back();

    deq0.push_front(right);
    for(i=right-1;i>=left;i--){
        pos = deq0.front();
        if(ai[pos] <= ai[i]){
            deq0.push_front(i);
        }
    }

    for(i=left;i<right;i++){
        if(i == deq0.front()){
            deq0.pop_front();
            continue;
        }
        if(ai[i] <= cc){
            ans = _max(ans, cc + ai[deq0.front()] - ai[i]);
        }
    }
    return ans;
}

int fun(int mid){
    int ans = c;
    ans = find(0,mid,ans);
    ans = find(mid+1,n-1,ans);
    return ans;
}




int main() {
    int i,j,k,pos,tmp;

    scanf("%d%d",&c,&n);
    for(i=0;i<n;i++){
        scanf("%d",&ai[i]);
    }

    int ans = c;

    for(i=1;i<n;i++){
        ans = _max(ans,fun(i));
    }

    printf("%d\n",ans);



    return 0;
}
