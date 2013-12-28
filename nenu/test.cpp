#include <stdio.h>
int cube(int y) {
    return y*y*y;
}

int judge(int x) {
    int bai,shi,ge;
    bai = x/100;
    shi = (x/10)%10;
    ge = x%10;
    if(x==cube(bai)+cube(shi)+cube(ge)) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    int judge(int);
    int m,n,i,j;
    while(scanf("%d %d",&m,&n)!=EOF) {
        j=0;
        for(i=m; i<=n; i++) {
            if(judge(i)) {
                printf("%d ",i);
                j++;
            }

        }
        if(j!=0) printf("\b");
        if(j==0) printf("no");
        printf("\n");
    }
    return 0;
}


