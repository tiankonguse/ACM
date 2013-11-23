#include <iostream>   
#include <algorithm> 
#include <functional> 
using namespace std;
int n;
int stick[70];
int used[70];
int num;
int length;
int quick[70];
bool dfs(int left,int i,int total)
{
	if (total == num)return true;

	for (int j = i; j <= n;j++)
	{
		if (left < stick[j] || used[j])continue;
		else if(left == stick[j])
		{
			used[j] = true;
			if (dfs(length, 1, total + 1))return true;
			else{return false;}
		}
		else
		{
			used[j] = true;
			if ( j + 1 <= n && dfs(left - stick[j], j + 1, total))return true;
			else
			{
				used[j] = false;
				
				if (left == length || j == n)return false;
				//在搜索一根全新的小棒不成功，那么停止搜索，剪枝//当j = n时候也停止搜索

				j = quick[j] - 1 ;
				//同样长的小棒不再同样搜索，掠过，剪枝，后面有j++，所以需要减一
			}
		}
	}			
	return false;
}
int main()   
{
	while (scanf("%d",&n) && n != 0)
	{
		int longest = 0,sum = 0;
		memset(stick,0,sizeof(stick));
		for (int i = 1; i <= n; i++)
		{		
			scanf("%d",&stick[i]);
			sum += stick[i];
			if (stick[i] > longest)
			{
				longest = stick[i];
			}
		}	
		sort(stick + 1,stick + 1 + n,greater<int>());

		{
			int began = 1;
			int temp = stick[n];stick[n] = -1;
			for (int i = 1; i < n ;i++)
			{
				if (stick[i] > stick[i + 1])
				{
					for ( int j = began; j <= i; j++)
					{
						quick[j] = i + 1;
					}
					began = i + 1;
				}
			}
			stick[n] = temp;
		}
		for (int i = longest; i <= sum; i++)
		{
			if (sum % i == 0)
			{
				memset(used,false,sizeof(used));
				num = sum / i;length = i;
				if (dfs(length,1,0))
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
} 
