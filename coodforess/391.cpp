/*************************************************************************
    > File Name: 391.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: Wed 26 Feb 2014 03:40:34 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
        int p,e;

}c[200000];
int n,k;
int cmp(node a,node b){return a.p>b.p;}
long long check(int s)
{
        if (s>n) return -1;
        int i,t=0,x;
        vector<int> cur,rem;
        for (i=0;i<n;i++)
    {
                if (c[i].p<s-1) t++;
                if (c[i].p<=s&&c[i].p>=s-1) cur.push_back(c[i].e);
                else rem.push_back(c[i].e);
            
    }
        x=max(n-k+1-t,0);
        if (x>s||x>cur.size()) return -1;
        long long tot=0;
        sort(cur.begin(),cur.end());
        for (i=0;i<x;i++) tot+=cur[i];
        for (i=x;i<cur.size();i++) rem.push_back(cur[i]);
        sort(rem.begin(),rem.end());
        for (i=0;i<s-x;i++) tot+=rem[i];
        return tot;

}
int main()
{
        long long tot,m=0;
        cin>>n>>k;
        if (k>n) {cout<<0<<endl;return 0;}
        for (int i=0;i<n;i++) {cin>>c[i].p>>c[i].e;m+=c[i].e;}
        sort(c,c+n,cmp);
        if (c[k-1].p>n) {cout<<-1<<endl;return 0;}
        for (int i=0;i<=2;i++)
    {
                tot=check(c[k-1].p+i);
            cout<<"i="<<i<<" "<<tot<<endl;
        if (tot>0){
            m=min(m,tot);
        }
            
    }
        cout<<m<<endl;
        return 0;

}
