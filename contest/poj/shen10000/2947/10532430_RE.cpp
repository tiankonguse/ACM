#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
const int N=100;
#define LL int
LL gcd(LL a,LL b){
    if (a==0) return 1;
    if (a<0) return gcd(-a,b);
    while (b){
        LL t=a%b; a=b; b=t;
    }
    return a;
}
class Gauss{
	public:
	int matrix[N][N];
	int free_x[N];
	int ans[N];
	int n;
	int m;
	int make(int a,int b);
	void printMatrix();
	void setmatrix(int str[][N],int n,int m);
	int echelon_matrix();
	int getanswer();
}Mymatrix;
int Gauss::make(int a,int b){
    a = (a % 7 + 7)%7; 
	b = (b% 7 + 7)%7;
    for(int i = 0; i < 7; i++)
        if((a*i)%7 == b) return i;
}
void Gauss::printMatrix(){
	cout<<"\nbegin----->"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++){
			cout<<matrix[i][j]<<" ";
		}	
		cout<<endl;
	}	
	cout<<"end--->"<<endl;
}
void Gauss::setmatrix(int str[][N],int n,int m){
	this->m=m;
	this->n=n;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++){
			matrix[i][j]=str[i][j];
		}	
	}

}
int Gauss::getanswer(){
	int lev=echelon_matrix();
	int equ=m;
	int var=n;
	int tmp;
	int free_x_num=0,free_index;
	
	for(int i=lev;i<equ;i++){
		if(matrix[i][var]!=0)return -1;//无解 
	}
	
	if(lev<var){
		return 0;//多个解 
	}
	
	for(int i=var-1;i>=0;i--){
		tmp=matrix[i][var];
		for(int j=i+1;j<var;j++){
			tmp-=matrix[i][j]*ans[j];
		}
	//	if(tmp % matrix[i][i])return -1;//无整数解 
		ans[i]=make(matrix[i][i],tmp);
		//cout<<"ans["<<i<<"]="<<ans[i]<<endl;
	}
	return 1;	
}
int Gauss::echelon_matrix(){
	
	int equ=m;
	int var=n;
	
	int max_r;
	int col=0;
	int tmp,ta,tb;
	int k;
	for(k=0;k<equ && col<var ;k++,col++){
		
		max_r=k;
		
		for(int i=k+1;i<equ;i++){
			if(abs(matrix[i][col]) > abs(matrix[max_r][col]))max_r=i;
		}
		
		if(max_r != k){
			for(int j=k;j<var+1;j++)swap(matrix[k][j],matrix[max_r][j]);
		}
		if(matrix[k][col] == 0){k--;continue;}
		ta=matrix[k][col];
		for(int i=k+1; i<equ ;i++){
			if(matrix[i][col] != 0){
				tb=matrix[i][col];
				for(int j=col;j<=var;j++){
					matrix[i][j]=(matrix[i][j]*ta-matrix[k][j]*tb)%7;
				}
			}
			//printMatrix();
		}
		
	}
	//cout<<"k="<<k<<endl;
	return k;
}


int main()
{
   int i,j,k;
    int a,b,c,n,m;
    char first[5],last[5];
    int str[N][N];
    int week[300];
    week['O']=0;week['T']=1;week['E']=2;week['H']=3;week['R']=4;week['A']=5;week['S']=6;
    while(scanf("%d%d",&n,&m),n){
		
        memset(str,0,sizeof(str));
        for(i = 0; i <m; i++){
			scanf("%d%s%s",&k,first,last);

            a=(first[1]=='U')?week[first[0]]:week[first[1]];
            b=(last[1]=='U')?week[last[0]]:week[last[1]];
            str[i][n] = (b - a+8)%7;
            for(j = 0; j <k; j++){
                str[i][cin>>a,(a-1)]++;
            }
        }
        Mymatrix.setmatrix(str,n,m);
        //Mymatrix.printMatrix();
        int ok=Mymatrix.getanswer();
         
        if(ok==-1){
			printf("Inconsistent data.\n");
		}else if(ok==0){
			printf("Multiple solutions.\n");
		}else{
			    for(int i = 0; i <n; i++){
					Mymatrix.ans[i]%=7;
					if(Mymatrix.ans[i]<3)Mymatrix.ans[i]+=7;
					if(Mymatrix.ans[i]<3)Mymatrix.ans[i]+=7;
					if(i)putchar(' ');
					putchar('0'+Mymatrix.ans[i]);
				}	
				puts("");
			
    	}
    }
    return 0;
}
