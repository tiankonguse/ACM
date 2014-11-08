typedef long long lld;
const int N=105;
int n;
lld m[N];
lld c[N];
bool check;

lld exgcd(lld a,lld b,lld &x,lld &y){
    if (!b){
      x=1;
      y=0;
      return a;
    }
    else{
      lld res=exgcd(b,a%b,x,y);
      lld t=x;
      x=y;
      y=t-(a/b)*y;
      return res;
    }
}

inline
lld mod(lld x,lld y){
    lld res=x%y;
    if (res<0) res+=y;
    return res;
}

lld  solve(){
     for (int i=1;i<=n;i++)
        if (c[i]>=m[i]){
            check=false;
            return -1;
        }
     check=true;
     lld ans=c[1],LCM=m[1],x,y,g,mm;
     for (int i=2;i<=n;i++){
         g=exgcd(LCM,m[i],x,y);
         if ((c[i]-ans)%g) {check=false; return -1;}
         ans=mod( ans + LCM * mod( (c[i]-ans)/g*x, m[i]/g )  , LCM/g*m[i]);
         LCM=LCM/g*m[i];
     }
     return mod(ans,LCM);
}

