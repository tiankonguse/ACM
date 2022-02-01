#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=65;
int st[N];
struct str{
	int lengh,num;
}str1[N];

int k,num,len;

int cmp(void const *b,void const *a)
{
	return (((struct str*)b)->lengh - ((struct str*)a)->lengh);		
}

void init(){
	k=0;
	memset(st,-1,sizeof(st));
}

bool dfs(int left,int i,int total){
	if(total==num)return true;
	
	for(int j=i;j<k;j++){
		int l=str1[j].lengh;
		int &numb=str1[j].num;
		if(numb==0)continue;
		if(l>left)return false;
		numb--;
		if(l==left){
			if(dfs(len,0,total+1))return true;
			numb++;
			return false;
		}
		
		if(dfs(left-l,j,total))return true;
		numb++;
		if(left==len || j+1==k)return false;
		
	}
	
	return false;
}

int main()
{
	int n;
	while(scanf("%d",&n),n){
		int sum=0;
		init();
		while(n--){
			scanf("%d",&len);
			sum+=len;
			if(st[len]=-1){str1[k].lengh=len;str1[k].num=1;st[len]=k;k++;}
			else {str1[st[len]].num++;}
		}
		qsort(str1,k,sizeof(struct str),cmp);
		
		len=str1[k-1].lengh;
		for(int i=len;i<=sum;i++){
			if(sum%i)continue;
			num=sum/i;
			len=i;
			if(dfs(len,0,0)){
				printf("%d\n",i);
				break;
			}
		}
		
	}
return 0;
}
