#include<iostream>
#include<queue>
#include<string>
using namespace std;
const int M=19000000;
const int N=20011239;
const int small=19000101;
int map[N-M];
int str[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
queue<int>que1,que2;

int toint(int y,int m,int d){
	return y*10000+m*100+d-M;	
}
bool isleap(int y){
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

bool todate(int &tmp,int now,int key){
	int y,m,d;
	now+=M;
	d=now%100;
	now/=100;
	
	m=now%100;
	
	y=now/100;
	
	if(key){
		if(d>1){
			d--; 
			tmp=toint(y,m,d); 
			if(map[tmp])return false;
			return true;
		}
		if(m>1){
			m--; 
			d=str[m]; 
			if(m==2 && isleap(y))d++; 
			tmp=toint(y,m,d); 
			if(map[tmp])return false;
			return true;
		}
		y--;m=12;d=31;
		tmp=toint(y,m,d);
		if(map[tmp] || y<1900)return false;
		return true;
	}else{
		m--;
		if(m==0){
			y--;
			m=12;
			tmp=toint(y,m,d);
			if(map[tmp] || y<1900)return false;
			return true;
		}
		if(d<=str[m]){
			tmp=toint(y,m,d);
			if(map[tmp])return false;
			return true;
		}
		if(m==2 && d==29 && isleap(y)){
			tmp=toint(y,m,d);
			if(map[tmp])return false;
			return true;
		}
		return false;
	}
	return false;
}

void init(){
	memset(map,0,sizeof(map));
	while(!que1.empty())que1.pop();
	while(!que2.empty())que2.pop();
	int now=toint(2001,11,4);
	int tmp,y,m,d;
	map[now]=2;
	//printf("%d %d\n",now,map[now]);
	que2.push(now);
	while(!que1.empty() || !que2.empty()){
		if(!que1.empty()){
			while(!que1.empty()){
				now=que1.front();
				que1.pop();
				if(todate(tmp,now,1)){
					map[tmp]=2;
					que2.push(tmp);
				}
			}

		}else{
			while(!que2.empty()){
				now=que2.front();
				que2.pop();
				if(todate(tmp,now,1)){
					map[tmp]=1;
					que1.push(tmp);
				}
				if(todate(tmp,now,0)){
					map[tmp]=1;
					que1.push(tmp);
				}
			}
		}
		
	}
	
}

int main()
{
init();	
int tmp,n,y,m,d;
scanf("%d",&n);
while(n--){
	scanf("%d%d%d",&y,&m,&d);
	tmp=toint(y,m,d);
	printf("%s\n",map[tmp]-1?"NO":"YES");
}
return 0;	
}
