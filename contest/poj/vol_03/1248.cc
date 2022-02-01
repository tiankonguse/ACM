#include"iostream"
#include"string"
#include"cstdlib"
using namespace std;
int cmp(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int check(int p[],int s){
    if(p[0]-p[1]*p[1]+p[2]*p[2]*p[2]-p[3]*p[3]*p[3]*p[3]
    +p[4]*p[4]*p[4]*p[4]*p[4]==s)return 1;
    else return 0;
}
int search(int c[],int p[],int d,int s,int l){
    for(int i=0;i<l;i++){
        int ff=0;
        for(int j=0;j<d;j++){
                if(p[j]==c[i])ff=1;
        }
        if(ff)continue;
        p[d]=c[i];
        if(d==4){
                 if(check(p,s))return 1;
        }
        else if(search(c,p,d+1,s,l))return 1;
    }
    return 0;
}
int main(){
    int N,c[30],p[5];
    string s;
    while(cin>>N>>s){
       if(N==0 && s=="END")break;
       int l=s.length();
       for(int i=0;i<l;i++){
               c[i]=s[i]-64;
       }
       qsort(c,l,sizeof(c[0]),cmp);
       if(search(c,p,0,N,l)){
            for(int i=0;i<5;i++){
                    printf("%c",p[i]+64);
            }
            printf("\n");
       }
       else printf("no solution\n");
    }
    return 0;
}
