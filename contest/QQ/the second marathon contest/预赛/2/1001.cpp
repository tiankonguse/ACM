#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<functional>


int getAlls(int h, int m, int s){

    if(h == 0)h = 12;

    return h * 60 * 60 + m * 60 + s;
}

int main(){
    int nowh,nowm,nows,nowAlls;
    int oldh,oldm,olds ,oldAlls;
    int ans;
    int cas;
    scanf("%d", &cas);
    while(cas--){

        scanf("%d:%d:%d",&nowh,&nowm,&nows);

        nowAlls = getAlls(nowh,nowm,nows);


        scanf("%d:%d:%d",&oldh,&oldm,&olds);

        oldAlls = getAlls(oldh%12,oldm,olds);

        if(oldAlls > nowAlls){
            nowAlls += 12 * 60 * 60;
        }

        ans = nowAlls - oldAlls;

        nowh = ans / 3600;
        ans %= 3600;

        nowm = ans / 60;

        nows = ans % 60;

        printf("%02d:%02d:%02d\n",nowh,nowm,nows);
    }
    return 0;
}
