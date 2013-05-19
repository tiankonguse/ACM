/*************************************************************************
    > File Name: CD操作.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 19:47:00
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;

map<string,int>Map;
int map_num;
int pre[100010];
int len[100010];
char first[50],second[50];

int find_map(char *p){
    if(Map.find(p) != Map.end()){
        return Map[p];
    }else{
        return Map[p]=map_num++;
    }
}

int find_len(int p){
    if(len[p] != -1){
        return len[p];
    }
    if(pre[p] == -1){
        return len[p] = 0;
    }

    return len[p] = find_len(pre[p]) +1;
}

int find_con_pre_len(int a,int b){
//    printf("--%d  %d\n",len[a],len[b]);
    int len_a=0,len_b=0;
    while(a != b){
//        printf("888 %d  %d\n",a,b);

        if(len[a] > len[b])a = pre[a],len_a++;
        else b=pre[b],len_b++;
    }
    if(len_b)len_a++;
    return len_a;
}

int main() {
    int cas,n,m,k,i,j,a,b;

    scanf("%d",&cas);
    while(cas--){

        scanf("%d%d",&n,&m);
        Map.clear();
        map_num = 0;
        memset(pre,-1,sizeof(pre));
        memset(len,-1,sizeof(len));

        for(i=1;i<n;i++){
            scanf("%s%s",first,second);
            a = find_map(first);
            b = find_map(second);
//            printf("%d----%d->%d\n",i,a,b);
            pre[a] = b;
        }

//        printf("num=%d\n",map_num);

        for(i=0;i<map_num;i++){
            find_len(i);
//            printf("i=%d  %d\n",i,len[i]);
        }
        while(m--){
            scanf("%s%s",first,second);
            a = find_map(first);
            b = find_map(second);
//            printf("----%d->%d\n",a,b);
            printf("%d\n",find_con_pre_len(a,b));
//            printf("end\n");
        }
//        printf("------------------\n");


    }

    return 0;
}
