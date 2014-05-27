#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N = 10011;
//x 坐标　c 个数　w 温度　s是否是中间那个点
struct T{
	int x,c,w,s;
}str[N];
//缩点后的点的个数
int num;

//map　代表某个点缩点后的位置
int map[10011];
//n个点,位置x,热度h
int n,x,h;
int l,r,i,k;

//pre 代表上一个固定位置的点
int pre,ans,now;

//记录是不是中间那个点,是的话p代表那个位置．
bool have;
int p;



int main() {
	int cas;
	char op[4];
	scanf("%d",&cas);
	for(int ca=1;ca<=cas;ca++){
		scanf("%d",&n);

		num = 0;
		pre = -1;

		str[0].c = 0;
		str[0].s = 0;

		for(i=0;i<n;i++){
			scanf("%d%d",&x,&h);
			if(h == 0){
				if(pre == -1){
					//一直是休息点,位置无关，直接关联下一个景点
					str[num].c++;
				}else{
					//前面有景区，先缓存
					str[num].x = x;
					str[num].s = 0;
					num++;
				}
			}else{
				if(pre == -1){
					//第一个景点
					str[num].x = x;
					str[num].w = h;
					str[num].c++;
					str[num].s = 0;
					pre = num;
					num++;
				}else{
					//中间的景点
					str[num].x = x;
					str[num].c = 1;
					str[num].w = h;
					str[num].s = 0;

					now = pre + 1;
					have = false;
					while(now < num){
						l = str[now].x - str[pre].x;
						r = str[num].x - str[now].x;
						if(l < r){
							str[pre].c++;
						}else if(l == r){
							have = true;
							str[now].w = max(str[num].w, str[pre].w);
							p = now;
						}else{
							str[num].c++;
						}
						now++;
					}

					if(have){
						num = pre + 1;
						str[num].x = str[p].x;
						str[num].w = str[p].w;
						str[num].c = 1;
						str[num].s = 1;

						num = pre + 2;
						str[num].x = str[now].x;
						str[num].w = str[now].w;
						str[num].c = str[now].c;
						pre = num;
						num++;
					}else{
						num = pre + 1;
						str[num].x = str[now].x;
						str[num].w = str[now].w;
						str[num].c = str[now].c;
						pre = num;
						num++;
					}
				}
				map[i] = num-1;
			}
		}
		num--;
		while(pre != -1 && num > pre){
			str[pre].c++;
			num--;
		}
		num++;

		printf("Case #%d:\n",ca);
		scanf("%d",&k);
		while(k--){
			scanf("%s",op);
			if(op[0] == 'Q'){
				scanf("%d",&h);
				ans  = 0;
				for(i=0;i<num;i++){
					if(str[i].w <= h){
						ans += str[i].c;
					}
				}
				printf("%d\n",ans);
			}else{
				scanf("%d%d",&x,&h);
				x = map[x];
				str[x].w = h;
				if(x > 0 && str[x-1].s){
					str[x-1].w = max(str[x].w, str[x-2].w);
				}
				if(x + 1 < num && str[x+1].s){
					str[x+1].w = max(str[x].w, str[x+2].w);
				}

			}
		}


	}



    return 0;
}
