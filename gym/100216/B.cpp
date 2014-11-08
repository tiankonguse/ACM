#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //freopen("bandits.in","r",stdin);
    //freopen("bandits.out","w",stdout);
    int m,n;
    scanf("%d%d",&m,&n);
    vector<int> u;
    u.push_back(n);
    for(int i=2;i<=m;i++){
        int c=i/2,sum=0;
        vector<int> v=u;
        sort(v.begin(),v.end());
        for(int j=0;j<c;j++) sum+=v[j] + 1;
        while (c > 0 && c < i - 1 && v[c - 1] == v[c]) c--;
        for(int j=0;j<c;j++) ++v[j];
        for(int j=c;j<i-1;j++) v[j]=0;
        if(sum>n){
            u.insert(u.begin(),-1);
        }else{
            v.swap(u);
            u.insert(u.begin(),n-sum);
        }
    }
    printf("%d\n",u[0]);
}