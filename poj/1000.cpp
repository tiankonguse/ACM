#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<functional>

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        printf("%d\n", a+b);
    }
    return 0;
}
