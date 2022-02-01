#include<string>
#include<iostream>
using namespace std;
int map0[11]={72930,65,13090,15470,1365,9282,102102,130,510510,46410};
int str[5][12];
bool map1[5][12];
char tmp[4][30];
int ans[5],acc;
int fans[4];
int add(int p){
	int sum=1;
	if(tmp[0][p+1]!=' ')sum*=2;
	if(tmp[1][p  ]!=' ')sum*=3;
	if(tmp[1][p+2]!=' ')sum*=5;
	if(tmp[1][p+1]!=' ')sum*=7;
	if(tmp[2][p  ]!=' ')sum*=11;
	if(tmp[2][p+2]!=' ')sum*=13;
	if(tmp[2][p+1]!=' ')sum*=17;
	return sum;
}

bool ok(){
	int xs=ans[0]*10+ans[1];
	if(xs>=24)return false;
	int fz=ans[2]*10+ans[3];
	int all=xs*60+fz-15;
	if(all<0)all+=1440;
	xs=all/60;
	fz=all%60;
	if(map1[0][xs/10]==0)return false;
	if(map1[1][xs%10]==0)return false;
	if(map1[2][fz/10]==0)return false;
	if(map1[3][fz%10]==0)return false;
	for(int i=0;i<4;i++)fans[i]=ans[i];

	return true;
}

void dfs(int lev){
	if(lev==4){
		if(ok())acc++;
		return ;
	}
	for(int i=1;i<str[lev][0];i++){
		ans[lev]=str[lev][i];
		if(acc==2)return ;
		dfs(lev+1);
	}
}

int main()
{
int left[4],right[4];
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		int k=3;
		for(int i=0;i<k;i++){
			gets(tmp[i]);
		}
	
		for(int i=0,j=13;i<4;i++,j+=3){
			left[i]=add(i*3);
			right[i]=add(j);
		}
		
		for(int i=0;i<4;i++){
			int k=1;
			for(int j=0;j<10;j++){
				if((i==0 || i==2) && j>=6)break;
				if(map0[j]%left[i]==0)str[i][k++]=j;
			}
			str[i][0]=k;

		}
		
//		printf("\n");
//		for(int i=0;i<4;i++){
//			printf("%d--->",str[i][0]-1);
//			for(int j=1;j<str[i][0];j++)
//				printf(" %d ",str[i][j]);
//			printf("\n");
//
//		}
		memset(map1,false,sizeof(map1));
		for(int i=0;i<4;i++)
			for(int j=0;j<10;j++){
				if(i==0 && j>=3)break;
				if(i==2 && j>=6)break;
				if(map0[j]%right[i]==0)map1[i][j]=1;
			}
//		printf("5--->");
//		for(int j=0;j<10;j++){
//			printf(" %d ",j);
//
//		}
//		printf("\n");
//		for(int i=0;i<4;i++){
//			printf("%d--->",i);
//			for(int j=0;j<10;j++){
//				printf(" %d ",map1[i][j]);
//			}
//			printf("\n");
//		}
		acc=0;
		dfs(0);
//		printf("acc=%d\n",acc);
		if(acc==1){
			for(int i=0;i<4;i++)
			printf("%d",fans[i]);
			printf("\n");
		}else{
			printf("Not Sure\n");
		}
		
	//	for(int i=0;i<k;i++){
//			printf("%s\n",tmp[i]);
//		}
	}
return 0;
}
/*
    _  _  _      _     _ 
  | _  _||       _   ||  
  | _ |_   |   | _    |_|

*/
