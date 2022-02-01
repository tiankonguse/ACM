#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1024
int an[MAX_NUM+10];
//用以排序的比较函数
int MyCompare(const void *e1,const void *e2)
{
	return *((int *)e1)-*((int *)e2);
}

int main()
{
	int M;
	int m,n,k,i,j;
	
	//freopen("in.txt","r",stdin);

	scanf("%d",&M);
	for(m=0;m<M;m++)
	{
		scanf("%d%d",&n,&k);
		//排列存放在an[1],an[2],...an[n]
		for(i=1;i<=n;i++)
			scanf("%d",&an[i]);
		an[0]=100000;//确保an[0]比排列中所有的数都大
		for(i=0;i<k;i++) //每次循环都找出下一个排列
		{
			for(j=n;j>=1 && an[j-1]>an[j];j--);
			if(j>=1)
			{
				int nMinLarger=an[j];
				int nMinIdx=j;
				//下面找出从an[j]及其后最小的比an[j-1]大的元素，并记住其下标
				int kk;
				for(kk=j;kk<=n;kk++)
				{
					if(nMinLarger>an[kk] && an[kk]>an[j-1])
					{
						nMinLarger=an[kk];
						nMinIdx=kk;
					}
				}
				//交换位置
				an[nMinIdx]=an[j-1];
				an[j-1]=nMinLarger;
				qsort(an+j,n-j+1,sizeof(int),MyCompare);  //排序
			}
			else   //an里的排列已经是降序了，那么下一个排序就是1 2 3 ... n
			{
				for(j=1;j<=n;j++)
					an[j]=j;
			}
		}
		for(j=1;j<=n;j++)
			printf("%d ",an[j]);
		printf("\n");

	}
	return 0;
}