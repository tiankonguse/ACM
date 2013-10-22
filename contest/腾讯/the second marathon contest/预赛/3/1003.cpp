#include<cstdio>
#include<cstring>

const int N = 2002;

char str[N][N];

int n,m,x,y,ans;

// a[1...m][1...n]


void mycol(int i,int* col){
    //printf("%d : ",i);
	for(int j = 0, k; j < n; ++j){
		if(str[i][j] =='.'){
            col[j] = 0;
		}else if( i==0 || str[i-1][j] == '.'){
			for(k = i + 1; k < m && str[k][j] == '*'; ++k);
			col[j]=k;
		}
		//printf("%d ",col[j]);
	}
	//printf("\n");
}

void Run(){
	int  i, j, l, r, max = 0,tmpx,tmpy,k;
	int col[N];

	for(i = 0; i < m; ++i){
		mycol(i,col);
		tmpx = i + x;

		for(j = y - 1; j < n; ++j){
            if( col[j] >= tmpx){
                for( l = j - 1, k = 1; l >= 0 && col[l] >= tmpx && k < y; --l, ++k);
                if(k == y)ans ++;
            }
		}
		if(x != y){
		    tmpy = i + y;
            for(j = x - 1; j < n; ++j){
                if( col[j] >= tmpy){
                    for( l = j - 1, k = 1; l >= 0 && col[l] >= tmpy && k < x; --l,++k);
                    if(k == x)ans ++;
                }
            }
		}
	}

}

int main(){

    while(scanf("%d%d",&m,&n),n){
        scanf("%d%d",&x,&y);

        for(int i=0;i<m;i++){
            scanf("%s",str[i]);
        }

        ans = 0;
        Run();

        printf("%d\n",ans);

    }



    return 0;
}
