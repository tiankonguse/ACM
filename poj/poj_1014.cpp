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

int str[7];
int total;
int f[20020*6];
int n;
int mycount[20020*6];


void MultiplePack(int cost,int weight,int amount){
    int i,v,tmp;
    for(i=0;i<=total;i++)mycount[i]=0;

    for(v = cost; v <= total; v++){
        tmp = f[v - cost] + weight;
        if(tmp > f[v] && mycount[v - cost] < amount){
            f[v] = tmp,mycount[v] = mycount[v - cost] + 1;
        }else if(f[v-1] > f[v]){
            f[v] = f[v-1],mycount[v] = mycount[v - 1];
        }
    }

}


int main(){
    bool end,ok;
    int i,cas=1;



    while(true){
        end = true;
        ok = false;
        total = 0;

        for(i=0;i<6;i++){
            scanf("%d",&str[i]);
            total += str[i]*(i+1);
            if(str[i])end = false;
        }
        if(end)break;

        if(total%2){
            ok = false;
        }else{
            total = total >> 1;
            memset(f,0
                   ,sizeof(f));
            f[0] = 0;

            for(i=0;i<6;i++){
                MultiplePack(i+1,i+1,str[i]);
            }

            ok = (f[total] == total);
        }

        if(ok){
            printf("Collection #%d:\nCan be divided.\n\n",cas);
        }else{
            printf("Collection #%d:\nCan't be divided.\n\n",cas);
        }
        cas++;
    }

    return 0;
}
