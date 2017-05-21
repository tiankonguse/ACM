#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
#define MAXN 10
#define MAXR 4005
#define MAXS 10
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
char res[MAXR][MAXS];
char mat[MAXN][MAXN];
char c;
int cnt;
int row[MAXN],col[MAXN],dia1[MAXN*3],dia2[MAXN*3];
int cmp(const void *a, const void *b)
{
  char *x=(char *)a;
	char *y=(char *)b;
	return strcmp(x,y);
}
bool check(int x0,int y0,int x,int y,int c){
    int l,r;
    if(x>=0 && y>=0 && x<8 && y<8 && mat[x][y]!=c){
        if(y0==y){
            l=min(x0,x);
            r=max(x0,x);
            for(int i=l+1;i<r;i++){
                if(mat[i][y]!=c && mat[i][y]!='.')return false;
            }
            return true;
        }
        else if(x0==x){
            l=min(y0,y);
            r=max(y0,y);
            for(int i=l+1;i<r;i++){
                if(mat[x][i]!=c && mat[x][i]!='.')return false;
            }
            return true;
        }
        else if(x0+y0==x+y){
            int s=x+y;
            l=min(y0,y);
            r=max(y0,y);
            for(int i=l+1;i<r;i++){
                if(mat[s-i][i]!=c && mat[s-i][i]!='.')return false;
            }
            return true;
        }
        else if(y0-x0==y-x){
            int s=y-x;
            l=min(x0,x);
            r=max(x0,x);
            for(int i=l+1;i<r;i++){
                if(mat[i][i+s]!=c && mat[i][i+s]!='.')return false;
            }
            return true;
        }
    }
    else return false;
}
void make(int i1,int j1,int i2,int j2){
    res[cnt][0]='A'+i1;
    res[cnt][1]='1'+j1;
    res[cnt][2]='-';
    res[cnt][3]='A'+i2;
    res[cnt][4]='1'+j2;
    cnt++;
}
int main(){
    bool f=false;
    while(~scanf(" %s",mat[0])){
        for(int i=1;i<8;i++)scanf(" %s",mat[i]);
        scanf(" %c",&c);
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(dia1,0,sizeof(dia1));
        memset(dia2,0,sizeof(dia2));
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(mat[i][j]!='.'){
                    row[i]++;
                    col[j]++;
                    dia1[i+j]++;
                    dia2[i-j+7]++;
                }
            }
        }
        cnt=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(mat[i][j]==c){
                    if(check(i,j,i-col[j],j,c)){
                        make(i,j,i-col[j],j);
                    }
                    if(check(i,j,i+col[j],j,c)){
                        make(i,j,i+col[j],j);
                    }
                    if(check(i,j,i,j-row[i],c)){
                        make(i,j,i,j-row[i]);
                    }
                    if(check(i,j,i,j+row[i],c)){
                        make(i,j,i,j+row[i]);
                    }
                    if(check(i,j,i+dia1[i+j],j-dia1[i+j],c)){
                        make(i,j,i+dia1[i+j],j-dia1[i+j]);
                    }
                    if(check(i,j,i-dia1[i+j],j+dia1[i+j],c)){
                        make(i,j,i-dia1[i+j],j+dia1[i+j]);
                    }
                    if(check(i,j,i-dia2[i-j+7],j-dia2[i-j+7],c)){
                        make(i,j,i-dia2[i-j+7],j-dia2[i-j+7]);
                    }
                    if(check(i,j,i+dia2[i-j+7],j+dia2[i-j+7],c)){
                        make(i,j,i+dia2[i-j+7],j+dia2[i-j+7]);
                    }
                }
            }
        }
        if(f)printf("\n");
        f=true;
        if(cnt==0)printf("No moves are possible\n");
        else{
            qsort(res,cnt,sizeof(res[0]),cmp);
            for(int i=0;i<cnt;i++){
                printf("%s\n",res[i]);
            }
        }
    }
    return 0;
}
