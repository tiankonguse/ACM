#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
const int N=350;

class Gauss{
	int var,equ;//有equ个方程，var个变元。
	int matrix[N][N],free_x[N],ans[N];// matrix为增广矩阵，ans为解集,free_x判断是否是不确定的变元.
	public:
	void init(int n,int m){this->equ=m;this->var=n;memset(matrix,0,sizeof(matrix));}
	int getanswer();
	//高斯消元法解方程组(Gauss-Jordan elimination).
	//(-2表示有浮点数解，但无整数解，-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
};

int Gauss::getanswer(){
	int tmp;
	int max_r,ta,tb,k,col=0;
	//// 转换为阶梯阵.
	for(k=0;k<equ && col<var ;k++,col++){
		max_r=k;//找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
		for(int i=k+1;i<equ;i++){
			if(abs(matrix[i][col]) > abs(matrix[max_r][col]))max_r=i;
		}
		
		if(max_r != k){// 与第k行交换
			for(int j=k;j<var+1;j++)swap(matrix[k][j],matrix[max_r][j]);
		}
		//// 说明该col列第k行以下全是0了，则处理当前行的下一列 	
		if(matrix[k][col] == 0){k--;continue;}
		
		ta=matrix[k][col];
		//之后列的要化为0 
		for(int i=k+1; i<equ ;i++){
			if(matrix[i][col] != 0){
				tb=matrix[i][col];
				for(int j=col;j<=var;j++){
					matrix[i][j]=matrix[i][j]*ta-matrix[k][j]*tb;
				}
			}
		}
		
	}
	//// 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0). 
	for(int i=k;i<equ;i++){
		if(matrix[i][var]!=0)return -1;//无解 
	}

	// 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.    
	// 且出现的行数即为自由变元的个数.
	if(k!=col || col<var){
		
		int free_x_num=0,free_index;
		for(int i=k-1;i>=0;i--,free_x_num=0){
// 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.            
// 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
// free_x_num用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
			for(int j=0;j<var;j++){
				if(matrix[i][j] && free_x[j])free_x_num++,free_index=j;
			}
			
			if(free_x_num>1)continue;// 无法求解出确定的变元.
// 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
			tmp=matrix[i][var];
			
			for(int j=0;j<var;j++){
				if(matrix[i][j] && j!=free_index)tmp-=matrix[i][j]*ans[j];
			}
			
			ans[free_index]=tmp/matrix[i][free_index];// 求出该变元
			
			free_x[free_index]=0;// 该变元是确定的.
			
		}
		return var - k;// 自由变元有var - k个.
	}
// 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.    
// 计算出Xn-1, Xn-2 ... X0.
	for(int i=var-1;i>=0;i--){
		tmp=matrix[i][var];
		for(int j=i+1;j<var;j++){
			tmp-=matrix[i][j]*ans[j];
		}
		if(tmp % matrix[i][i])return -1;// 说明有浮点数解，但无整数解.
		ans[i]=tmp/matrix[i][i];
	}
	return 0;	
}



int main()
{


    return 0;
}
