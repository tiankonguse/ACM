#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[100005],b[100005],n,s[100005],g1[100005],g2[100005];

struct array {
    int x,y;
} ans[100005];

int f(int index,int mid) {
    int i,j;
//for(i=index)
}

int main() {
    int i,j,k,q;
    while(scanf("%d",&n)!=EOF) {
        for(i=1; i<=n; i++) {
            scanf("%d",&a[i]),s[i]=-1,g1[i]=g2[i]=-1,ans[i].x=i,ans[i].y=-1;
        }
        for(i=1; i<=n; i++) {
            scanf("%d",&b[i]);
        }
        if(n>=3) {
            s[3]=b[2]-b[1],a[3]=s[3],ans[3].y=a[3];
        }
        for(i=6; i<=n; i+=3) {
            s[i] = b[i-1]-(b[i-2]-s[i-3]);
            a[i] = s[i];
            ans[i].y=a[i];
        }
        if(n-2>=1) {
            s[n-2]=b[n-1]-b[n],a[n-2]=s[n-2],ans[n-2].y=a[n-2];
        }
        for(i=n-6; i>=1; i-=3) {
            s[i]=b[i-1]-(b[i+2]-s[i+3]),a[i]=s[i],ans[i].y=a[i];
        }
        int m = n/3*3;
        j=1;
        for(i=1; i<=m; i+=3) {
            g1[j++]=i;
            g2[j-1]=b[i+1]-s[i+2];
            g1[j++]=i+1;
            g2[j-1]=b[i+2]-s[i+2];
        }
        if(n-m==1) {
            g1[j++]=n;
            g2[j-1]=b[n]-s[n-1];
        } else if(n-m==2) {
            g1[j++]=n-1;
            g2[j-1]=b[n-1]-s[n-2];
            g1[j++]=n;
            g2[j-1]=-1;
        }
// for(i=1;i<j;i++)
// cout<<i<<"%%%"<<g1[i]<<" "<<g2[i]<<endl;
        int flag=0;
        for(i=1; i<j; i++) {
            if(ans[g1[i]].y!=-1) {
                flag=1;
                k=i;
                break;
            }
        }
        if(flag) {
            for(i=k+1; i<=n; i++) {
                ans[g1[i]].y=g2[i-1]-ans[g1[i-1]].y;
            }
            for(i=k-1; i>=1; i--)
                ans[g1[i]].y=g2[i]-ans[g1[i+1]].y;
        }
        scanf("%d",&q);
        while(q--) {
            scanf("%d",&k);
            k++;
            if(ans[k].y!=-1)printf("%d\n",ans[k].y);
            else {
                int l = 0,r = 10005;
                while(l<r) {
                    int mid = l+(r-l)/2;
                    if(f(k,mid))r=mid;
                    else l = mid+1;
                }
                cout<<l<<endl;
            }
        }
    }
