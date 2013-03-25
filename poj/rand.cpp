#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<functional>

const int begin = 1000;

const int end = 4054;

int main(){
    srand((unsigned int)(time(NULL)));
    printf("%d\n", rand()%(end + 1 - begin) + begin);
    getchar();
    return 0;
}
