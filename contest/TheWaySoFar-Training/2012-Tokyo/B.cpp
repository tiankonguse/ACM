#include <cstdio>
#include <cstring>
char str1[20][100],str2[20][100];
int p,q,a[6],ans[100];
void work(int x)
{
    int len = strlen(str1[x]);
    for(int i = 0; i < len; ++i){
        if(str1[x][i] == '(') ++a[0];
        if(str1[x][i] == ')') ++a[1];
        if(str1[x][i] == '[') ++a[2];
        if(str1[x][i] == ']') ++a[3];
        if(str1[x][i] == '{') ++a[4];
        if(str1[x][i] == '}') ++a[5];
    }
}
void work2(int x)
{
    int len = strlen(str2[x]);
    for(int i = 0; i < len; ++i){
        if(str2[x][i] == '(') ++a[0];
        if(str2[x][i] == ')') ++a[1];
        if(str2[x][i] == '[') ++a[2];
        if(str2[x][i] == ']') ++a[3];
        if(str2[x][i] == '{') ++a[4];
        if(str2[x][i] == '}') ++a[5];
    }
}
bool check(int r,int c,int s)
{
    memset(a,0,sizeof(a));
    work(1);
    for(int i = 2; i <= p; ++i){
        int tmp = r * (a[0] - a[1]) + c * (a[2] - a[3]) + s * (a[4] - a[5]);
        int cnt = 0;
        int len = strlen(str1[i]);
        for(int j = 0; j < len; ++j)
            if(str1[i][j] == '.') ++cnt;
            else break;
        work(i);
        if(cnt != tmp) return 0;
    }
    return 1;
}
void calc(int r,int c,int s)
{
	//for(int i = 0; i < 6; ++i) printf("%d ",a[i]);
	//printf("\n");
    for(int i = 1; i <= q; ++i){
        int tmp = r * (a[0] - a[1]) + c * (a[2] - a[3]) + s * (a[4] - a[5]);
        //printf("%d\n",tmp);
        if(ans[i] == -2) ans[i]=tmp;
        else if (ans[i]!=tmp) ans[i] = -1;
        work2(i);
    }
}
int main()
{
	//freopen("1.in","r",stdin);
    while(1)
    {
        scanf("%d%d\n",&p,&q);
        if(p == 0 && q == 0) break;
        for(int i = 1; i <= p; ++i)
            gets(str1[i]);
        for (int i=1; i<=q; ++i) gets(str2[i]);
        //for(int i = 1; i <= p; ++i)
        //	puts(str1[i]);
        for(int i = 1; i <= q; ++i) ans[i] = -2;
        for(int r = 1; r <= 20; ++r)
            for(int c = 1; c <= 20; ++c)
                for(int s = 1; s <= 20; ++s){
                    if(check(r,c,s)){
                    	//printf("%d %d %d\n",r,c,s);
                        calc(r,c,s);
                       }
                }
        for(int i = 1; i< q; ++i) printf("%d ",ans[i]);
        printf("%d\n",ans[q]);
    }
    return 0;
}
