#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(){
    freopen("Average_Score.in","w",stdout);
    int t=50;
    srand(time(NULL));
    while(t--){
        int n=rand()%100+1;
        printf("%d\n",n);
        for(int i=0;i<n;i++){
            int ty=rand()%2+1;
            if(ty==1){
                int c=rand()%100+1;int s=rand()%100+1;
                printf("%d %d %d\n",ty,c,s);
            }else{
                int c=rand()%100+1;int s=rand()%5;
                printf("%d %d %c\n",ty,c,s+'A');
            }
        }
        n=t+50;
        printf("%d\n",n);
        for(int i=0;i<n;i++){
            int ty=rand()%2+1;
            if(ty==1){
                int c=rand()%100+1;int s=rand()%100+1;
                printf("%d %d %d\n",ty,c,s);
            }else{
                int c=rand()%100+1;int s=rand()%5;
                printf("%d %d %c\n",ty,c,s+'A');
            }
        }
    }
}
