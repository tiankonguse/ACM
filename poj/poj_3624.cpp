/**************************************************************************
 **      File Name: poj_1014.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/10 9:36:02
/**************************************************************************/

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


int total;
int f[13000];
int tmpf[13000];
int mycount[13000];

int* ff = f;
int* tmpff = tmpf;

void MultiplePack(int cost,int weight,int amount) {
    int i,v,tmp;
    for(i=0; i<=total; i++){
        mycount[i]=0;
        tmpff[i] = f[i];
    }

    for(v = cost; v <= total; v++) {

        if(mycount[v - cost] < amount) {
            tmp = tmpff[v - cost] + weight;
            if(tmp > tmpff[v]){
                tmpff[v] = tmp,mycount[v] = mycount[v - cost] + 1;
            }else if(tmpff[v-1] > tmpff[v]){
                tmpff[v] = tmpff[v-1];mycount[v] = mycount[v-1];
            }
        }else{
            if(tmpff[v-1] > tmpff[v]){
                tmpff[v] = tmpff[v-1];mycount[v] = mycount[v-1];
            }
            tmp = tmpff[v - cost] + weight;
            tmp = ff[v - cost] + weight;


        }

        if(f[v-1] > f[v]) {
            f[v] = f[v-1],mycount[v] = mycount[v - 1];
        }
    }

}


int main() {
    int cost,weight,n;
    int i;
    while(~scanf("%d%d",&n,&total)) {
        memset(f,0,sizeof(f));
        for(i=0; i<n; i++) {
            scanf("%d%d",&cost,&weight);
            MultiplePack(cost,weight,1);
        }
        printf("%d\n",f[total]);

    }

    return 0;
}
