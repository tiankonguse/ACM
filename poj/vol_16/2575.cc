#include"iostream"
#include"set"
using namespace std;
int ab(int x){
    return x>0?x:-x;
}
set<int>st;
int main(){
    int N,a,b,c;
    while(~scanf("%d",&N)){
        st.clear();
        for(int i=0;i<N;i++){
            scanf("%d",&a);
            if(i>0){
               c=ab(a-b);
               if(c>=1 && c<=N-1)st.insert(c);
            }
            b=a;
        }
        if(st.size()==N-1)printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
