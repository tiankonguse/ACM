#include <cstdio>
const int N = 20010;
int n;
int a[N],b[N],c[N];
int main() {
    while(~scanf("%d",&n)) {
        int ans = 0;
        for(int i=0; i<n; i++) {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j = a[i]; j <= b[i]; j += c[i]) {
                ans ^= j;
            }
        }

        if(ans != 0) {
            int num = 0 ;
            for(int i=0; i<n; i++) {
                if(ans >= a[i] && ans <= b[i]) {
                    if((ans - a[i])%c[i] == 0) {
                        num++;
                    }
                }
            }
            printf("%d %d\n",ans,num);

        } else {
           printf("DC Qiang is unhappy.\n");
        }
    }
    return 0;
}

