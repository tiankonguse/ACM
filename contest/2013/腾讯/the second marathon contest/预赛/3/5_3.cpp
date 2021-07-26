#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;


int mapx[9]={-2, -1, -1,  0, 0,  1, 1, 2};
int mapy[9]={ 0, -1,  1, -2, 2, -1, 1, 0};

const int N = 1100;
int pic[N][N],flag[N],link[N];
int str[N][N];

bool find(int x){
	int j;
	for(int i=1;i<=pic[x][0];i++){
		j=pic[x][i];
		if(!flag[j]){
			flag[j]=1;
			if(link[j]==-1 || find(link[j])){
				link[j]=x;
				return true;
			}
		}
	}
	return false;
}
int main() {
    int i,j,x,y, n,m,k,tmp,ans,num;
    while (scanf("%d%d",&n,&m)!=EOF) {

        num = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&str[i][j]);
                if(str[i][j]){
                    str[i][j]= ++num;
                }
            }
        }

		memset(pic,0,sizeof pic);
		for(i=0;i<num;i++){
			link[i]=-1;
		}

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                //printf("%d ",str[i][j]);
                if(str[i][j]){
                    tmp = str[i][j]-1;
                    for(k=0;k<8;k++){
                        if(i+mapx[k]>=0 && i+mapx[k]<n && j+mapy[k]>=0 && j+mapy[k]<m && str[i+mapx[k]][j+mapy[k]]){
                            pic[tmp][0]++;
                            pic[tmp][pic[tmp][0]] = str[i+mapx[k]][j+mapy[k]]-1;
                        }
                    }
                }
            }
            //printf("\n");
        }
		ans=0;
		for(i=0;i<num;i++){
			memset(flag,0,sizeof flag);
			if(find(i))
				ans++;
		}
		printf("%d\n",num-(ans+1)/2);
    }
    return 0;
}
/*
2 3
1 0 1
0 1 0
*/
