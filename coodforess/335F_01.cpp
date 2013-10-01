#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    long long basecost=0;
    map<int, int> vals;
    for(int i=0; i<N; i++) {
        int val;
        scanf("%d", &val);
        vals[val]++;
        basecost+=val;
    }
    multiset<int> freed;
    int total=0;
    for(map<int, int>::reverse_iterator it=vals.rbegin(); it!=vals.rend(); it++) {
        int val=it->first;
        int count=it->second;
        int maxadd=min(count, total);
        int nextsize=min(min((int)freed.size()+count, total), (total+count)/2);
        int remove=maxadd-(nextsize-freed.size());

        multiset<int>::iterator pos=freed.begin();
        for(int i=0; i<remove; i++)
            pos++;
        vector<int> removed(freed.begin(), pos);
        reverse(removed.begin(), removed.end());
        freed.erase(freed.begin(), pos);

        int toadd=nextsize-freed.size();
        vector<int> add(toadd, val);
        if((total+maxadd)&1) {
            add.push_back(0);
            toadd++;
        }
        for(int i=0; i<remove; i++)
            if(removed[i]>add[i]) {
                add[i]=removed[i];
                add[toadd-i-1]-=removed[i]-val;
            }
        while(add.size() && add.back()<=0)
            add.pop_back();
        freed.insert(add.begin(), add.end());
        total+=count;
    }
    printf("%I64d\n", basecost-accumulate(freed.begin(), freed.end(), 0ll));
}
