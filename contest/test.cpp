#include <stdio.h>

int getAns(int n,int m){
    int ans = 0;
    for (int i=2; i<=n; i++){
        ans=(ans+m)%i;
    }
    return ans+1;
}

int main(void) {
    int n, m, i, ans=0;
    for (i=2; i<=n; i++)
        s=(s+m)%i;
    printf ("The winner is %d/n", s+1);
    return 0 ;
}
