#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
//1.bulid();2.query(a,b)；3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 111;

double sum[maxn<<2];//区间的测度
int LayerCount[maxn<<2];//区间被覆盖的层数 
int n;
double map[maxn<<1];//区间映射到整型 

struct Line{
	double pos;//pos为分割线
	double top;//top为矩阵的上界
	double bottom; //bottom为矩阵的下届 
	int sign; //sign = 1 : 直线为矩形的左边, sign = 0:直线为矩形的右边
	void init(double pos,double top,double bottom,int sign){
		this->pos=pos;this->top=top;this->bottom=bottom;this->sign=sign;
	}
}line[maxn<<1];
	
bool cmp(Line l1, Line l2){
	return l1.pos < l2.pos;
}

inline void PushUp(int rt,int l,int r){
	//将线段树上区间的端点分别映射到y[]数组所对应的浮点数上,由此计算出测度
	if(LayerCount[rt] > 0)sum[rt] = map[r-1] - map[l-1];
	else if(r - l == 1)   sum[rt] = 0;
	else sum[rt] = sum[rt<<1] + sum[rt<<1 | 1];
}

void bulid(int l=1,int r=n,int rt=1){

	LayerCount[rt]=0;
	sum[rt]=0;
	
	if(l==r){// 据题意做相关修改
		return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
}

void update(int L,int R,int add,int l=1,int r=n,int rt=1){
	if(L<=l && r<=R){// 据题意做相关修改
		LayerCount[rt]+=add;
		PushUp(rt,l,r);
		return ;
	}
	
	int m = (l + r) >> 1;
	if(l+1==r)return ;
	if (L < m) update(L , R , add , lson);
	if (R > m) update(L , R , add , rson);
	PushUp(rt,l,r);
}


//去掉重复的线
void DelDoubleLine(int m){
		n=0;
		for(int i=1; i < m; i++){
			while(map[n]==map[i] && i<m)i++;
			if(i<m){
				map[++n]=map[i];
			}
		}
		n++;
}
int findpos(double t){
	//二分查找出浮点数t 在数组y[]中的位置(此即所谓的映射关系)
	int low,high,mid;
	low = 0; high = n-1;
	while(low < high){
		mid = (low+high)/2;
		if(t > map[mid]) low = mid + 1;
		else high = mid;
	}
	return high+1;
}
int main()
{
	int m,i,t=1;
	int l,r;
	double x1,y1,x2,y2;
	double ans;
	while(scanf("%d",&m),m){
		for(i=0;i<m;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			line[2*i].init(x1,y1,y2,1);
			line[2*i+1].init(x2,y1,y2,0);
			
			map[2*i] = y1; 
			map[2*i+1] = y2;
		}
		m<<=1;
		sort(line, line+m, cmp);
		sort(map, map+m);
		
		DelDoubleLine(m);
		
		bulid();
		ans=0;
		
		for(i = 0; i < m-1; i++){
			//由对应关系计算出线段两端在树中的位置
			l = findpos(line[i].top);
			r = findpos(line[i].bottom);
			update(l,r,line[i].sign);
			ans += sum[1] * (line[i+1].pos -line[i].pos);
		}
		
		printf("Test case #%d\nTotal explored area: %.2f\n",t++,ans);
	}
	return 0;
}
