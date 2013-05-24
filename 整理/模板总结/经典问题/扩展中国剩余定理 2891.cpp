#include<cstdio>
#include<cstdlib>

typedef __int64 LL;

inline LL ex_gcd(LL a,LL b,LL &x,LL &y){
    if (!b) {
        x=1,y=0;
        return a;
    }
    LL ret=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

LL k,ai,ri,ans,lcm;

int main(){
    while (scanf("%I64d",&k)==1){
        lcm=1; ans=0; k--;
        scanf("%I64d %I64d",&ai,&ri);
        lcm=ai,ans=ai+ri;
        bool flag=1;
        for (;k;k--){
            scanf("%I64d %I64d",&ai,&ri);
            if (!flag) continue;
            LL x,y,b=ri-ans;
            LL gcd=ex_gcd(lcm,ai,x,y);
            if (b%gcd!=0) flag=0;
            else{
                LL times=(ri-ans)/gcd;
                x*=times; ans=ans+(((x%ai)+ai)%ai)*lcm;
            }
            if (!flag) continue;
            lcm=lcm*ai/gcd;
            ans=((ans%lcm)+lcm)%lcm;
        }
        printf("%lld\n",flag?ans:-1);
    }
}
