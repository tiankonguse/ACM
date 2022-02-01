#include<string>
#include<queue>
#include<iostream>
using namespace std;
const int N=65555;//65535--0
bool map[N];
int num[N];
queue<int>que;
bool game[5][5];
int ban[5][5];
int now;
int zh[6][3]={{-1,0},{0,-1},{0,0},{0,1},{1,0}};

void init(){
	//printf("ban[][]\n");
	for(int i=0,p=1;i<4;i++){
		for(int j=0;j<4;j++){
			ban[i][j]=p;
			p<<=1;
		//	printf("%7d ",ban[i][j]);
		}
	//	printf("\n");
	}
	memset(map,false,sizeof(map));
	while(!que.empty())que.pop();
}

int read(){
	char str[6];
	int sum=0;
	int p=1;
	for(int i=0;i<4;i++){
		scanf("%s",str);
		for(int j=0;j<4;j++){
			if(str[j]=='w')sum+=p;
			p<<=1;
		}
	}
	return sum;	
}

bool ok(int now){
	if(now==0 || now==65535)return true;
	return false;
}

void togame(){
	int k=now;
	for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		game[i][j]=k&1;
		k>>=1;
		//printf("%d",game[i][j]);
	}
	//printf("\n");		
	}

}

int flip(int x,int y){
	int tmp=now;
	int x0,y0;
	for(int i=0;i<5;i++){
		x0=x+zh[i][0];
		y0=y+zh[i][1];
		if(x0<0 || y0<0 || x0>=4 || y0>=4)continue;
		if(game[x0][y0]){
			tmp-=ban[x0][y0];
		}else{
			tmp+=ban[x0][y0];
		}
	}
	return tmp;
}

int main()
{
	int ans=-1;
	init();
	now=read();
//	printf("%d\n",now);
	if(ok(now))ans=0;
	else{
		map[now]=true;
		num[now]=0;
		que.push(now);
		while(!que.empty()){
			
			now=que.front();
			que.pop();
			togame();
			//printf("now=%d\n",now);
			for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				
				int tmp=flip(i,j);
				
				//printf("%d\n",tmp);
				
				if(map[tmp])continue;
				
				num[tmp]=num[now]+1;
				map[tmp]=true;
				if(ok(tmp)){ans=num[tmp];goto over;}
				
				que.push(tmp);
				
			}
		}
	}
	over:
	if(ans==-1){
		printf("0\n");
	}else{
		printf("%d\n",ans);
	}
scanf("%d",&now);
return 0;
}
