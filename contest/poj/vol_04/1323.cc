#include"iostream"
#include"algorithm"
using namespace std;
int cards[51];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int m,n,s,p,cnt,c=1;
    while(scanf("%d%d",&m,&n)&&m){
        s=m*n;
        for(int i=0;i<n;i++)scanf("%d",&cards[i]);
        sort(cards,cards+n,cmp);
        p=s-cards[0];
        cnt=0;  
        for(int i=0;i<n;i++){
            if(i)p+=cards[i-1]-cards[i]-1;
            if(p==0)cnt++;
            else p--;
        }
        printf("Case %d: %d\n",c++,cnt);
    }
    return 0;
}

