/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-27 21:01
 # Filename: POJ2828 Buy Tickets.cpp
 # Description : 倒序插入，这样POS的意义就变为找到这么一个位置可以放置这个人，
 使得从这个位置往前数共有POS个空位，线段树的节点中cnt表示在[l,r)区间中共有多少
 个空位
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 200010
using namespace std;

struct NODE
{
	int l,r,cnt;
}node[MAX<<2];

pair<int,int> order[MAX];
int result[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].cnt=r-l;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &pos,const int &val)
{
    --node[t].cnt;
	if(node[t].l == node[t].r-1)
  {
	result[node[t].l]=val;
		return;
  }
  if(node[L(t)].cnt > pos)
    update(L(t),pos,val);
  else{
    update(R(t),pos - node[L(t)].cnt,val);
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;

  while(~scanf("%d",&n))
  {
	  init();
	  build(1,0,n);
	  for(int i=0;i<n;++i)
		  scanf("%d%d",&order[i].first,&order[i].second);
	  for(int i=n-1;i>=0;--i)
		  update(1,order[i].first,order[i].second);
	  for(int i=0;i<n;++i)
		  printf("%d%c",result[i],i==(n-1)?'\n':' ');
  }

  return 0;
}
