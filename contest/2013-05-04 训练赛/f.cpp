#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff
#define maxn 100010
using namespace std;



int main(){
    srand((unsigned int )(time(NULL)));

    int cas,n,ai,i,nn,p;
    cin>>cas;
    for(i=1;i<=cas;i++){
        cin>>n;nn=n;
        p=0;
        while(nn--){
            cin>>ai;
            if(ai>3)p++;

        }
        printf("Case %d: %s\n",i,((p&n%2))?"Alice":"Bob");
    }


    return 0;
}
