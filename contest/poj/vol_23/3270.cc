#include"iostream"
#include"algorithm"
#define MAXN 10001
#define range 100001
using namespace std;
int nums[MAXN],cd[MAXN],pos[range];
bool used[MAXN];
int mi(int a,int b){
    return a<b?a:b;
}
int main(){
    int N,sum,min,len,p,d,ans=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&nums[i]);
    }
    memcpy(cd,nums,sizeof(nums));
    sort(cd,cd+N);
    for(int i=0;i<N;i++)pos[cd[i]]=i;
    for(int i=0;i<N;i++){
       if(!used[i]){
           used[i]=true;
           len=1;
           sum=nums[i];
           min=nums[i];
           p=pos[nums[i]];
           while(p!=i){
              used[p]=true;
              len++;
              d=nums[p];
              sum+=d;
              if(d<min)min=d;
              p=pos[d];
           }
           ans+=mi(sum+(len-2)*min,sum+cd[0]*(len+1)+min);
       }
    }
    printf("%d\n",ans);
  //  system("pause");
    return 0;
}
