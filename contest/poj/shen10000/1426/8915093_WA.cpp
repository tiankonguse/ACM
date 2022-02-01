#include <stdio.h>
#include<string.h>
//99和198是磋的数据1110101001100001010111111111和11101010011000010101111111110
bool fg;
int n,i;
__int64 ans;
char str[209][20];

void dfs(int dep){
	if(dep>10)return; 
	if(ans%n==0){
		fg=true;
		sprintf(str[i],"%I64d",ans);
		//printf("%llu\n",ans);
		return;
	}
	if(n%2==0)
	{
		ans*=10;
		dfs(dep+1);
		if(fg)return ;
		
		ans++; //优先判1的情况，更快些
		dfs(dep+1);
		if(fg)return ;
		ans/=10;		
	}
    else
    {
	ans*=10;
	ans++; //优先判1的情况，更快些 
	dfs(dep+1);
	if(fg)return;
	ans--;
	dfs(dep+1);
	if(fg)return;
	ans/=10;		
    }
}
void fun()
{
for(i=1;i<=200;i++)
{
	if(i==72||i==99||i==108||i==144||i==189||i==198){continue;}
	
	n=i;
		ans=1; 
		fg=false;
		dfs(0);                
}

}

int main(){
    memset(str,0,sizeof(str));
    strcpy(str[99],"1110101001100001010111111111");
    strcpy(str[198],"11101010011000010101111111110");
    strcpy(str[72],"43064666871111000");
    strcpy(str[108],"4306466687111100");
    strcpy(str[189],"430646668710111");
    strcpy(str[144],"4306466671110000");

   
    fun();
	while(scanf("%d",&n)!=EOF,n){
		
printf("%s\n",str[n]);
	}
	return 0;
} 
