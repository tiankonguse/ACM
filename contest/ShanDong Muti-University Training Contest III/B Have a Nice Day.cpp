/*************************************************************************
    > File Name: B Have a Nice Day.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 18:11:40
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
int str[5];
int num1[10];

void add(int val,int*s){
    if(val == 0){
        s[val]++;
    }
    while(val){
        s[val%10]++;
        val /= 10;
    }
}

bool ok(){
    int i,j,sum,_num;


    bool first = true;
    for(i=0;i<10;i++){
        if(num1[i] == 0)continue;
        if(first){
            _num = num1[i];
            first = false;
        }else{
            if(num1[i] != _num)return false;
        }
    }

    sum = 0;
    for(i=0;i<4;i++){
        sum += str[i];
    }
    if(sum&1){
        return false;
    }


    sum >>= 1;
    for(i=0;i<4;i++){
        if(sum == str[i])return true;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i==j)continue;
            if(sum == str[i] + str[j])return true;
        }
    }

    return false;
}

int main() {
    int t,Y;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&str[0],&str[1],&Y);
        memset(num1,0,sizeof(num1));

        add(str[0],num1);
        add(str[1],num1);
        add(Y,num1);

        str[2]= Y/100;
        str[3] = Y%100;
        printf("%s\n",ok()?"yes":"no");

    }
    return 0;
}
