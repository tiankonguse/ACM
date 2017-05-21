#include"iostream"
#define WORD_SIZE 27
#define MAXN 100001
using namespace std;
int word[WORD_SIZE][2];
int parents[WORD_SIZE];
bool used[WORD_SIZE];
int Find(int x){
    int a=x,tmp;
    while(parents[x]>=0){
       x=parents[x];}
    while(parents[a]>=0 && parents[a]!=x){tmp=parents[a];parents[a]=x;a=tmp;}
    return x;
}
int Union(int a,int b){
     if(parents[a]<parents[b]){
        parents[a]+=parents[b];
        parents[b]=a;
        return -parents[a];
     }
     else{
        parents[b]+=parents[a];
        parents[a]=b;
        return -parents[b];
     }
}
int main(){
   // freopen("1386.in","r",stdin);
   // freopen("1386out.txt","w",stdout);
    int T,N,root1,root2,t1,t2,max,res,re;
    char str[1024];
  //  int c=0;
    scanf("%d",&T);
    while(T--){
       memset(parents,0xff,sizeof(parents));
       memset(word,0,sizeof(word));
       memset(used,false,sizeof(used));
       res=1;
       re=0;
       scanf("%d",&N);
       for(int i=0;i<N;i++){
           scanf("%s",str);
           t1=str[0]-'a';
           t2=str[strlen(str)-1]-'a';
           word[t1][0]++;
           word[t2][1]++;
           if(!used[t1]){re++;used[t1]=true;}
           if(!used[t2]){re++;used[t2]=true;}
           root1=Find(t1);
           root2=Find(t2);
           if(root1!=root2)res=Union(root1,root2);
       }
       if(res!=re) printf("The door cannot be opened.\n");
       else{
       int r1=0,r2=0;
       for(int i=0;i<WORD_SIZE;i++){
           if(word[i][0]-word[i][1]==1)r1++;
           else if(word[i][0]-word[i][1]==-1)r2++;
           else if(word[i][0]!=word[i][1]){r1=-1;break;}
       }
       if( (r1==0 && r2==0) || (r1==1 && r2==1)){
           printf("Ordering is possible.\n");
       }
       else printf("The door cannot be opened.\n");
       }
    }
  //  system("pause");
    return 0;
}
