#include <iostream>

using namespace std;

int tri[21][21];
int main()
{
    int N,S,t;
    cin>>N>>S;
    t=S;
    for(int j=1;j<=N;j++){
        for(int i=1;i<=j;i++){
           tri[i][j]=t++;
           if(t==10)t=1;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            printf("  ");
        }
        for(int j=i;j<=N;j++){
            if(j==N)printf("%d\n",tri[i][j]);
            else printf("%d ",tri[i][j]);
        }
    }
    return 0;
}
