#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct in{
    char name[100],clas[100];
    int ty;
    void input(){
        scanf("%s%s%d",name,clas,&ty);
    }
}p[105];
int main(){
    int n;
//    freopen("C#.in","r",stdin);
//    freopen("C#.out","w",stdout);
    int cas=0;
    while(scanf("%d",&n)!=EOF){
        if(cas) puts("");
        cas++;
        for(int i=0;i<n;i++){
            p[i].input();
            for(int j=0;p[i].name[j];j++) if(p[i].name[j]<='Z'&&p[i].name[j]>='A') p[i].name[j]+=32;
        }
        for(int i=0;i<n;i++){
            printf("private %s ",p[i].clas);
            if(p[i].name[0]<='Z'&&p[i].name[0]>='A') p[i].name[0]+=32;
            printf("%s;\n",p[i].name);
        }
        puts("");
        for(int i=0;i<n;i++){
            printf("public %s ",p[i].clas);
            p[i].name[0]-=32;printf("%s{",p[i].name);p[i].name[0]+=32;
            if(p[i].ty==0){
                puts("}");
            }else if(p[i].ty==1){
                printf("get{return this.%s;}}\n",p[i].name);
            }else if(p[i].ty==2){
                printf("set{this.%s==value;}}\n",p[i].name);
            }else{
                printf("set{this.%s==value;} get{return this.%s;}}\n",p[i].name,p[i].name);
            }
        }
    }
}
