#include<iostream>
using namespace std;

int a[21][21];
int main()
{
    int nCase = 1, n;
    int i, j, k, from, to;
    
    while (1) {
        memset(a, 20, sizeof(a));
        from = 1;
        a[from][from] = 0;
        if (!(cin>>n)) break;
        else {
            for (j = 0; j < n; ++j) {
                scanf("%d", &to);
                a[from][to] = 1;
                a[to][from] = 1;
            }
        }
        for (from = 2; from <= 19; ++from) {
            a[from][from] = 0;
            scanf("%d",&n);
            for (j = 0; j < n; ++j) {
                scanf("%d", &to);
                a[from][to] = 1;
                a[to][from] = 1;
            }
        }
        
        for (k = 1; k <= 20; ++k) 
            for (i = 1; i <= 20; ++i) 
                for (j = 1; j <= 20; ++j) 
                    if (a[i][k]+a[k][j] < a[i][j])
                        a[i][j] = a[i][k]+a[k][j];
        
        scanf("%d",&n);
        printf("Test Set #%d\n",nCase++);
        for (i = 1; i <= n; ++i) {
            scanf("%d %d",&from, &to);
            printf("%d to %d: %d\n", from, to, a[from][to]);
        }
        cout<<endl;
    }    
    return  0;
}