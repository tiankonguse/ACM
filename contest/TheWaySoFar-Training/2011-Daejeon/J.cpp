#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

map <int,int> m1,m2;
const int MAXN=1000002;

typedef map<int,int>::iterator IT;
typedef pair<int,int> point;
point c1[MAXN],c2[MAXN];

int main(){
    int T;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    for (;T ; --T){
        int n;
        scanf("%d",&n);
        m1.clear();
        m2.clear();
        for (int i=0; i<n; ++i)
            scanf("%d%d",&c1[i].second,&c1[i].first);
        int m;
        scanf("%d",&m);
        for (int i=0; i<m; ++i)
            scanf("%d%d",&c2[i].second,&c2[i].first);
        sort(c1,c1+n);
        sort(c2,c2+m);
        int ans=10000000;
        for (int i=0; i<m; ++i) ++m1[c2[i].first+c2[i].second];
        for (int i=0, j=0; i<n; ++i){
            while (j<m && c2[j].first<c1[i].first){
                int k=c2[j].first+c2[j].second;
                if (--m1[k]==0) m1.erase(k);
                ++m2[c2[j].second-c2[j].first];
                ++j;
            }
            if (m1.size()){
                IT t=m1.begin();
                int k=t->first;
               // cout<<k-c1[i].first-c1[i].second<<endl;
                ans=min(ans,k-c1[i].first-c1[i].second);
            }
            if (m2.size()){
                IT t=m2.begin();
                int k=t->first;
                ans=min(ans,k-(c1[i].second-c1[i].first));
            }
        }
        printf("%d\n",ans);
    }
}
