/*************************************************************************
    > File Name: I Imagine.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 20:36:30
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 1500;
const int XY = 1024;
int c[N][N];
int old[N][N];
const int A = 0;
const int B = 1;
int Lowbit(int t){ return t & -t;}
int Row = XY;
int Col = XY;
int Sum(int i, int j){
	int tempj, sum = 0;
	while( i > 0 ){
		tempj = j;
		while( tempj > 0 ){
			sum += c[i][tempj];
			tempj -= Lowbit(tempj);
		}
		i -= Lowbit(i);
	}
return sum;
}

void Update(int i, int j, int num){
	int tempj;
	while( i <= Row ){
		tempj = j;
		while( tempj <= Col ){
			c[i][tempj] += num;
			tempj += Lowbit(tempj);
		}
		i += Lowbit(i);
	}
}
int main() {
    int n,x0,y0,x1,y1,i,j;
    int left_top_A,left_A,top_A,all_A,left_top_B,left_B,top_B,all_B;
    char op[5];
    while(~scanf("%d",&n)){
        memset(c,0,sizeof(c));
        for(i=1;i<=XY;i++){
            for(j=1;j<=XY;j++){
                old[i][j] = (i+j)%2;
                if(old[i][j]){
                    Update(i,j,old[i][j]);
                }

            }
        }
        while(n--){
            scanf("%s",op);
            if(op[0] == 'R'){
                scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
                all_B = Sum(x1,y1);
                left_B = Sum(x0-1,y1);
                top_B = Sum(x1,y0-1);
                left_top_B = Sum(x0-1,y0-1);

                all_A = x1*y1 - all_B;
                left_A = (x0-1)*y1 - left_B;
                top_A = x1*(y0-1)-top_B;
                left_top_A = (x0-1)*(y0-1)-left_top_B;
                printf("%d %d\n",all_A-left_A-top_A+left_top_A,all_B-left_B-top_B+left_top_B);
            }else if(op[0] == 'A'){
                scanf("%d%d",&x0,&y0);
                if(old[x0][y0] == A)continue;
                old[x0][y0] = A;
                Update(x0,y0,-1);
            }else{
                scanf("%d%d",&x0,&y0);
                if(old[x0][y0] == B)continue;
                old[x0][y0] = B;
                Update(x0,y0,1);
            }
        }
    }
    return 0;
}
