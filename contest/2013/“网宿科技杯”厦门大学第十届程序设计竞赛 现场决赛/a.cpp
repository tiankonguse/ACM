/*************************************************************************
    > File Name: a.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 13:07:41
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<cstdlib>


const int N = 222;
const char c = '.';
char str[N][N];
int top[N][N];
int bottom[N][N];
int left[N][N];
int right[N][N];

void init(int n,int m){
    memset(top,0,sizeof(top));
    memset(bottom,0,sizeof(bottom));
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    int i,j;
    for(i=2;i<=n-1;i++){
        for(j=2;j<=m-1;j++){
             if(str[i-1][j] != c){
                top[i][j] = top[i-1][j] +1;
             }else{
                 top[i][j] = 0;
             }
             if(str[i][j-1] != c){
                left[i][j] = left[i][j-1] +1;
             }else{
                left[i][j] = 0;
             }
        }

    }

    for(i=n-1;i>=2;i--){
        for(j=m-1;j>=2;j--){
             if(str[i+1][j] != c){
                bottom[i][j] = bottom[i+1][j] +1;
             }else{
                 bottom[i][j] = 0;
             }
             if(str[i][j+1] != c){
                right[i][j] = right[i][j+1] +1;
             }else{
                right[i][j] = 0;
             }
        }

    }


}

int min(int a,int b){
    return a>b?b:a;
}

int main() {
    int n,m,i,j,ans;
    while(~scanf("%d%d",&n,&m)){
        memset(str,c,sizeof(str));
        for(i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            str[i][m+1] = c;
        }
        init(n,m);
        ans = 0;
        for(i=2;i<=n-1;i++){
            for(j=2;j<=m-1;j++){
                if(str[i][j] != c){
                    ans += min(min(top[i][j],bottom[i][j]), min(left[i][j],right[i][j]));
                }
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
