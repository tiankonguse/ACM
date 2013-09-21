/*************************************************************************
    > File Name: [B] Blitzcrank.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/18 13:50:55
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
typedef int LL;
char str[100],op[100];
LL map[256];
LL A,B,aa,bb;
char tmp[200];
LL input(char* tmp){
    scanf("%s",tmp);
    LL now=0;
    while(*tmp){
        now = now*16 + map[*tmp];
        tmp++;
    }
    return now;
}

int main() {

    int cas,i,j;
    char c;
    for(i='0',j=0;i<='9';i++,j++){
        map[i]=j;
    }
    for(i='A';i<='F';i++,j++){
        map[i]=j;
    }


    scanf("%d",&cas);
    while(cas--){
        A = input(tmp);
        B = input(tmp);
        getchar();
        while(1){
            c = getchar();
            while(c == ' '){
                c = getchar();
            }

            if(c == '\n'){
                break;
            }
            scanf("%s",tmp);
            if(c == '8'){
                scanf("%s",tmp);
                if(tmp[0] == 'A'){
                    A += B;
                }else{
                    B += A;
                }
                scanf("%s",tmp);
            }else{
               scanf("%s",tmp);
                if(tmp[0] == 'A'){
                    A += A;
                }else{
                    B += B;
                }
            }

        }
        printf("%0X %0X\n",A,B);
    }

    return 0;
}
