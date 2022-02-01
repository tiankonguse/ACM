#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define N 350
int n,m;
int matrix[N][N];
int st[N],ans[N];

int week[300];
int find(int a, int y)
{
    int i,j;
    y = (y % 7 + 7)%7; 
	a = (a % 7 + 7)%7;
    for(i = 0; i < 7; i++)
        if((a*i)%7 == y) return i;
}

int Gauss()
{
    int i,j,k;
    int row,col,ta,tb,sum;

    row = 1; col = 1;
    while(row <= m && col <= n){
        for(i = row, j = 0; i <= m; i++)
            if(matrix[i][col] != 0) {j = i; break;}
            
        if(j == 0) {col++;continue;}
        
        for(i = col; i <= n+1; i++)swap(matrix[row][i],matrix[j][i]);
  
        ta = matrix[row][col];
        for(i = row+1; i <= m; i++)
        {
            tb = matrix[i][col];
            for(j = col; j <= n+1; j++)
                matrix[i][j] = (matrix[i][j]*ta-matrix[row][j]*tb)%7;
        }
        st[row] = col;
        row++; col++;
    }
// 1. 无解的情况
    for(i = row; i<= m; i++)
    	if(matrix[i][n+1] != 0){
            return -1;
        }
//2. 无穷解的情况
    if(row != col || col <= n){
        return 0;
    }
// 3. 唯一解的情况
    ta = row-1; tb = n;
    while(ta >= 1)
    {
        sum = 0;
        for(i = tb+1; i <= n; i++)
            sum = sum + ans[i]*matrix[ta][i];
        ans[tb] = find(matrix[ta][tb],matrix[ta][n+1] - sum);
        ta--; tb--;
    }

        return 1;
}

int main()
{
    int i,j,k;
    int a,b,c;
    char first[5],last[5];
    
    week['O']=0;week['T']=1;week['E']=2;week['H']=3;week['R']=4;week['A']=5;week['S']=6;
    while(scanf("%d%d",&n,&m),n){
		
        memset(matrix,0,sizeof(matrix));
        for(i = 1; i <= m; i++){
			scanf("%d%s%s",&k,first,last);

            a=(first[1]=='U')?week[first[0]]:week[first[1]];
            b=(last[1]=='U')?week[last[0]]:week[last[1]];

            matrix[i][n+1] = b - a+1;
            
            for(j = 1; j <= k; j++){
                matrix[i][cin>>a,a]++;
            }
            
            for(j = 1; j <= n; j++)
               matrix[i][j] %=7;
        }
        int ok=Gauss();
        
        if(ok==-1){
			printf("Inconsistent data.\n");
		}else if(ok==0){
			printf("Multiple solutions.\n");
		}else{
			    for(int i = 1; i <= n; i++){
					ans[i]%=7;
					if(ans[i]<3)ans[i]+=7;
					if(ans[i]<3)ans[i]+=7;
					if(i>1)putchar(' ');
					putchar('0'+ans[i]);
				}	
				puts("");
			
    	}
    }
    return 0;
}
