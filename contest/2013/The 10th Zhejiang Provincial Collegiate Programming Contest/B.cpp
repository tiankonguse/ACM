#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>

#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;
int str[111][111];
bool sum[500];

int _find_1(int a){
    if(a>0 && sum[a]){
        sum[a]=false;
        return 1;
    }
    return 0;
}
int _find_2(int a,int b){

    int a_add_b = a+b;
    int a_b = a-b;
    int b_a = b-a;
    int _b_a = -b-a;
    int ans = 0;

    ans += _find_1(a_add_b);
    ans += _find_1(b_a);
    ans += _find_1(a_b);
    ans += _find_1(_b_a);

    return ans ;
}

int _find_3(int a,int b,int c){
    int a_add_b = a+b;
    int a_b = a-b;
    int b_a = b-a;
    int _a_b = -a-b;
    int ans = 0;

    ans += _find_2(a_add_b,c);
    ans += _find_2(a_b,c);
    ans += _find_2(b_a,c);
    ans += _find_2(_a_b,c);
    return ans;
}

int _find(int a,int b,int c){
    int ans = 0;
    ans += _find_1(a);
    ans += _find_1(b);
    ans += _find_1(c);

    ans += _find_2(a,b);
    ans += _find_2(a,c);
    ans += _find_2(c,b);

    ans += _find_3(a,b,c);
    ans += _find_3(a,c,b);
    ans += _find_3(b,c,a);

    return ans;

}

int main(){

    int n,m,i;
    int cas,ans,tmp;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        if(n==1 && m==1){
            ans = 2;
        }else{
            ans = 0;
        }



        for(i=1;i<n;i++){
            memset(sum,true,sizeof(sum));
            ans = max(ans,_find(i,n-i,m));
        }
         for(i=1;i<m;i++){
             memset(sum,true,sizeof(sum));
            ans = max(ans,_find(i,m-i,n));
        }
        printf("%d\n",ans);



    }

    return 0;
}
