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


int str[10011];
int mycount[10011];
int wd[10011];
int state[10011];

int num;
int map[10011];

int main() {
	int cas,ca;
	int n,i,j,k,x,h,now,l,r;
	int pre;
	char op[4];
	int ans;
	int pos;
	scanf("%d",&cas);
	for(ca=1;ca<=cas;ca++){
		scanf("%d",&n);

		memset(str,0,sizeof(str));
		memset(state, 0,sizeof(state));
		memset(mycount, 0,sizeof(mycount));
		memset(wd, 0,sizeof(wd));

		num = 0;
		pre = -1;
		bool have;
		int p;
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&h);
			if(h == 0){
				if(pre == -1){
					//一直是休息点,位置无关，直接关联下一个景点
					mycount[num]++;
				}else{
					//前面有景区，先缓存
					str[num] = x;
					mycount[num]++;
					num++;
				}
			}else{
				if(pre == -1){
					//第一个景点
					str[num] = x;
					wd[num] = h;
					mycount[num]++;
					pre = num;
					num++;
				}else{
					//第中间的景点
					str[num] = x;
					mycount[num]++;
					wd[num] = h;

					now = pre + 1;
					have = false;
					while(now < num){
						l = str[now] - str[pre];
						r = str[num] - str[now];
						if(l < r){
							mycount[pre]++;
						}else if(l == r){
							have = true;
							wd[now] = max(wd[num],wd[pre]);
							p = now;
						}else{
							mycount[num]++;
						}
						now++;
					}

					if(have){
						num = pre + 1;
						str[num] = str[p];
						wd[num] = wd[p];
						mycount[num] = mycount[p];
						state[num] = 1;

						num = pre + 2;
						str[num] = str[now];
						wd[num] = h;
						mycount[num] = mycount[now];
						pre = num;
						num++;
					}else{
						num = pre + 1;
						str[num] = str[now];
						wd[num] = h;
						mycount[num] = mycount[now];
						pre = num;
						num++;
					}
				}
				map[i] = num-1;
			}
		}
		num--;
		while(num > pre){
			mycount[pre]++;
			num--;
		}
		num++;
//		printf("num=%d\n",num);
//		for(i=0;i<num;i++){
//			printf("wd=%d c=%d x=%d\n",wd[i],mycount[i],str[i]);
//		}
		printf("Case #%d:\n",ca);
		scanf("%d",&k);
		while(k--){
			scanf("%s",op);
			if(op[0] == 'Q'){
				scanf("%d",&h);
				ans  = 0;
				for(i=0;i<num;i++){
					if(wd[i] <= h){
						ans += mycount[i];
					}
				}
				printf("%d\n",ans);
			}else{
				scanf("%d%d",&x,&h);
				pos = map[x];
//				printf("pos=%d\n",pos);
				wd[pos] = h;
				if(pos > 0 && state[pos-1]){
					wd[pos-1] = max(wd[pos], wd[pos-2]);
				}
				if(pos + 1 < num && state[pos+1]){
					wd[pos+1] = max(wd[pos], wd[pos+2]);
				}

			}
		}


	}



    return 0;
}
