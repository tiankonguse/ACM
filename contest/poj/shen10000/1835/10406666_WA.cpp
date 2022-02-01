#include<string>
#include<iostream>
using namespace std;
int x,y,z;
int myf,myu,myr;
int map[8]={3,4,5,0,1,2};

void myfun(char c){
	int tmp;
			switch(c){
				case 'f':
				break;
				case 'b':
					myf=map[myf];
					myr=map[myr];
				break;
				case 'l':
					tmp=myf;
					myf=map[myr];
					myr=tmp;
				break;
				case 'r':
					tmp=myf;
					myf=myr;;				
				break;
				case 'u':
					tmp=myf;
					myf=myu;
					myu=map[tmp];				
				break;
				case 'd':
					tmp=myf;
					myf=map[myu];
					myu=tmp;
				break;
			}
}

int main()
{
char str[100];
int len;
	int n;
	int m;
	scanf("%d",&n);
	while(n--){
		x=y=z=0;
		myf=0;
		myr=1;
		myu=2;
		scanf("%d",&m);
		while(m--){
			scanf("%s%d",str,&len);
			myfun(str[0]);
			switch(myf){
				case 0:x+=len;break;
				case 1:y+=len;break;
				case 2:z+=len;break;
				case 3:x-=len;break;
				case 4:y-=len;break;
				case 5:z-=len;break;
			}
		}

		
		
		printf("%d %d %d %d\n",x,y,z,myf);
	}
return 0;
}
