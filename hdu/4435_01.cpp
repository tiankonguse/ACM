#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
const int N=200;
int num[N];
int str[N][N][2];
bool have[N];//是否到达该地点
bool oil[N];//是否设为加油站
bool ok;
int point[N][2];
int n,d;


int getlen(int i,int j){
	int x=point[i][0]-point[j][0];
	int y=point[i][1]-point[j][1];
	int s=x*x+y*y;
	int len=(int)sqrt(s*1.0);
	if(len*len<s)len++;
	return len;
}

void dfs(int now){
	have[now]=true;
	for(int i=0;i<num[now];i++){
		//如果下一站没有到达过且可以到达
		if(!have[str[now][i][0]] && d>=str[now][i][1] ){
			//不是加油站
			if(!oil[str[now][i][0]]){
				//不加油再回来
				if(d>=str[now][i][1]+str[now][i][1]){
					have[str[now][i][0]]=true;
				}
			}else{
				//是加油站可以到就可以逆着回来
				dfs(str[now][i][0]);
			}
		}
	}
}

bool couldgo(){
	memset(have,false,n*sizeof(bool));
	dfs(0);
	for(int i=0;i<n;i++){
		if(!have[i])return false;
	}
	return true;
}

void solver(){
	memset(oil,true,n*sizeof(bool));

	if(!couldgo()){ok = false;return ;}

	for(int i=n-1;i>0;i--){
		oil[i]=false;
		if(!couldgo())oil[i]=true;
	}
}

void myprint(){
	int i=n-1;
	while(!oil[i])i--;
	for(;i>=0;i--){
		putchar(oil[i]?'1':'0');
	}
	puts("");
}

int main(){

	int i,j,tmp;
	while(~scanf("%d%d",&n,&d)){
		for(i=0;i<n;i++){
			scanf("%d%d",&point[i][0],&point[i][1]);
			num[i]=0;
		}

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				tmp=getlen(i,j);

				if(tmp<=d){
					str[i][num[i]][0]=j;
					str[i][num[i]][1]=tmp;
					num[i]++;
					str[j][num[j]][0]=i;
					str[j][num[j]][1]=tmp;
					num[j]++;
				}
			}
		}

		ok=true;
		solver();
		if(ok){
			myprint();
		}else{
			printf("-1\n");
		}

	}

	return 0;
}
