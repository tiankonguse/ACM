#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

double a[10][10],b[10],c[10];
const double ZERO=1e-3;

void swap(double &a,double &b){
    double t=a; a=b; b=t;
}

double abs(double x) { return x<0?-x:x; }

int check(int m,int n,int x){
    for (int i=0; i<m; ++i){
        int k=i;
        for (int j=i+1; j<m; ++j)
            if (abs(a[j][i])>abs(a[k][i])){
                k=j;
            }
        if (abs(a[k][i])<ZERO) continue;
        for (int j = 0 ; j <= n + 1 ; ++ j)
            swap(a[k][j] , a[i][j]);
        for (int j = i + 1 ; j < m ; ++ j)
        {
            double x = a[j][i] / a[i][i];
            for (int l = i ; l <= n + 1 ; ++ l)
                a[j][l] -= x * a[i][l];
        }
    }
    //printf("%.10lf\n" , abs(a[m - 1][n + 1]));
    if (abs(a[m - 1][n + 1]) > ZERO)
        return 0;
    return 1;
}

int main(){
    int n;
    while (scanf("%d",&n) , n){
        for (int i=0; i<=n+2; ++i) scanf("%lf",&b[i]);
        int m;
        int ans=-1;
        for (int i=0; i<=n+2; ++i){
            m=0;
            for (int j=0; j<=n+2; ++j)
                if (i!=j){
                    for (int k=0; k<=n; ++k){
                        a[m][k]=1;
                        for (int l=1; l<=k; ++l) a[m][k]=a[m][k]*j;
                    }
                    a[m][n+1]=b[j];
                    ++m;
                }
            if (check(m,n,i)) {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
