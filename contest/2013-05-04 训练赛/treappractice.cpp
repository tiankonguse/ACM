/*************************************************************************
    > File Name: 7.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/1 18:14:11
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100010;
int cnt=1,rt=0;
struct treap
{
    int key,val,pri,ch[2];
    void set(int x,int y,int z)
    {
        key=x;val=y;pri=z;
        ch[0]=ch[1]=0;
    }
}t[maxn];
void rotate(int &x,int f)
{
    int y = tree[x].ch[!f];
    tree[x].ch[!f]=tree[y].ch[f];
    tree[y].ch[f]=x;
    x=y;
}
void insert(int &x,int key,int val)
{
    if(x==0)
    {
        tree[x=cnt++].set(key,val,rand());
    }
    else
    {
        int f = key<tree[x].key;
        insert(tree[x].ch[!f],key,val);
        if(tree[x].pri<tree[tree[x].ch[!f]].pri)rotate(x,f);
    }
}
void del(int &x,int key)
{
    if(tree[x].key==key)
}
