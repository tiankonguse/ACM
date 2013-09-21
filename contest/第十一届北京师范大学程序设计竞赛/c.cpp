/*************************************************************************
    > File Name: c.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 13:00:31
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

int main() {

        int cas,n,m,num;
        scanf("%d",&cas);
        while(cas--){
            scanf("%d%d",&n,&m);
            num=0;
            while(n && n%2 == 0){
                n >>=1;
                num++;
            }
            while(m && m%2 == 0){
                m >>=1;
                num++;
            }
            if(num&1){
                puts("Adidas loses");
            }else{
                puts("Adivon prevails");
            }
        }




    return 0;
}
