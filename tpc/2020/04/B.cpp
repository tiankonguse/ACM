#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

//flag: 0 删除最小的， 1 删除最大的

void delLast(map<int, set<int> >&m, int v, int flag){
    if(m.count(v)){
        if(flag){
            m[v].erase(--m[v].end());
        }else{
            m[v].erase(m[v].begin());
        }

        if(m[v].size() == 0){
            m.erase(v);
        }
    }
}

int str1[111111];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        map<int, set<int> > m1, m2; //储存前后集合
        for(int i=0;i<n;i++){
            int v;
            scanf("%d", &v);
            str1[i] = v;
            if(i < n/2){
                m1[v].insert(i);
            }else{
                m2[v].insert(i);
            }
        }
        sort(str1, str1+n); //排序后，删除相同的元素
        for(int i=0;i<n;i++){
            int v = str1[i];
            if(i < n/2){
                delLast(m1, v, 0);
            }else{
                delLast(m2, v, 1);
            }
        }

        set<int> s1, s2; //剩余的元素按下标排序
        while(m1.size() > 0){
            auto it =m1.begin();
            for(auto v: it->second){
                s1.insert(v);
            }
            m1.erase(it);
        }
        while(m2.size() > 0){
            auto it = m2.begin();
            for(auto v: it->second){
                s2.insert(v);
            }
            m2.erase(it);
        }

        long long ans =0; //排序后，计算法案
        while(s1.size() > 0){
            auto it1 =s1.begin();
            auto it2 =s2.begin();
            ans +=  *it2 - *it1;
            s1.erase(it1);
            s2.erase(it2);

        }
        printf("%lld\n", ans);
    }

    return 0;
}


