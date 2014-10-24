#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef unsigned long long ULL;

char a[100000];
ULL sum[100000],d[100000];
const int P=10007;

ULL geth(int i , int j)
{
    return sum[j] - sum[i - 1] * d[j - i + 1];
}

int check(int n){
    int i=1,j=n,ans=0;
    while (i<=j){
        if (i==j) return ans+1;
        for (int k=1; ; ++k){
            if (i+k-1>=j-k+1) return ans+1;
            if (geth(i , i + k - 1) == geth(j - k + 1 , j))
            {
                ans += 2;
                i += k , j -= k;
                break;
            }

//            ULL z1=sum[i+k+1]-sum[i],z2=sum[j+1]-sum[j-k-1];
//            z1=z1*d[n-i-k];
//            z2=z2*d[n-j];
//            printf("%d %d %d %d\n",i,i+k,j-k,j);
//            cout<<z1<<" "<<z2<<endl;
//            if (z1==z2){
//                ans+=2;
//                i=i+k;
//                j=j-k;
//                break;
//            }
        }
    }
    return ans;
}

int main(){
    int T;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    d[0]=1;
    int num=0;
    for (int i=1; i<100000; ++i) d[i]=d[i-1]*P;
    for (;T;--T){
        memset(sum,0,sizeof(sum));
        scanf("%s",a+1);
        int n=strlen(a+1);
        for (int i=1; i<=n; ++i) sum[i]=sum[i-1]*P + (a[i]-'A'+1);
        printf("Case #%d: %d\n",++num,check(n));
    }
}
