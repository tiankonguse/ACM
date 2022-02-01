#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 205
using namespace std;
int num[MAXN];
bool used[MAXN];
char str[MAXN];
int res[MAXN];
char out[MAXN];
int main(){
    int N,K;
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++){
            scanf("%d",&num[i]);
            num[i]--;
        }
        while(scanf(" %d",&K) && K){
            getchar();
            gets(str);
            memset(used,false,sizeof(used));
            for(int i=strlen(str);i<N;i++)str[i]=' ';
            str[N]='\0';
            int p,s,t,d;
            for(int i=0;i<N;i++){
                if(!used[i]){
                    p=num[i];s=0;used[i]=true;
                    res[s++]=i;
                    while(p!=i){
                        used[p]=true;
                        res[s++]=p;
                        p=num[p];
                    }
                   // for(int j=0;j<s;j++)cout<<res[j];cout<<endl;
                    d=K%s;
                    p=num[i];out[i]=str[res[(s-d)%s]];
                    t=0;

                 //   printf("out[%d]=%c\n",i,str[res[d]]);
                    while(p!=i){
                        t++;
                        out[p]=str[res[(t-d+s)%s]];
                       // printf("out[%d]=%c\n",p,str[res[(t+d)%s]]);
                        p=num[p];
                    }
                }
            }

            for(int i=0;i<N;i++)printf("%c",out[i]);printf("\n");
        }
        printf("\n");
    }
    return 0;
}
