#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<functional>
#include<algorithm>
using namespace std;

int A[6];
int len;
char str[111];
char *p;

int readNum(){

    int sign = 1;

    int val = 1;

    if(*p == '-'){
        sign = -1;
        p++;
    }else if(*p == '+'){
        sign = 1;
        p++;
    }

    while(*p >= '0' && *p <= '9'){
        val = val * 10 + *p - '0';
        p++;
    }

    return val * sign;
}

void read(){
    int a,b=0;
    a = readNum();
    //printf("a=%d\n",a);
    if(*p == 'x'){
        p++;
        b = 1;
        if(*p == '^'){
            p++;
            b = readNum();
        }
    }

    if(b > len) len = b;

    A[b] += a;
}

int main(){
    int t,pos,i;
    scanf("%d",&t);
    while(t--){
        scanf("%s",&str);
        for()
        len = 0;
        p = str;
        while(*p){
            //printf("%c\n",*p);
            read();
        }
        printf("\n");
        for(int i =0;i<=len;i++){
            if(A[i]){
                printf("%d x ^ %d\n",A[i],i);
            }

        }
        printf("\n");

    }
    return 0;
}
