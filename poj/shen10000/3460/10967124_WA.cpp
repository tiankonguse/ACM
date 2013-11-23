#include<stdio.h>
#include<string.h>

/*
 *  IDA*算法
 *	解题思路：使用迭代加深的深度搜索算法，这里非常要注意还是剪枝的问题
 *	只有较好的针对题目环境的剪枝，才能提高搜索效率
*/

//使用数组表示游戏局面
int map[25],n;
//搜索深度
int DEPTH;

//估计函数
int hfunc(){
	int i,ans=0;
	for(i=0;i<n;i++){
		if(map[i]+1 != map[i+1]){
			ans++;
		}
	}

	return ans;
}
//更新状态
void changeState(int x1,int x2,int x3){
	int tmp[25],i,j;
	for(i=x1;i<=x2;i++){
		tmp[i]=map[i];
	}
	for(i=x2+1,j=x1;i<=x3;i++,j++){
		map[j]=map[i];
	}
	for(i=x1;i<=x2;i++,j++){
		map[j]=tmp[i];
	}

}

bool dfsSearch( int currDepth) {

	int x1,x2,x3,h;
	for(x1=0;x1<n-1;x1++){
		for(x2=x1;x2<n-1;x2++){
			for(x3=x2+1;x3<n;x3++){
				changeState(x1,x2,x3);
				h=hfunc();
				if(h==0)return false;
				else if(3*currDepth +  h <= 3*DEPTH){
					if(!dfsSearch(currDepth+1))return false;
				}
				changeState(x1,x1-x2+x3-1,x3);
			}
		}
	}

	return true ;
}


void ida(){

         //起始状态就是目标状态
         DEPTH = (hfunc()+2)/3;
         while(DEPTH < 5 && dfsSearch(1))DEPTH++;

		if(DEPTH == 5){
			printf("5 or more\n");
		}
		else{
			printf("%d\n",DEPTH);
		}
}

int main(){
	int cas,i;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&map[i]);
		}
		map[n]=n+1;
		ida();
	}

	return 0;
}
