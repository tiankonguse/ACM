
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char in[200];
char map[256];
int main(){
    int n,i;
    map['1']='1';
    map['0']='0';
    map['8']='8';
    map['6']='9';
    map['9']='6';
    while(~scanf("%s",in)){
            for(i=0;in[i];i++){
                in[i] = map[in[i]];
            }
            for(i--;i>=0;i--){
                putchar(in[i]);
            }
            puts("");
    }
}
