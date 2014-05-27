#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    freopen("JACK AND JOHN.in","w",stdout);
    puts("100");
    int t=20;
    while(t--){
        ll n,a,b;
        n=rand()%10000ll+1ll;
        a=rand()%1000000ll+1ll;
        b=rand()%1000000ll+1ll;
        if(a>b) swap(a,b);
        printf("%lld %lld %lld\n",n,a,b);
    }
    t=30;
    while(t--){
        ll n,a,b;
        n=rand()%1000000ll+1ll;
        a=rand()%100000000ll+1ll;
        b=rand()%100000000ll+1ll;
        if(a>b) swap(a,b);
        printf("%lld %lld %lld\n",n,a,b);
    }
    t=20;
    while(t--){
        ll n,a,b;
        n=rand()%1000000000ll+1000000000ll;
        a=rand()%1000000000000000ll+100000ll;
        b=rand()%1000000000000000ll+10000000000000ll;
        if(a>b) swap(a,b);
        printf("%lld %lld %lld\n",n,a,b);
    }
    t=9;
    printf("1 1 1\n");
    while(t--){
        int n,a,b;
        n=rand()%10+1;
        a=rand()%10+1;
        b=rand()%10+1;
        if(a>b) swap(a,b);
        printf("%d %d %d\n",n,a,b);
    }
    t=20;
    ll n=1000000000ll,a=1,b=1000000000000000ll;
    ll k=100;
    while(t--){
        printf("%lld %lld %lld\n",n,a,b);
        n-=k,a+=k,b-=k;
    }
}
