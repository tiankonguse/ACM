#include<iostream>
#include<queue>
#include<string>
using namespace std;
const int N=20011104;
const int M=19000101;
const int JIE=N-M;
int map[N-M+10000];
int str[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int toint(int y,int m,int d){
	return y*10000+m*100+d-M;	
}
bool isleap(int y){
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

void today(int&y,int& m,int&d ,int now){
	now+=M;
	d=now%100;now/=100;
	m=now%100;
	y=now/100;
}

bool nextday(int &tmp,int now){
	int y,m,d;
	today(y,m,d,now);
	d++;
//	printf("y=%d  m=%d  d=%d   %d\n",y,m,d,now+M);
	tmp=toint(y,m,d);
//	printf("%d %d  \n",now,tmp);
	if(tmp>JIE)return false;//day的越界没有进位 
	if(d<=str[m])return true;	//不考虑二月闰年，未进位月
	//printf("goto\n");
	if(m==2 && d==29 && isleap(y)) return true;//单独考虑二月闰年不需进位 
	m++;d=1;//剩下的就全是需要进位的 
	if(m==13) {y++;m=1;}//年进位的 
	tmp=toint(y,m,d);return true;
}
bool nextmounth(int &tmp,int now){
	int y,m,d;
	today(y,m,d,now);
	m++;
	tmp=toint(y,m,d);
	if(tmp>JIE)return false;//mounth的越界没有进位 
	if(m==13){y++,m=1;tmp=toint(y,m,d);return true;}
	if(d<=str[m])return true;
	if(m==2 && d==29 && isleap(y))return true;
	return false;
}

bool ok(int now){
	
	if(map[now])return map[now]-1;
	int nd,nm,nn;
	bool hd=nextday(nd,now);
	bool hm=nextmounth(nm,now);
	//printf("%d  %d %d  %d  %d \n",now,nd,hd,nm,hm);
	if(hd && hm){
		map[now]=!(ok(nd)&ok(nm))+1;
	}else if(hd){
		map[now]=!ok(nd)+1;
	}else if(hm){
		map[now]=!ok(nm)+1;
	}
	
	return map[now]-1;
}


int main()
{
memset(map,0,sizeof(map));
map[toint(2001,11,4)]=1;
int n,y,m,d;
scanf("%d",&n);
while(n--){
	scanf("%d%d%d",&y,&m,&d);
	printf("%s\n",ok(toint(y,m,d))?"YES":"NO");
}
return 0;	
}
