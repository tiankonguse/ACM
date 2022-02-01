#include"iostream"
#define MAXN 26
using namespace std;
int N;
int block[MAXN][MAXN];
int pos[MAXN][2];
char str1[5],str2[5];
void init(){
    for(int i=0;i<N;i++){
        block[i][0]=1;
        block[i][1]=i;
        pos[i][0]=i;
        pos[i][1]=1;
    }
}
void initial(int a){
    int b;
    int i=pos[a][0];
    int j=pos[a][1];
    for(int k=j+1;k<=block[i][0];k++){
        b=block[i][k];
        block[b][0]++;
        block[b][1]=b;
        pos[b][0]=b;
        pos[b][1]=1;
    }
    block[i][0]=j;
}
void move(int a,int num,int b){
    int bl;
    int i_a=pos[a][0];
    int j_a=pos[a][1];
    int i_b=pos[b][0];
    int j_b=pos[b][1];
    for(int k=j_a;k<j_a+num;k++){
        bl=block[i_a][k];
        block[i_b][++j_b]=bl;
        pos[bl][0]=i_b;
        pos[bl][1]=j_b;
    }
    block[i_a][0]-=num;
    block[i_b][0]+=num;
}
void print(){
    for(int i=0;i<N;i++){
        printf("%d:",i);
        for(int j=1;j<=block[i][0];j++){
            printf(" %d",block[i][j]);
        }
        printf("\n");
    }
   // system("pause");
}
int main(){
    int a,b;
    while(~scanf("%d",&N)){
        init();
        while(scanf(" %s",str1)){
            if(strcmp(str1,"quit")==0)break;
            scanf("%d %s %d",&a,str2,&b);
            if(pos[a][0]==pos[b][0])continue;
            if(str1[0]=='m'){
                initial(a);
                if(str2[1]=='n'){
                    initial(b);
                    move(a,1,b);
                }
                else{
                    move(a,1,block[pos[b][0]][block[pos[b][0]][0]]);
                  //  printf("pos[%d][0]=%d\n",b,pos[b][0]);
                 //   printf("block[%d][0]=%d\n",pos[b][0],block[pos[b][0]][0]);
                  //  printf("move(%d,1,%d)\n",a,block[pos[b][0]][block[b][0]]);
                }
            }
            else{
                if(str2[1]=='n'){
                    initial(b);
                    move(a,block[pos[a][0]][0]-pos[a][1]+1,b);
                }
                else{
                    move(a,block[pos[a][0]][0]-pos[a][1]+1,block[pos[b][0]][block[pos[b][0]][0]]);
                }
            }
         /*   print();
            for(int i=0;i<N;i++){
                printf("pos[%d]=(%d,%d)\n",i,pos[i][0],pos[i][1]);
            }*/
        }
        
        for(int i=0;i<N;i++){
            printf("%d:",i);
            for(int j=1;j<=block[i][0];j++){
                printf(" %d",block[i][j]);
            }
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}
