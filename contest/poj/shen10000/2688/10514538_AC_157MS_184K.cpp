#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
const int N=22;
const int M=12;
char str0[N][N];
int str1[M][M];
int str2[M][2];
int str3[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool str4[N][N];
bool str5[M];
int ans;
int w,h;
int num;
struct TT{
	TT(int x0=0,int y0=0 ,int s0=0):x(x0),y(y0),s(s0){}
	int x,y,s;
}now;
queue<TT>que;

int init(){
	int k=1;
	for(int i=0;i<h;i++)
	for(int j=0;j<w;j++){
		if(str0[i][j]=='*' ){
			str2[k][0]=i;
			str2[k][1]=j;
			str0[i][j]='0'+k;
			k++;
		}else if(str0[i][j]=='o'){
			str2[0][0]=i;
			str2[0][1]=j;
			str0[i][j]='0';
		}
	}
	return k;
}

int find(int p){
	
	memset(str4,true,sizeof(str4));
	int k=1;
	while(!que.empty())que.pop();
	int x0,y0,s0,x1,y1,s1,k1;
	
	x0=str2[p][0];
	y0=str2[p][1];
	que.push(TT(x0,y0,0));
	str4[x0][y0]=false;
	str0[x0][y0]='.';
	//printf("\nw=%d  h=%d  \n\n",w,h);
	while(!que.empty()){
		now=que.front();que.pop();
		x0=now.x;
		y0=now.y;
		s0=now.s;
		//printf("%d  %d  s=%d\n",x0,y0,s0);
		s1=s0+1;
		
		for(int i=0;i<4;i++){
			
			x1=x0+str3[i][0];
			y1=y0+str3[i][1];
			
			if(x1>=0 && x1<h && y1>=0 && y1<w && str4[x1][y1]){
				
				str4[x1][y1]=false;
				
				if(str0[x1][y1]=='.'){
						que.push(TT(x1,y1,s1));
				}else if(str0[x1][y1]=='x'){
					continue;
				}else{
					k++;
					k1=str0[x1][y1]-'0';
					str1[p][ k1 ]=s1;
					str1[k1][ p ]=s1;
					que.push(TT(x1,y1,s1));
				}
			}
		}
		
	}
	return k;
}

bool bulid(){
	num=init();
			//for(int i=0;i<num;i++){
		//		printf("%d:%d  %d\n",i,str2[i][0],str2[i][1]);
		//	}

//for(int i=0;i<h;i++){
//	printf("%s\n",str0[i]);
//}
/*
			for(int i=0;i<num;i++){
				for(int j=0;j<num;j++){
					printf("%d ",str1[i][j]);
				}
				printf("\n");
			}
*/
//	printf("num=%d\n",num);
	int k;
	for(int i=0;i<num;i++){
		k=find(i);
//		printf("k=%d\n",k);
		if(k+i<num)return false;
	}
	return true;
}

void dfs(int k,int sum,int lev){
	
	//printf("k=%d  sum=%d  lev=%d\n",k,sum,lev);
	
	if(sum>ans)return ;
	if(lev==num-1){
	//	printf("sum=%d  ans=%d\n",sum,ans);
		if(sum<ans)ans=sum;
		return ;
	}
	
	for(int i=1;i<num;i++){
		if(str5[i] && i!=k){
			str5[i]=false;
			dfs(i,sum+str1[k][i],lev+1);
			str5[i]=true;
		}
	}
}

int main()
{
	while(scanf("%d%d",&w,&h),w){
		for(int i=0;i<h;i++){
			scanf("%s",str0[i]);
		}
		if(bulid()){

			ans=4000;
			memset(str5,true,sizeof(str5));
			str5[0]=false;
			dfs(0,0,0);
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
