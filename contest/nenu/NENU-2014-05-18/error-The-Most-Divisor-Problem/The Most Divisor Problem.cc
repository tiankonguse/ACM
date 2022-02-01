#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cctype>
#include<algorithm>
using namespace std;
const int N=1000005;
typedef long long LL;
struct in{
    LL maxh,h;
    int head;
    LL id;
}p[N];
LL a[N];
LL count(in a,in b){
    return (a.h*b.id-a.id*b.h)/(b.id-a.id)+1;
}
inline LL getint(){
    LL res=0;
    char tmp;
    while(!isdigit(tmp=getchar()));
    do{
        res=(res<<3)+(res<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return res;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        p[0].head=0,p[0].id=0;
        p[1].h=getint();
        p[2].h=getint();
        p[1].head=0;p[1].maxh=0;p[1].id=1;
        p[2].head=1;p[2].id=2;p[2].maxh=count(p[2],p[1]);
        for(int i=3;i<=n;i++){
            p[i].id=i;
            p[i].h=getint();
            int p1=p[i-1].head,p2=p[i-1].id;
            LL tmp1=count(p[i],p[p2]),tmp2=count(p[i-1],p[p1]);
            int head=p2;
            while(tmp1<tmp2&&p1!=p2){
                p1=p[p1].head;p2=p[p2].head;
                tmp1=count(p[i],p[p2]);
                tmp2=count(p[p2],p[p1]);
                head=p2;
            }
            p[i].head=head;
            p[i].maxh=tmp1;
        }
        for(int i=1;i<=n;i++) a[i-1]=p[i].maxh;
        sort(a,a+n);
        a[n]=a[n-1]+1;
        int m;
        LL hh;
        scanf("%d",&m);
        while(m--){
            hh=getint();
            int low=0,hig=n,mid;
            while(low<hig){
                mid=(low+hig)/2;
                if(a[mid]<=hh) low=mid+1;
                else hig=mid;
            }
            printf("%d\n",low);
        }
    }
}
