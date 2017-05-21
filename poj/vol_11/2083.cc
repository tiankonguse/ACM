#include"iostream"
#include"cstdio"
using namespace std;
bool map[731][731];
int data[7]={1,3,9,27,81,243,729};
void print(int n,int x,int y){
     if(n==1){
        map[x][y]=true;
        return ;
     }
     int emp=data[n-2];
     print(n-1,x,y);
     print(n-1,x,y+emp*2);
     print(n-1,x+emp,y+emp);
     print(n-1,x+emp*2,y);
     print(n-1,x+emp*2,y+emp*2);
}
int main(){
    int n;
    print(7,0,0);
    while(scanf("%d",&n)){
      if(n==-1)break;
      for(int i=0;i<data[n-1];i++){
         for(int j=0;j<data[n-1];j++){
            if(map[i][j])
            printf("X");
            else printf(" ");
         }
         printf("\n");
      }
      printf("-\n");
    }
    return 0;
}

