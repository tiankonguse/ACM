#include <stdio.h>
#include <string.h>

bool fg;
int n,i;
unsigned long long ans;
char str[205][22];
void dfs(int dep){
	if(dep>18)return; 
	if(ans%n==0){
		fg=true;
		printf("%llu\n",ans);
	//	sprintf(str[i],"%llu",ans);
		return;
	}
	ans*=10;
	ans++; //优先判1的情况，更快些 
	dfs(dep+1);
	if(fg)return;
	ans--;
	dfs(dep+1);
	if(fg)return;
	ans/=10;
}




int main(){
//	memset(str,0,sizeof(str));
/*	for(i=1;i<=200;i++)
	{
		n=i;
		ans=1; 
		fg=false;
		dfs(0);		
	}
*/	
	while(scanf("%d",&n)!=EOF,n){
         //printf("%s\n",str[n]);
      	ans=1; 
		fg=false;
		dfs(0);	   
         
         
	}
	return 0;
} 

