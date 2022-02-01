#include"iostream"
#include"queue"
using namespace std;
priority_queue<int>q1;
priority_queue<int, vector<int>, greater<int> > q2;
int res[10001];
int main(){
    int T,p,N,a,mid,cl,ch;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        scanf("%d%d",&p,&N);
        scanf("%d",&mid);
        res[0]=mid;
        cl=ch=0;
        for(int j=1;j<N;j++){
            scanf("%d",&a);
            if(j&1){
               if(a>mid){q2.push(a);ch++;} 
               else{q1.push(a);cl++;}
            }
            else{
               if(ch>cl){
                   if(a>mid){
                       q1.push(mid);
                       cl++;
                       q2.push(a);
                       mid=q2.top();
                       q2.pop();
                       res[j]=mid;
                   }
                   else{
                       q1.push(a);
                       cl++;
                       res[j]=mid;
                   }
               }
               else{
                   if(a<mid){
                       q2.push(mid);
                       ch++;
                       q1.push(a);
                       mid=q1.top();
                       q1.pop();
                       res[j]=mid;
                   }
                   else{
                       q2.push(a);
                       ch++;
                       res[j]=mid;
                   }
               }
            }
        }
        printf("%d %d\n",p,N/2+1);
        for(int j=0;j<N;j+=2){
             if(j%20==0)printf("%d",res[j]);
             else printf(" %d",res[j]);
             if(j%20==18)printf("\n");
        }
        if((N-1)%20!=18)printf("\n");
    }
   // system("pause");
    return 0;
}
