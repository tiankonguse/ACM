
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char s[1000][10];
char s1[10000],s2[10000];
int n,m,k;

int dfs(int n1,int m1){
   // printf("%d %d\n",n1,m1);
    if (n1>n && m1>m) return 1;
    if (n1>n || m1>m) return 0;
    if (n-n1+1>m-m1+1) return 0;
    if ((n-n1+1)*3<m-m1+1) return 0;
    int bo=0;
    for (int i=1; i<=k; ++i)
        if (m1+i-1<=m){
            int mark=0;
            int z1=strlen(s[s1[n1]]);
            if (z1>0 && z1!=i) continue;
            if (m1+z1-1>m) continue;
            for (int j=0; j<z1; ++j)
                if (s[s1[n1]][j]!=s2[m1+j]) ++mark;
            if (mark) continue;
            for (int j=0; j<i; ++j) s[s1[n1]][j]=s2[m1+j];
            s[s1[n1]][i]='\0';
            bo|=dfs(n1+1,m1+i);
            if (z1!=i) s[s1[n1]][0]='\0';
        }
    return bo;
}

int main(){
    int T;
    scanf("%d",&T);
    for (;T;--T){
        scanf("%d",&k);
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        //for (int i=1; i<=15; ++i) s1[i]='a'+i-1;
        //for (int i=1; i<=30; ++i) s2[i]='a'+i-1;
        //s1[16]=s2[31]='\0';
        n=strlen(s1+1),m=strlen(s2+1);
        for (int i=1; i<300; ++i) s[i][0]='\0';
        if (dfs(1,1)) printf("1\n");
        else printf("0\n");
    }
}
