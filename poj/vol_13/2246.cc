#include"iostream"
#include"cstdlib"
#include"cstdio"
#include"string"
#define MAXN 27
#define MAXS 1005
using namespace std;
struct node{
    int x,y;
}nod[MAXN],tmp[MAXN];
char st[MAXS];
char str[MAXS];
int main(){
    int N,d,e,x,y;
    char ch,ci;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf(" %c %d %d",&ch,&x,&y);
        d=ch-'A';
        tmp[d].x=x;
        tmp[d].y=y;
    }
    int h=1,len,res=0;
    bool flag=true;
    st[0]='#';
    while(~scanf("%s",str)){
        memcpy(nod,tmp,sizeof(tmp));
        h=1,res=0,flag=true;
        st[0]='#';
        len=strlen(str);
        for(int i=0;i<len;i++){
            ci=str[i];
            ch=st[h-1];
            if(ci>='A' && ci<='Z' && ch>='A' && ch<='Z'){
                d=ch-'A';
                e=ci-'A';
                if(nod[d].y!=nod[e].x){
                    flag=false;
                    break;
                }
                res+=nod[d].x*nod[d].y*nod[e].y;
                nod[d].y=nod[e].y;
            }
            else if(ci==')'){
                str[i]=st[h-1];
                h-=2;
                i--;
            }
            else{
                st[h++]=ci;
            }
        }
        if(!flag)printf("error\n");
        else{
            printf("%d\n",res);
        }
    }
    return 0;
}
