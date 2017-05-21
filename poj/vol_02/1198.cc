#include"iostream"
#include"cstdlib"
#include"queue"
#include"set"
using namespace std;
int num[8];
int change(int s,int n,int d){
    int x,y;
    bool flag;
    for(int i=7;i>=0;i--){
       num[i]=s%10;
       s/=10;
    }
    x=num[n*2];
    y=num[n*2+1];
    flag=false;
    if(d==0){ //up
       if(x==0)return -1;
       for(int i=0;i<8;i+=2){
          if(num[i]==x-1 && num[i+1]==y){
              if(x==1)return -1;
              for(int j=0;j<8;j+=2){
                 if(num[j]==x-2 && num[j+1]==y)return -1;
              }
              num[n*2]=x-2;
              flag=true;
              break;
          }
       }
       if(!flag)num[n*2]=x-1;
    }
    else if(d==1){ //down
       if(x==7)return -1;
       for(int i=0;i<8;i+=2){
          if(num[i]==x+1 && num[i+1]==y){
              if(x==6)return -1;
              for(int j=0;j<8;j+=2){
                 if(num[j]==x+2 && num[j+1]==y)return -1;
              }
              num[n*2]=x+2;
              flag=true;
              break;
          }
       }
       if(!flag)num[n*2]=x+1;
    }
    else if(d==2){ //left
       if(y==0)return -1;
       for(int i=1;i<8;i+=2){
          if(num[i]==y-1 && num[i-1]==x){
              if(y==1)return -1;
              for(int j=1;j<8;j+=2){
                 if(num[j]==y-2 && num[j-1]==x)return -1;
              }
              num[n*2+1]=y-2;
              flag=true;
              break;
          }
       }
       if(!flag)num[n*2+1]=y-1;
    }
    else{  //right
       if(y==7)return -1;
       for(int i=1;i<8;i+=2){
          if(num[i]==y+1 && num[i-1]==x){
              if(y==6)return -1;
              for(int j=1;j<8;j+=2){
                 if(num[j]==y+2 && num[j-1]==x)return -1;
              }
              num[n*2+1]=y+2;
              flag=true;
              break;
          }
       }
       if(!flag)num[n*2+1]=y+1;
    }
    for(int i=0;i<8;i++){
        s=s*10+num[i];
    }
    return s;
}
int sor(int s){
   for(int i=7;i>=0;i--){
       num[i]=s%10;
       s/=10;
   }
   int max,t,tmpx,tmpy;
   for(int i=0;i<8;i+=2){
       max=num[i];
       t=i;
       for(int j=i+2;j<8;j+=2){
          if(num[j]>max){max=num[j];t=j;}
          else if(num[j]==max){
              if(num[j+1]>num[t+1]){
                 max=num[j];t=j;
              }
          }
       }
       tmpx=num[i];tmpy=num[i+1];
       num[i]=num[t];num[i+1]=num[t+1];
       num[t]=tmpx;num[t+1]=tmpy;
   } 
   for(int i=0;i<8;i++){
        s=s*10+num[i];
    }
    return s;
}
struct node{
   int n,t;
   node(int i,int j):n(i),t(j){}
};
queue<node>q1,q2;
set<int>mark1,mark2;
void bfs(int st,int des){
   node t(0,0);
   int ts,step=0;
   while(!q1.empty())q1.pop();
   while(!q2.empty())q2.pop();
   mark1.clear();
   mark2.clear();
   q1.push(node(st,0));
   q2.push(node(des,0));
   mark1.insert(st);
   mark2.insert(des);
   while(!q1.empty() && !q2.empty()){
       if(step==4){break;}
       //cout<<q1.front().t<<","<<q2.front().t<<endl;
       while(q1.front().t==step){
           t=q1.front();
           q1.pop();
           for(int i=0;i<4;i++){
               for(int j=0;j<4;j++){
                   ts=change(t.n,i,j);
                   if(ts==-1)continue;
                   ts=sor(ts);
                   if(mark2.find(ts)!=mark2.end()){
                       printf("YES\n");
                       return;
                   }
                   if(mark1.find(ts)==mark1.end()){
                       mark1.insert(ts);
                       q1.push(node(ts,t.t+1));
                   }   
               }
           }
       }
       while(q2.front().t==step){
           t=q2.front();
           q2.pop();
           
           for(int i=0;i<4;i++){
               for(int j=0;j<4;j++){
                   ts=change(t.n,i,j);
                   if(ts==-1)continue;
                   ts=sor(ts);
                   if(mark1.find(ts)!=mark1.end()){
                       printf("YES\n");
                       return;
                   }
                   if(mark2.find(ts)==mark2.end()){
                       mark2.insert(ts);
                       q2.push(node(ts,t.t+1));
                   }   
               }
           }
       }
       step++;
   }
   printf("NO\n");
}
int main(){
    int st,des,a;
    while(~scanf("%d",&a)){
       st=a-1;
       for(int i=1;i<8;i++){
           scanf("%d",&a);
           st=st*10+a-1;
       }
       des=0;
       for(int i=0;i<8;i++){
           scanf("%d",&a);
           des=des*10+a-1;  
       }
       bfs(sor(st),sor(des));
    }
    return 0;
}
