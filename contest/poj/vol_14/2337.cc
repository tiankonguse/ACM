#include"iostream"
#include"cmath"
#include"cstdlib"
using namespace std;
int N,degree_in[26],degree_out[26],edge_order[1001];
bool used[1001];
struct edge{
       int start,end;
       char word[21];
}edges[1001];
int cmp(const void *a,const void *b){
     return strcmp((*(edge *)a).word,(*(edge *)b).word);
}
int check(){
   int cnt1=0,cnt2=0,source;
   for(int i=0;i<26;i++){
      if(abs(degree_in[i]-degree_out[i])>=2)
         return -1;
      else if(degree_in[i]-degree_out[i]==1)
         cnt1++;
      else if(degree_in[i]-degree_out[i]==-1){
         cnt2++;
         source=i;
      }
   }
   if(cnt1>1 || cnt2>1)return -1;
   else if(cnt1==0){
       for(int i=0;i<26;i++)
         if(degree_out[i])return i;
   }
   else return source;
}
bool dfs(int source,int cnt){
   if(cnt==N)return true;
   for(int i=0;i<N;i++){
      if(edges[i].start<source ||used[i])continue;
      else if(edges[i].start>source)return false;
      used[i]=true;
      edge_order[cnt]=i;
      if(dfs(edges[i].end,cnt+1))return true;
      used[i]=false;
   }
   return false;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
       scanf("%d",&N);
       memset(degree_in,0,sizeof(degree_in));
       memset(degree_out,0,sizeof(degree_out));
       for(int j=0;j<N;j++){
          scanf("%s",edges[j].word);
          edges[j].start=edges[j].word[0]-'a';
          edges[j].end=edges[j].word[strlen(edges[j].word)-1]-'a';
          degree_in[edges[j].end]++;
          degree_out[edges[j].start]++;
       }
       int source=check();
       if(source==-1){printf("***\n");continue;}
       qsort(edges,N,sizeof(edges[0]),cmp);
       memset(used,0,sizeof(used));
       if(!dfs(source,0)){
                          printf("***\n");
                          continue;
       }
       printf("%s",edges[edge_order[0]].word);
       for(int j=1;j<N;j++)printf(".%s",edges[edge_order[j]].word);
       printf("\n");
    }
}
