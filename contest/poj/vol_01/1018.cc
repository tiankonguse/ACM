#include"iostream"
#include"set"
#include"algorithm"
using namespace std;
struct manu{
    int b,p;
}man[101][101];
int cmp(manu a,manu b){
   return a.p<b.p;
}
int cnt[101];
set<int>st;
int main(){
    int T,N;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&N);
       for(int i=0;i<N;i++){
           scanf("%d",&cnt[i]);
           for(int j=0;j<cnt[i];j++){
                 scanf("%d%d",&man[i][j].b,&man[i][j].p);
                 st.insert(man[i][j].b);
           }
           sort(man[i],man[i]+cnt[i],cmp);
       }
       double max=0,mp;
       int sum=0;
       bool flag;
       for(set<int>::iterator it=st.begin();it!=st.end();it++){
           sum=0;
           for(int i=0;i<N;i++){
                flag=false;
                for(int j=0;j<cnt[i];j++){
                    if(man[i][j].b>=*it){
                                       //  cout<<*it<<":"<<man[i][j].p<<endl;
                        sum+=man[i][j].p;
                        flag=true;
                        break;
                    }   
                }
                if(!flag)break;
           }
           if(!flag)continue;
         //  cout<<*it<<","<<sum<<endl;
           mp=(double)*it/(double)sum;
           if(mp>max)max=mp;
       }
       printf("%.3lf\n",max);
    }
 //   system("pause");
    return 0;
}
