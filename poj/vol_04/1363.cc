#include"iostream"
#include"stack"
using namespace std;
stack<int> st;
int main(){
    int N,c=0;
    int a[1001];
    while(scanf("%d",&N)&&N){
        if(c==1)printf("\n");
        c=1;
        while(scanf("%d",&a[0])){
           if(a[0]==0)break;
           for(int i=1;i<N;i++){
              scanf("%d",&a[i]);
           }
           while(!st.empty())st.pop();
           int k=0,num=1;
           while(num<=N){
            st.push(num++);
            while(!st.empty() && st.top()==a[k]){
              st.pop();
              k++;
              if(k>=N)break;
            }
            if(k>=N)break;
           }
           if(k==N)printf("Yes\n");
           else printf("No\n");
        }
    }
    return 0;
}
