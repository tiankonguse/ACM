#include<string>
#include<queue>
#include<iostream>
using namespace std;
const int N=1111;
struct pot{
	struct pot* pre;
	char s[20];
	int num;
	bool yes;
	int x,y;	
}str[N][N],*ans,now;
int a,b,c;
queue<pot>que;

bool ones(){
	if(b==c){
		printf("fill B\n");
		printf("success\n");
		return true;
	}else{
		return false;
	}
	
}

void init(){
	for(int i=0;i<=a;i++)
	for(int j=0;j<=b;j++){
		str[i][j].yes=false;
		str[i][j].pre=NULL;
		str[i][j].x=i;
		str[i][j].y=j;
	}
	while(!que.empty())que.pop();
	ans=NULL;
}

void add(int x,int y,char *s){
	str[x][y].yes=true;
	str[x][y].pre=&str[now.x][now.y];
	str[x][y].num=now.num+1;
	strcpy(str[x][y].s,s);
	que.push(str[x][y]);
}

bool ok(int x,int y){
	if(y==c)return true;
	return false;
}

void fill_a(){
	
	if(now.x==a || str[a][now.y].yes)return ;
	
	add(a,now.y,"fill A");
}

void fill_b(){

	if(now.y==b || str[now.x][b].yes)return ; 
	
	add(now.x,b,"fill B");
}
void empty_a(){
	
	if(now.x==0 || str[0][now.y].yes)return ;
	
	add(0,now.y,"empty A");
}

void empty_b(){
	
	if(now.y==0 || str[now.x][0].yes)return ;
	
	add(now.x,0,"empty B");
}

bool pour_atob(){
	if(now.x==0 || now.y==b)return false;
	int x,y;
	int tmp=b-now.y;
	if(tmp>=now.x){
		x=0;
		y=now.x+now.y;
	}else{
		x=now.x-tmp;
		y=b;
	}
	
	if(str[x][y].yes)return false;
	add(x,y,"pour A B");
	
	if(ok(x,y)){ans=&str[x][y];return true;}
	
	return false;
}

bool pour_btoa(){
	if(now.y==0 || now.x==a)return false;
	int x,y;
	int tmp=a-now.x;
	if(tmp>=now.y){
		y=0;
		x=now.x+now.y;
	}else{
		y=now.y-tmp;
		x=a;
	}
	
	if(str[x][y].yes)return false;
	add(x,y,"pour B A");
	
	if(ok(x,y)){ans=&str[x][y];return true;}
	
	return false;
}
void print(pot* p){
	if(p->num==0)return ;
	print(p->pre);
	printf("%s\n",p->s);
}
int main()
{
	
	while(~scanf("%d%d%d",&a,&b,&c)){

		if(ones())continue;

		init();
		str[0][0].yes=true;
		str[0][0].num=0;
		que.push(str[0][0]);

		while(!que.empty()){
			now=que.front();
			que.pop();
			fill_a();
			fill_b();
			empty_a();
			empty_b();
			if(pour_atob())break;
			if(pour_btoa())break;
		}
			print(ans);

		printf("success\n");
		
	}

return 0;
}
