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

#define maxn 10000

int main(){
    char list[maxn];
    int sum, i;
    while(gets(list),list[0]!='#'){
        sum = 0;
        for(i=0;list[i];i++){
            if(list[i] >= 'A' && list[i] <='Z'){
                sum += (list[i] - 'A' + 1) * (i + 1);
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
