#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define PB(x) push_back(x)
#define FOR(i,n) for(int i=0;i<n;++i)
typedef vector<int> VI;

priority_queue<int, VI, greater<int> >pq;
map<int,int>::reverse_iterator it;
map<int,int> mp;
long long ans=0;

int main()
{
    int i,t,n;
    cin>>n;
    FOR(i,n){ cin>>t; ans+=t; mp[t]++;}

    int all=0,free=0;
	for(it=mp.rbegin();it!=mp.rend();++it){
        int val = it->first;
		int cur = it->second;
        int ct = min(all-2*free, cur);//免费的个数
        printf("all=%d  free=%d cur=%d  val=%d ct=%d\n",all,free,cur,val, ct);
        VI up = VI(ct,val);//免费
        cur -= ct;//不能免费的
        while( pq.size() && cur){
            printf("%d \n",pq.top());
            if(pq.top()<val){
                up.PB(val); cur--;
                if(cur){ up.PB(val); cur--;}
            }
            else if(pq.top()<2*val && cur>1) {
                up.PB(2*val - pq.top());
                up.PB(pq.top());
                cur-=2;
            }
            else break;
            pq.pop();
        }

        FOR(i,up.size()) pq.push(up[i]),printf("%d ",up[i]);
        puts("");
        free = pq.size();
        all += it->second;
	}

    while(pq.size()){ ans -= pq.top(); pq.pop();}

    cout<<ans<<endl;
	return 0;
}
/*
6
3 4 5 3 4 5
8
6 6 5 5 4 4 3 3

*/
