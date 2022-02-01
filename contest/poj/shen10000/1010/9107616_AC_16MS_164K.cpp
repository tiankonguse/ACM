#include<iostream>
#include<algorithm>
using namespace std;

//不同种类的面值，先前最佳可行解，当前解
int kind[100],pre[4],cur[4];
//种类，需求，先前已存在最佳解的种类数、张数、单张最大面值
int types,need,prekind,prenum,preval;
//最佳方案的个数
int tienum;


void dfs(int k, int lastgetkind, int curkind ,int curnum, int curval, int cost)
{
	if(curnum>4 || (curnum==4) && cost!=need)return;
	
	if(cost == need)
	{
		if(prekind==0||
		   curkind>prekind||
		   (curkind==prekind && curnum<prenum)||
		   (curkind==prekind && curnum==prenum && curval>preval))
		{
			prekind=curkind;
			prenum=curnum;
			preval=curval;
			
			for(int i=0;i<curnum;i++)
			    pre[i]=cur[i];
			    
			tienum=1;
			
		}
		else if(curkind==prekind && curnum==prenum && curval==preval)
		    tienum++;
		return ;
	}
	for(int i=k;i<types;i++)
	{
		if(cost+kind[i]>need)break;
		int Kind=curkind,Val=curval;
		if(lastgetkind!=i)Kind=curkind+1;
		if(curval<kind[i])Val=kind[i];
		cur[curnum]=kind[i];
		dfs(i,i,Kind,curnum+1,Val,cost+kind[i]);	
	}	
		
		
	
}

int main()
{
char str[100];
while(scanf("%d",&kind[0])!=EOF)
{

	types=0;
	while(kind[types])
	    scanf("%d",&kind[++types]);

gets(str);
	sort(kind,kind+types);	
	
	while(scanf("%d",&need),need)
	{
		prekind=prenum=preval=0;	
		tienum=1;
		
		dfs(0,-1,0,0,0,0);
			
		if(prekind==0)printf("%d ---- none\n",need);
		else if(tienum>1)printf("%d (%d): tie\n",need,prekind);
		else
		{
			int i;
			printf("%d (%d): ",need,prekind);
			for(i=0;i<prenum-1;i++)
			    printf("%d ",pre[i]);
			printf("%d\n",pre[i]);
			
			
		}
	}

	gets(str);

}
return 0;
}
