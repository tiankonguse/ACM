#include <cstdio>
#include <cmath>

int val[7];

bool is(int n){
    for(int i=0;i<6;i++){
        val[i] = n%10;
        n/=10;
    }
    for(int i=0;i<3;i++){
        if(val[i] != val[5-i])return false;
    }
    return true;
}

int main() {
    int ans = 0;
    for(int i = 0; i < 1000000; i++){
        if(is(i))ans++;
    }
    printf("%d\n",ans);
    return 0 ;
}
